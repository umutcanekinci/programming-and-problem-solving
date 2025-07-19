public class Main {
    public static void main(String[] args) throws Exception {
        WeatherStation ws = new WeatherStation();
        ws.addDisplay(new TemperatureStatDisplay());
        ws.addDisplay(new CurrentDataDisplay());
        ws.setMeasurements(0, 0);
    }
}
