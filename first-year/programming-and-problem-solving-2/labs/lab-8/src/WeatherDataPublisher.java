public interface WeatherDataPublisher {
    void addDisplay(DisplayUnit du);
    void removeDisplay(DisplayUnit du);
    void update();
    void setMeasurements(double temperature, double humidity);
}
