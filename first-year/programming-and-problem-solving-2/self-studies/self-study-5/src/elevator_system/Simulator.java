package elevator_system;

import java.util.concurrent.TimeUnit;

public class Simulator {
    private Simultable simultable;
    private VisualizerSystem visiualizer;    

    public Simulator(Simultable simultable, VisualizerSystem visualizer) {
        Utils.checkNull(new Object[] {simultable, visualizer});
        this.simultable = simultable;
        this.visiualizer = visualizer;
    }

    public void simulate(int startTime, int endTime) {
        simultable.init();
        simulateNonvisual(startTime);
        simulateVisual(endTime - startTime);
        simultable.end();
    }

    private void simulateNonvisual(int time) {
        while (time-- > 0)
            simultable.update(time);
    }

    private void simulateVisual(int time) {
        while(time-- > 0) {
            simultable.update(time);
            visiualizer.display(simultable);
            sleep(1);
        }
    }

    private void sleep(int seconds) {
        try {
            TimeUnit.SECONDS.sleep(seconds);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new RuntimeException("Simulation interrupted", e);
        }
    }
}
