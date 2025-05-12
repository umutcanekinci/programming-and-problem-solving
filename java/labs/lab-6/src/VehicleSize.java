public enum VehicleSize {
    SMALL(1, 1),
    MEDIUM(2, 2),
    LARGE(3, 3);

    private int space;
    private int payment;

    public int getSpace() {
        return space;
    }

    public double getPayment() {
        return payment;
    }

    VehicleSize(int space, int payment) {
        this.space = space;
        this.payment = payment;
    }
}
