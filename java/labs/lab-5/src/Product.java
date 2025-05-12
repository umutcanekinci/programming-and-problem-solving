public abstract class Product {
    private final int id;
    private final String name;
    private final double price;
    private final String description;

    public Product(int id, String name, double price, String description) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.description = description;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public String getDescription() {
        return description;
    }

    public abstract double getTax();

    @Override
    public String toString() {
        return "[" + id + "] " + name + ": " + price + "$" + "\n" +
        "(" + description + ")" + "\n";
    }
}
