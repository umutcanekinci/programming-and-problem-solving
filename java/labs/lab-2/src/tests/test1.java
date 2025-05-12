package tests;

import app.*;
public class test1 {
    public static void main(String[] args) throws Exception {
        Book[] testBooks = {
            new Book("Book 1", "Author 1", 1),
            new Book("Book 2", "Author 2", 2),
            new Book("Book 3", "Author 3", 3)
        };
        
        Library library = new Library();

        for(Book book : testBooks) {
            library.addBook(book);
        }

        System.out.println("");
        System.out.println("");
        System.out.println(" ----------------------------------- LIBRARY SYSTEM -----------------------------------");
        System.out.println("");
        library.borrowBook(1);
        System.out.println("");
        library.listAvailableBooks();
        System.out.println("");
        library.borrowBook(1);
        System.out.println("");
        library.returnBook(1);
        library.listAvailableBooks();
        System.out.println("");
        library.removeBook(2);
        library.listAvailableBooks();
    }
}
