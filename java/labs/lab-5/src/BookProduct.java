public class BookProduct extends Product{
    private static double TAX_RATE = 8 / 100;
    private final String author, genre;
    private int pageCount;

    public BookProduct(int id, String name, double price, String description, String author, String genre, int pageCount) {
        super(id, name, price, description);
        this.author = author;
        this.genre = genre;
        this.pageCount = pageCount;
    }

    public String getAuthor() {
        return author;
    }

    public String getGenre() {
        return getGenre();
    }

    public int getPageCount() {
        return pageCount;
    }

    @Override
    public double getTax() {
        return getPrice() * TAX_RATE;
    }

    @Override
    public String toString() {
        return "[" + getId() + "] " + author + " - " + getName() + ": " + getPrice() + "$" + "\n" +
        "(" + getDescription() + ")" +
        "\n" + "Genre: " + genre + "\n" + pageCount + " Pages" + "\n\n"; 
    }


}
