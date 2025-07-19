package elevator_system.elevator;
public enum ElevatorStatus {
    GOING_UP, GOING_DOWN, WAITING, IDLE_ON_GROUND;

    public static ElevatorStatus getDirectionTo(int currentFloor, int targetFloor) {
        int delta = targetFloor - currentFloor;
        if(delta > 0)
            return GOING_UP;

        if(delta < 0)
            return GOING_DOWN;

        return WAITING;
    }
}
