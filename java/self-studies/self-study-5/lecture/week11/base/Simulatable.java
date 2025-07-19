package week11.base;

public interface Simulatable {
    void update(long clock);

    void init(long clock);

    void endSimulation(long clock);
}
