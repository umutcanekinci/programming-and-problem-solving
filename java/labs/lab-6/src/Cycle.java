public class Cycle extends Vehicle {
    public Cycle(String licensePlate) {
        super(licensePlate);
        this.vehicleSize = VehicleSize.SMALL;
    }

    @Override
    public double calculateParkingFee(double duration) {
        return duration * vehicleSize.getPayment();
    }
}
