public class Video extends MediaItem{
    private String director;

    Video(String title, String category, double price, String director) {
        super(title, category, price);
        this.director = director;
    }
}
