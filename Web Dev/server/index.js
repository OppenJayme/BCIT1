const express = require('express')
const app = express();

app.set("view engine", "ejs");
app.use(express.json());
app.use(express.urlencoded({ extended: false }));


const users = {};

app.get("/login", (req, res) => {
    res.render("login");
});

app.post("/login", (req, res) => {
    const { username, password } = req.body;
    
    if (username && password === password) {
    const user = users[username];    
        res.render("dashboard", { user: user });
    } else {
        res.redirect("/login");
    }
});

app.get("/register", (req, res) => {
    res.render("register");
});

app.post("/register", (req, res) => {
    const { username, password, full_name, email, contact } = req.body;
    
    users[username] = { username, password, full_name, email, contact };
    res.redirect("/login");
});

app.listen(2300, () => console.log("server is running..."));