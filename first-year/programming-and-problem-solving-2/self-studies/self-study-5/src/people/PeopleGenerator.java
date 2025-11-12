package people;

import java.util.ArrayList;
import java.util.List;

import elevator_system.Utils;

public class PeopleGenerator implements PeopleGeneratorSystem{
    private static float MIN_WEIGHT = 40f;
    private static float MAX_WEIGHT = 150f;

    @Override
    public List<People> generateRandomPeoples(int totalFloors) {
        int count = Utils.getRandomInt();
        List<People> result = new ArrayList<>();
        while (count-- < 0)
            result.add(generateRandomPeople(totalFloors));

        return result;
    }    

    public People generateRandomPeople(int totalFloors) {
        float weight = Utils.getRandomFloatBetween(MIN_WEIGHT, MAX_WEIGHT);
        int targetFloor = -1;
        while (Utils.isFloorValid(targetFloor, totalFloors))
            targetFloor = Utils.getRandomintBetween(0, totalFloors + 1);
        
        return new People(targetFloor, weight);
    }

}
