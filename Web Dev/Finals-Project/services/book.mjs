import {
  addDoc,
  collection,
  deleteDoc,
  doc,
  getDocs,
  setDoc,
  getDoc,
  updateDoc,
  query,
  where,
} from "firebase/firestore";
import { db } from "../config/database.mjs";

//------------------REGISTER START------------------
export const saveUser = async (firstName, lastName, email, password) => {
    try {
      const docRef = await addDoc(collection(db, "users"), {
        firstName: firstName,
        lastName: lastName,
        email: email,
        password: password, 
      });
  
      console.log("User registered with ID: ", docRef.id);
    } catch (e) {
      console.error("Error registering user: ", e);
    }
  };
//------------------REGISTER END------------------

//------------------LOGIN START------------------
export const getUserByEmail = async (email) => {
    const userRef = collection(db, "users");
    const q = query(userRef, where("email", "==", email));
    const querySnapshot = await getDocs(q);
    let user = null;
    querySnapshot.forEach((doc) => {
      user = doc.data();
    });
    return user;
  };
//------------------LOGIN END------------------

//------------------SAVE BOOK ------------------
export const saveBook = async (userId, title, author, description, publisher, year, month, day, pages) => {
  try {
    const docRef = await addDoc(collection(db, "books"), {
      userId: userId, // Store user ID in book document
      title: title,
      author: author,
      description: description,
      publisher: publisher,
      datePublished: new Date(year, month - 1, day),
      pages: pages
    });

    console.log("Document written with ID: ", docRef.id);
  } catch (e) {
    console.error("Error adding document: ", e);
  }
};
//------------------SAVE BOOK END ------------------

//------------------ GET BOOKS START ------------------
export const getBooks = async (userId) => {
  const books = [];
  try {
    const querySnapshot = await getDocs(query(collection(db, "books"), where("userId", "==", userId)));
    querySnapshot.forEach((doc) => {
      books.push({ id: doc.id, ...doc.data() });
    });
  } catch (e) {
    console.error("Error getting documents: ", e);
  }
  return books;
};
export const getBookById = async (id) => {
  const bookRef = doc(db, "books", id);
  let book;
  try {
    const docSnap = await getDoc(bookRef);
    if (docSnap.exists()) {
      book = { id: docSnap.id, ...docSnap.data() };
    } else {
      console.log("No such document!");
    }
  } catch (e) {
    console.error("Error getting document: ", e);
  }
  return book;
};
//------------------GET BOOKS END ------------------


//----------------------------DELETE BOOK START----------------------------
export const deleteBook = async (id) => {
  await deleteDoc(doc(db, "books", id));
};
//----------------------------DELETE BOOK END----------------------------

//----------------------------UPDATE BOOK START----------------------------
export const updateBook = async (id, title, author, description, publisher, year, month, day, pages) => {
  const bookRef = doc(db, "books", id);
  try {
    await updateDoc(bookRef, {
      title: title,
      author: author,
      description: description,
      publisher: publisher,
      datePublished: new Date(year, month - 1, day),
      pages: pages
    });

    console.log("Document updated with ID: ", id);
  } catch (e) {
    console.error("Error updating document: ", e);
  }
};
//----------------------------UPDATE BOOK END----------------------------


