package people;

import elevator_system.Direction;
import elevator_system.Simultable;
import elevator_system.elevator.Elevator;

public class People implements Simultable {
    private int targetFloor;
    private float weight;
    private Elevator elevator;

    public People(int targetFloor, float weight) {
        this.targetFloor = targetFloor;
        this.weight = weight;
    }

    //region Getters
    
    public float getWeight() {
        return weight;
    }

    public Direction getTargetDirection(int currentFloor) {
        if (currentFloor == targetFloor)
            return null;

        return currentFloor < targetFloor ? Direction.UP : Direction.DOWN;
    }

    //endregion

    @Override
    public void init() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'init'");
    }

    @Override
    public void update(int time) {
        if (isInElevator()) {
            if (elevator.getCurrentFloor() == targetFloor && elevator.isWaiting())
                elevator.takeOutPeople(this);

        }
    }

    private boolean isInElevator() {
        return elevator != null;
    }
    
    private void takeElevator(Elevator elevator) {
        // Assume people are intelligent enough to not take elevator when there is no enough capacity.
        if (!elevator.isThereEnoughCapacity(weight))
            return;
        
        elevator.takePeople(this);
        this.elevator = elevator;
    }

    private void getOffElevator() {
        this.elevator = null;
    }

    @Override
    public void end() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'end'");
    }
}
