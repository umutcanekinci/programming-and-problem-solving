package week10.devices2;

public class GarageDoor implements Device{
    private boolean isOpen;

    public GarageDoor() {
        isOpen = false;
    }

    public boolean isOpen() {
        return isOpen;
    }

    public void open()
    {
        isOpen= true;
        System.out.println("Garage Door is opening");
    }

    public void close()
    {
        isOpen= false;
        System.out.println("Garage Door is closing");
    }

    public static void main(String[] args) {
        GarageDoor gd = new GarageDoor();

        gd.open();
        gd.close();
    }


    @Override
    public void on() {
        open();
    }

    @Override
    public void off() {
        close();
    }
}
