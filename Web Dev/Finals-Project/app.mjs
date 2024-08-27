import express from 'express';
import session from 'express-session';
import {
    saveUser,
    getBooks,
    saveBook,
    deleteBook,
    updateBook,
    getBookById,
}  from "./services/book.mjs";
import { db, auth} from "./config/database.mjs";
import { createUserWithEmailAndPassword, signInWithEmailAndPassword } from "firebase/auth";
import { deleteUser } from "firebase/auth";
import flash from 'express-flash';
import { signOut } from "firebase/auth";
//----------------------------IMPORTS----------------------------

//----------------------------FUNCTIONS AND OTHERS START----------------------------
const app = express();

app.set("view engine", "ejs");
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(express.static("public"));
app.use(flash());

app.use(session ({
  secret: 'Gw@p0siIv@n',
  resave: false,
  saveUninitialized: true,
}));

function checkAuth(req, res, next) {
  if (req.session.user && req.session.user.isAuthenticated) {
    return next();
  } else {
    res.redirect('/loginpage');
  }
}

//----------------------------FUNCTIONS AND OTHERS END----------------------------

//------------------LOGIN START------------------
app.get('/loginpage', (req, res) => {
  res.render('loginpage', { messages: req.flash() });
});
app.post('/loginpage', async (req, res) => {
  const { email, password } = req.body;

  try {
    const userCredential = await signInWithEmailAndPassword(auth, email, password);
    req.session.user = {
     isAuthenticated: true,
     id: userCredential.user.uid, 
    };
    console.log("User ID: ", req.session.user.id); 
    if (req.session.user.isAuthenticated) {
      req.flash('success', 'Successfully Logged in!');
      res.redirect('/lilbrary');
    }
  } catch (error) {
    console.error("Error logging in user: ", error);
    req.flash('error', 'Login failed');
    res.redirect('/loginpage');
  }
});

//------------------login END------------------

//------------------register------------------
app.get('/register', (req,res) => {
  res.render('register', { messages: req.flash() });
});
app.post('/register', async (req, res) => {
  const { firstName, lastName, email, password } = req.body;
  let userCredential;

  try {
    userCredential = await createUserWithEmailAndPassword(auth, email, password);
    const user = userCredential.user;
    await saveUser(firstName, lastName, email, password);
    req.flash('success', 'Successfully registered!');
    res.redirect('/loginpage');
  } catch (error) {
    console.error("Error registering user: ", error);
    if (userCredential) {
      await deleteUser(userCredential.user);
    }
    req.flash('error', 'Registration failed');
    res.redirect('/register');
  }
});
//------------------register END ------------------


//------------------LIL BRARY START ------------------
app.get('/lilbrary', checkAuth, async (req, res) => {
  try {
    const books = await getBooks(req.session.user.id);
    res.render('lilbrary', { books: books, messages: req.flash() });
  } catch (error) {
    console.error("Error getting books: ", error);
    res.render('lilbrary', { books: [], messages: req.flash() });
  }
});

app.get('/landing', (req, res) => {
  res.render('landing');
});
//------------------LIL BRARY END ------------------


//----------------------------ADD BOOK START----------------------------
app.get('/addbooks', checkAuth, (req, res) => {
  res.render('addbooks');
});
app.post('/addbooks',  checkAuth, async (req, res) => {
  const { title, author, description, publisher, 'publish-year': year, 'publish-month': month, 'publish-day': day, pages } = req.body;
  const newBook = await saveBook(req.session.user.id, title, author, description, publisher, year, month, day, pages);
  
  const books = await getBooks(req.session.user.id);
  
  res.render('addbooks', { books: books, messages: req.flash() });
});
//----------------------------ADD BOOK END----------------------------

//----------------------------delete bookv START----------------------------
app.delete('/books/:id', async (req, res) => {
  const id = req.params.id;
  console.log(`Deleting book with ID: ${id}`);
  await deleteBook(id);
  res.status(200).send();
});
//----------------------------delete book end----------------------------


//----------------------------UPDATE BOOK START----------------------------
app.get('/editbooks/:id', checkAuth, async (req, res) => {
  const id = req.params.id;
  const book = await getBookById(id); 
  if (book) {
    res.render('editbooks', { book: book });
  } else {
    res.status(404).send('Book not found');
  }
});
app.post('/editbooks/:id', checkAuth, async (req, res) => {
  const id = req.params.id;
  const { title, author, description, publisher, 'publish-year': year, 'publish-month': month, 'publish-day': day, pages } = req.body;
  await updateBook(id, title, author, description, publisher, year, month, day, pages); 
  res.redirect('/lilbrary');
});
//----------------------------UPDATE BOOK END----------------------------
//------------------LOG OUT START------------------
app.get('/logout', (req, res) => {
  signOut(auth)
    .then(() => {
      req.session = null; // Clear the session
      res.redirect('/loginpage');
    })
    .catch((error) => {
      console.error('Error during sign out:', error);
    });
});
//------------------LOG OUT END------------------
app.get('/', (req, res) => {
  res.redirect('/landing');
});
  app.listen(2312, () => console.log("Server is running..."));