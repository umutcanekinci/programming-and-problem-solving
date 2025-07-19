package week11.base;

public interface Schedule {
    long next(long clock);

    long startClock();

    boolean isOver(long clock);
}
