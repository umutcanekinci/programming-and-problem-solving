import java.util.ArrayList;
import java.util.List;

public class CarPark {
    private List<Vehicle> parkedVehicles;
    private int capacity;
    private int totalEarnings;

    public CarPark(int capacity) {
        this.capacity = capacity;
        parkedVehicles = new ArrayList<>();
        totalEarnings = 0;
    }

    public void parkVehicle(Vehicle vehicle) {
        if (capacity < vehicle.getVehicleSize().getSpace())
            return;

        parkedVehicles.add(vehicle);
    }

    public void releaseVehicle(Vehicle vehicle, double duration) {
        if(!parkedVehicles.contains(vehicle))
            return;

        parkedVehicles.remove(vehicle);
        capacity += vehicle.getVehicleSize().getSpace();
        totalEarnings += vehicle.calculateParkingFee(duration);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("CAR PARK").append(" - ").append(totalEarnings).append("\n");
        parkedVehicles.forEach(sb::append);
        return sb.toString();
    }
}
