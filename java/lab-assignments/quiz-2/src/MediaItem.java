public class MediaItem implements Media{
    private String title;
    private String category;
    private double price;

    public MediaItem(String title, String category, double price) {
        this.title = title;
        this.category = category;
        this.price = price;
    }

    public double getPrice() {
        return price;
    }

    public void display() {
        System.out.println(title + " " + category + " " + price);
    }

    public String getCategory() {
        return category;
    }
}
