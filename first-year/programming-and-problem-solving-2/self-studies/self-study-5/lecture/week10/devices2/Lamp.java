package week10.devices2;

public class Lamp implements Device{
    private boolean isOn;

    @Override
    public void on() {
        isOn = true;
        System.out.println("The lamp is on");
    }

    @Override
    public void off() {
        isOn = false;
        System.out.println("The lamp is Off");
    }
}
