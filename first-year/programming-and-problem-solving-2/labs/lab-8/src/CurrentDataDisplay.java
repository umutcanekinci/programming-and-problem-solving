public class CurrentDataDisplay implements DisplayUnit{

    @Override
    public void refresh(double temperature, double humidity) {
        System.out.println("Temperature: " + temperature + " Humidity: " + humidity);
    }
}
