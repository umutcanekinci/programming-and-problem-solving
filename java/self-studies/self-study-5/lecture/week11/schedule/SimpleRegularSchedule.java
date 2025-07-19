package week11.schedule;

import week11.base.Schedule;

public class SimpleRegularSchedule implements Schedule {

    long startClock;
    long endClock;
    long stepSize;

    public SimpleRegularSchedule(long startClock, long endClock, long stepSize) {
        this.startClock = startClock;
        this.endClock = endClock;
        this.stepSize = stepSize;
    }

    @Override
    public long next(long clock) {
        return clock + stepSize;
    }

    @Override
    public long startClock() {
        return startClock;
    }

    @Override
    public boolean isOver(long clock) {
        return clock>= endClock;
    }
}
