package app;

public class Book {
    private String title;
    private String author;
    private int isbn;
    private boolean isAvailable;

    public Book(String title, String author, int isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isAvailable = true;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public int getIsbn() {
        return isbn;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setTitle(String value) {
        title = value;
    }

    public void setAuthor(String value) {
        author = value;
    }

    public void setIsbn(int value) {
        isbn = value;
    }

    public void setAvailable(Boolean value) {
        isAvailable = value;        
    }

    public void borrowBook() {
        setAvailable(false);
    }

    public void returnBook() {
        setAvailable(true);
    }

    public String toString() {
        return title + " - " + author + " ["+ isbn +"]" + " (" + (isAvailable ? "Available" : "Not Available") + ")";
    }
}
