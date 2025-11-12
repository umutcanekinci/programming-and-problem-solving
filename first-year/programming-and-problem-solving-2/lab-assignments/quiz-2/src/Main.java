import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        Media[] test = new Media[] {
            new Book("null", "null", 100, "null"),
            new Book("null2", "null", 200, "null2"),
            new Video("null3", "null", 300, "null3"),
            new Video("null4", "null2", 300, "null4")
        };

        MediaLibrary library = new MediaLibrary();
        for(Media media : test)
            library.addMedia(media);

        library.displayLibrary();
        System.out.println("");
        library.removeMediaByCategory("null");
        System.out.println("");
        List<Media> listToDisplay = library.findMediaByCategory("null2");
        listToDisplay.forEach(Media::display);
        System.out.println("");
        library.displayLibrary();
        System.out.println("");

        System.out.println("Total price: " + library.calculateTotalPrice() + "\n");

    }
}
