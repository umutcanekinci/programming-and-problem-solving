public class Truck extends Vehicle {
    public Truck(String licensePlate) {
        super(licensePlate);
        this.vehicleSize = VehicleSize.LARGE;
    }

    @Override
    public double calculateParkingFee(double duration) {
        return duration * vehicleSize.getPayment();
    }

}
