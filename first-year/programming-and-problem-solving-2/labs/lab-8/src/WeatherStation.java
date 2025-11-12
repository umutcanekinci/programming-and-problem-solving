import java.util.ArrayList;
import java.util.List;

public class WeatherStation implements WeatherDataPublisher{

    private List<DisplayUnit> units;
    private double temperature;
    private double humidity;

    public WeatherStation() {
        units = new ArrayList<>();
    }

    public double getHumidity() {
        return humidity;
    }

    public double getTemperature() {
        return temperature;
    }

    public List<DisplayUnit> getUnits() {
        return units;
    }

    @Override
    public void addDisplay(DisplayUnit du) {
        if(du == null)
            throw new IllegalArgumentException("DisplayUnit cannot be null!");
        
        if(units.contains(du))
            return;
        
        units.add(du);
    }

    @Override
    public void removeDisplay(DisplayUnit du) {
        if(du == null)
            throw new IllegalArgumentException("DisplayUnit cannot be null!");
        
        if(!units.contains(du))
            return;
        
        units.remove(du);
    }

    @Override
    public void update() {
        for (DisplayUnit displayUnit : units)
            displayUnit.refresh(temperature, humidity);
    }

    @Override
    public void setMeasurements(double temperature, double humidity) {
        this.temperature = temperature;
        this.humidity = humidity;
        update();
    }
}
