public abstract class Vehicle {
    private String licensePlate;
    protected VehicleSize vehicleSize;

    public Vehicle(String licensePlate) {
        this.licensePlate = licensePlate;
    }

    public String GetLicensePlate() {
        return licensePlate;
    }

    public VehicleSize getVehicleSize() {
        return vehicleSize;
    }

    public abstract double calculateParkingFee(double duration);

    public String toString() {
        return "Vehicle{" +
                "licensePlate='" + licensePlate + '\'' +
                ", vehicleSize=" + vehicleSize +
                '}';
    }
}

