package week11.dummy;

import week11.base.Schedule;
import week11.base.Simulator;
import week11.base.SystemVisualizer;
import week11.schedule.SimpleRegularSchedule;

public class BacterySimulationDemo {
    public static void main(String[] args) {
        SimpleBactery bactery = new SimpleBactery();
        SystemVisualizer visualizer = new AdvancedBacteryVisualizer();
        Schedule schedule = new SimpleRegularSchedule(0,1000,1);

        Simulator simulator = new Simulator(    bactery,
                                                visualizer,
                                                schedule,
                                                false,
                                                1000);

        simulator.simulate();

    }
}
