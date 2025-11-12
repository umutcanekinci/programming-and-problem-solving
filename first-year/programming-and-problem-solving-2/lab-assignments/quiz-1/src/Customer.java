public abstract class Customer {
    private int id;
    private String name;
    protected double ratePerUnit;

    public Customer(int id, String name, double ratePerUnit) {
        this.id = id;
        this.name = name;
        this.ratePerUnit = ratePerUnit;
    }

    public double getRatePerUnit() {
        return ratePerUnit;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return "[" + id +"] " + name + " " + ratePerUnit;
    }

    public abstract double calculateBill(double usageUnits);
}
