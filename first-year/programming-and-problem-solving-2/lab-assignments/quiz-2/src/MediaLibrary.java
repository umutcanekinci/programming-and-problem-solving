import java.util.ArrayList;
import java.util.List;

public class MediaLibrary {
    private List<Media> mediaList;

    public MediaLibrary() {
        mediaList = new ArrayList<>();
    }

    public void displayLibrary() {
        System.out.println("LIBRARY MEDIAS:");
        mediaList.forEach(Media::display);
    }

    public double calculateTotalPrice() {
        double total = 0;
        for (Media media : mediaList) {
            total += media.getPrice();
        }
        return total;
    }

    public void addMedia(Media media) {
        if(media == null)
            throw new IllegalArgumentException("media cannot be null!");

        if(mediaList.contains(media))
            return;

        mediaList.add(media);
    }

    public List<Media> findMediaByCategory(String category) {
        List<Media> result = new ArrayList<>();
        for (Media media : mediaList) {
            if(!media.getCategory().equals(category))
                continue;

            result.add(media);
        }
        return result;
    }

    public void removeMediaByCategory(String category) {
        System.out.println("Deleting medias with category " + category);
        for (int i=0; i < mediaList.size(); i++) {
            Media media = mediaList.get(i);

            if(media == null)
                continue;

            if(!media.getCategory().equals(category))
                continue;
            
            mediaList.remove(i);
            i--;
        }
    }


}
