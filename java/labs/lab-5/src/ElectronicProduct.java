public class ElectronicProduct extends Product {
    private final static double TAX_RATE = 1/5;
    private final String manufacturer;
    private final String model;
    private final int warranty;


    public ElectronicProduct(int id, String name, double price, String description, String manufacturer, String model, int warranty) {
        super(id, name, price, description);
        this.manufacturer = manufacturer;
        this.model = model;
        this.warranty = warranty;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public String getModel() {
        return model;
    }

    public int getWarranty() {
        return warranty;
    }

    @Override
    public double getTax() {
        return getPrice() % TAX_RATE;
    }

    //Decoupling
    @Override 
    public String toString() {
        return super.toString() + model + " " + warranty + " Years Warranty" + "\n\n";
    }

}
