public class ResidentalCustomer extends Customer {
    private double baseCharge;

    public ResidentalCustomer(int id, String name, double ratePerUnit) {
        super(id, name, ratePerUnit);
    }

    public double calculateBill(double usageUnits) {
        return baseCharge + ratePerUnit * usageUnits;
    }

    public String toString() {
        return super.toString() + " " + baseCharge;
    }
}
