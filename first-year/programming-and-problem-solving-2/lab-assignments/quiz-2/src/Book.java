public class Book extends MediaItem{
    private String author;

    public Book(String title, String category, double price, String author) {
        super(title, category, price);
        this.author = author;
    }
}
