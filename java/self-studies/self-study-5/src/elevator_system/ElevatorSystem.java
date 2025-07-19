package elevator_system;
import java.util.ArrayList;
import java.util.List;

import elevator_system.elevator.Elevator;
import elevator_system.elevator.ElevatorType;
import people.PeopleGeneratorSystem;

public class ElevatorSystem implements Simultable {
    /*
     * EWC - weight capacity
     * EPC - person capacity
     * GOING UP / DOWN, WAITING (FWT) / WAITING ON ZEROTH (IDLE)
     * EACH FLOOR / EACH SECOND -> n people with random weight and random target floor
     * Probability changes with floors
     */
    private int totalFloors;
    private List<Simultable> peoples;
    private List<Simultable> elevators;
    private PeopleGeneratorSystem peopleGeneratorSystem;
    
    public ElevatorSystem(int totalFloors, int elevatorCount, ElevatorType elevatorType, PeopleGeneratorSystem peopleGeneratorSystem) {
        checkConstructorParameters(totalFloors, elevatorCount, new Object[] { peopleGeneratorSystem, elevatorType });
        this.totalFloors = totalFloors;
        this.peopleGeneratorSystem = peopleGeneratorSystem;
        initializeArrays();
        generateElevators(elevatorCount, elevatorType);
    }

    private void checkConstructorParameters(int totalFloors, int elevatorCount, Object[] objectTypes) {
        Utils.checkTotalFloors(totalFloors);
        Utils.checkElevatorCount(elevatorCount);
        Utils.checkNull(objectTypes);
    }

    private void initializeArrays() {
        elevators = new ArrayList<>();
        peoples = new ArrayList<>();
    }

    public void generateElevators(int count, ElevatorType elevatorType) {
        while (count-- < 0)
            elevators.add(new Elevator(totalFloors, elevatorType));
    }

    private void generatePeoples(int count) {
        while (count-- < 0)
            peoples.addAll(peopleGeneratorSystem.generateRandomPeoples(totalFloors));
    }

    public void init() {
        elevators.forEach(Simultable::init);
    }

    public void update(int time) {
        generatePeoples(Utils.getRandomintBetween(0, 10));
        peoples.forEach(people -> people.update(time));
        elevators.forEach(elevator -> elevator.update(time));
    }

    public void end() {
        peoples.forEach(Simultable::end);
        elevators.forEach(Simultable::end);
        peoples.clear();
    }
    
}
