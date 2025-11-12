package week10.devices2;

public class AirConditioner implements Device{
    boolean powerON;
    int temperature;
    ACMode mode;

    public AirConditioner() {
        this.powerON = false;
        this.temperature = 16;
        this.mode = ACMode.Summer;
    }

    public boolean isPowerON() {
        return powerON;
    }

    public int getTemperature() {
        return temperature;
    }

    public ACMode getMode() {
        return mode;
    }

    private void setMode(ACMode acMode) {
        this.mode = acMode;

        System.out.println("Airconditioner mode is set to "+ mode);
    }


    public void powerON() {
        powerON = true;
        System.out.println("Airconditioner is ON");
    }

    public void powerOFF() {
        powerON = false;
        System.out.println("Airconditioner is OFF");
    }

    public void increaseTemperature() {
        if (mode != ACMode.Humidity) {
            temperature++;
            System.out.println("The temperature is increased to " + temperature);
        }
    }

    public static void main(String[] args) {
        AirConditioner ac = new AirConditioner();

        ac.powerON();
        ac.setMode(ACMode.Summer);
        ac.increaseTemperature();
        ac.powerOFF();
    }

    @Override
    public void on() {
        powerON();
    }

    @Override
    public void off() {
        powerOFF();
    }
}
