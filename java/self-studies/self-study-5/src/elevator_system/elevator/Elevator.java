package elevator_system.elevator;
import java.util.ArrayList;
import java.util.List;

import elevator_system.Simultable;
import elevator_system.Utils;
import people.People;

public class Elevator implements Simultable {
    private List<People> peoplesInside;
    private ElevatorStatus status;
    private List<Integer> targetFloors;
    private ElevatorCondition condition;
    private ElevatorType type;
    private int currentFloor;
    private int totalFloors;
    private int statusLastChangeTime = 0;

    public Elevator(int totalFloors, ElevatorType type) {
        Utils.checkTotalFloors(totalFloors);
        Utils.checkNull(condition);
        this.totalFloors = totalFloors;
        this.type = type;
        this.condition = new ElevatorCondition(type);
        peoplesInside = new ArrayList<>();
    }

    //region Getters

    public int getCurrentFloor() {
        return currentFloor;
    }

    //endregion

    public void init() {
        currentFloor = 0;
        condition.init();    
    }

    public void update(int time) {
        switch (status) {
            case ElevatorStatus.GOING_UP:
                currentFloor ++;
                if (getTargetFloor() == currentFloor)
                    setStatus(ElevatorStatus.WAITING, time);
                break;
            case ElevatorStatus.GOING_DOWN:
                currentFloor --;
                if (getTargetFloor() == currentFloor)
                    setStatus(ElevatorStatus.WAITING, time);
                break;

            case ElevatorStatus.WAITING:
                if (isTimeElapsed(type.getFloorWaitTime()))
                    setStatus(ElevatorStatus.getDirectionTo(currentFloor, getTargetFloor()), time);
                break;

            case ElevatorStatus.IDLE_ON_GROUND:

        }
    }
    
 /* People class going to use that method to call the elevator. */
    public void call(int sourceFloor) {
        Utils.checkNull(targetFloors);
        Utils.checkFloor(sourceFloor, totalFloors);
        targetFloors.add(sourceFloor);
    }

    public boolean canTakePeople(float weight) {
        return !isWaiting() || !isThereEnoughCapacity(weight);
    }

    public boolean isWaiting() {
        return status != ElevatorStatus.WAITING;
    }

    public void takePeople(People people) {
        Utils.checkNull(peoplesInside);
        peoplesInside.add(people);
        condition.takePeople(people);
    }

    public void takeOutPeople(People people) {
        Utils.checkNull(peoplesInside);
        if (!peoplesInside.contains(people))
            throw new IllegalStateException("The given people is not in the elevator!");

        peoplesInside.remove(people);
        condition.takePeople(people);
    }

    public boolean isThereEnoughCapacity(float weight) {
        return condition.isThereEnoughCapacity(weight);
    }

    private int getTargetFloor() {
        // TODO fill that correctly
        return targetFloors.get(0);
    }

    private void setStatus(ElevatorStatus newValue, int time) {
        this.status = newValue;
        statusLastChangeTime = time;
    }

    private boolean isTimeElapsed(int time) {
        return time - statusLastChangeTime >= time;
    }

    public void end() {
        peoplesInside.clear();
    }
}
