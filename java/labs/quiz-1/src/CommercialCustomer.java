public class CommercialCustomer extends Customer {
    private double additionalRatePerUnit;

    public CommercialCustomer(int id, String name, double ratePerUnit, double additionalRatePerUnit) {
        super(id, name, ratePerUnit);
        this.additionalRatePerUnit = additionalRatePerUnit;
    }

    public double calculateBill(double usageUnits) {
        return usageUnits * (ratePerUnit + additionalRatePerUnit);
    }

    public String toString() {
        return super.toString() + " " + additionalRatePerUnit;
    }
}

