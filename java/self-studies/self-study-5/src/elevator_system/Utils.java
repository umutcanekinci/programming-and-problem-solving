package elevator_system;

import java.util.Random;

public class Utils {
    private static Random random = new Random();

    // Private constructor to prevent instantiation
    private Utils() {}

    public static float getRandomFloatBetween(float min, float max) {
        return random.nextFloat(min, max);
    }

    public static int getRandomInt() {
        return random.nextInt();
    }

    public static int getRandomintBetween(int min, int max) {
        return random.nextInt(min, max);
    }

    public static boolean isFloorValid(int floor, int totalFloors) {
        return floor >= 0 && floor < totalFloors;
    }

    public static void checkFloor(int sourceFloor, int totalFloors) {
        if (!Utils.isFloorValid(sourceFloor, totalFloors))
            throw new IllegalStateException("sourceFloor should be between 0 and " + (totalFloors - 1) + ", but was: " + sourceFloor);
    }

    public static void checkTotalFloors(int totalFloors) {
        if (totalFloors <= 0)
            throw new IllegalArgumentException("Why are you using elevators for " + totalFloors + " floors?");        
    }

    public static void checkNull(Object[] objectTypes) {
        checkNull(objectTypes);
        for (Object object : objectTypes)
            checkNull(object);
    }

    public static void checkNull(Object object) {
        if (object == null)
            throw new IllegalArgumentException("Object cannot be null!");
    }

    public static void checkElevatorCount(int elevatorCount) {
        if (elevatorCount <= 0)
            throw new IllegalArgumentException("A elevator system without elevators..");
    }
}
