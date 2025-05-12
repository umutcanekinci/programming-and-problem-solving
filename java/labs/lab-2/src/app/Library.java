package app;

import java.util.ArrayList;

public class Library {
    private ArrayList<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public Book borrowBook(int isbn) {
        Book book = getBook(isbn);

        if(book == null) {
            System.out.println("The book with isbn " + isbn + " haven't found in library.");
            return null;
        }
            
        if(!book.isAvailable()) {
            System.out.println("The book with isbn " + isbn + " have borrowed before.");
            return book;
        }

        book.borrowBook();
        System.out.println("You have borrowed the " + book.getTitle() + " succesfully.<");
        return book;
        
    }

    public void returnBook(int isbn) {
        Book book = getBook(isbn);
        
        if(book == null)
            return;
            
        book.returnBook();
    }

    public Book getBook(int isbn) {
        for(Book book : books) {
            if(book.getIsbn() == isbn)
                return book;
        }
        return null;
    }

    public void listAvailableBooks() {
        System.out.println("AVAILABLE BOOKS:");
        books.forEach(book -> System.out.print(book.isAvailable() ? book  + "\n" : ""));
    }

    public void removeBook(int isbn) {
        Book book = getBook(isbn);

        if(book == null)
            return;

        books.remove(book);
    }
}
