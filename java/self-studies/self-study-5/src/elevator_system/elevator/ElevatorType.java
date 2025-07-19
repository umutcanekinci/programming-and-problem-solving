package elevator_system.elevator;

public enum ElevatorType {
    FAST_AND_SMALL(4, 300, 2),
    SLOW_AND_LARGE(8, 1000, 4);

    private int peopleCapacity;
    private int weightCapacity;
    private int floorWaitTime;
    
    ElevatorType(int peopleCapacity, int weightCapacity, int floorWaitTime) {
        this.peopleCapacity = peopleCapacity;
        this.weightCapacity = weightCapacity;
        this.floorWaitTime = floorWaitTime;
    }

    public int getPeopleCapacity() {
        return peopleCapacity;
    }

    public int getWeightCapacity() {
        return weightCapacity;
    }

    public int getFloorWaitTime() {
        return floorWaitTime;
    }
}
