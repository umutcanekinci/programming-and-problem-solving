package week10.devices;

public class GarageDoor {
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


}
