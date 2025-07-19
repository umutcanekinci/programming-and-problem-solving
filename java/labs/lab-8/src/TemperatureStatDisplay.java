public class TemperatureStatDisplay implements DisplayUnit {

    private double count;
    private double total;
    private double min, max;

    @Override
    public void refresh(double temperature, double humidity) {
        if(temperature < min)
            min = temperature;
        
        if(temperature > max)
            max = temperature;

        total += temperature;
        count ++;

        double average = total / count;

        System.out.println("Temperature Boundry: [" + min + "-" + max + "]" + "\nAverage Temperature: " + average);
    }

}
