// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";
import { getAuth } from "firebase/auth";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyB9kgQyIsZ74VBpd-s5qOiWE3BakKHRL98",
  authDomain: "book-project-8747d.firebaseapp.com",
  projectId: "book-project-8747d",
  storageBucket: "book-project-8747d.appspot.com",
  messagingSenderId: "67603474889",
  appId: "1:67603474889:web:54379e74578a06151ee018"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);
const db = getFirestore(app);

export { db, auth };