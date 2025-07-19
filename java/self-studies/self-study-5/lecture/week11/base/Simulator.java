package week11.base;

import week11.dummy.SimpleBactery;
import week7.utils.ConsolUtils;

public class Simulator {

    long clock;

    Simulatable system;
    SystemVisualizer visualizer;
    Schedule schedule;
    private boolean silentSimulation;
    private long waitTime;

    public Simulator(Simulatable system, SystemVisualizer visualizer, Schedule schedule, boolean silent, int waitTime) {
        this.system = system;
        this.visualizer = visualizer;
        this.schedule = schedule;
        this.silentSimulation = silent;
        this.waitTime = waitTime;
    }


    public void simulate()
    {
        init();

        while ( !schedule.isOver(clock))
        {
            system.update(clock);

            if (!silentSimulation)
            {
                displaySystem();
            }
            clock = schedule.next(clock);
        }

        endSimulation();
    }

    private void endSimulation() {
        system.endSimulation(clock);
        displaySystem();
    }

    private void init() {
        clock = schedule.startClock();

        system.init(clock);
    }

    private void displaySystem() {
        ConsolUtils.clearScreen();
        System.out.println(ConsolUtils.colorize("[ CLOCK: "+ clock+ " ]",ConsolUtils.ANSI_GREEN));
        if (visualizer != null)
            visualizer.visualize(system);

        if ( waitTime>0)
            ConsolUtils.pause(waitTime);
    }

}
