package elevator_system.elevator;

import people.People;

public class ElevatorCondition {
    private ElevatorType elevatorType;
    private int totalWeight;
    private int peopleCount;
    

    public ElevatorCondition(ElevatorType elevatorType) {
        this.elevatorType = elevatorType;
    }

    public void init() {
        totalWeight = 0;
        peopleCount = 0;
    }

    public boolean isThereEnoughCapacity(float weight) {
        return isThereEnoughPeopleCapacity() && isThereEnoughWeightCapacity(weight);
    }

    private boolean isThereEnoughPeopleCapacity() {
        return elevatorType.getPeopleCapacity() > peopleCount;
    }
    
    private boolean isThereEnoughWeightCapacity(float weight) {
        return totalWeight + weight <= elevatorType.getWeightCapacity();
    }

    public void takePeople(People people) {
        totalWeight += people.getWeight();
        peopleCount ++;
    }

    public void takeOutPeople(People people) {
        totalWeight -= people.getWeight();
        peopleCount --;
    }
}
