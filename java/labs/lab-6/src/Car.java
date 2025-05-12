public class Car extends Vehicle {
    public Car(String licensePlate) {
        super(licensePlate);
        this.vehicleSize = VehicleSize.MEDIUM;
    }

    @Override
    public double calculateParkingFee(double duration) {
        return duration * vehicleSize.getPayment();
    }
}
