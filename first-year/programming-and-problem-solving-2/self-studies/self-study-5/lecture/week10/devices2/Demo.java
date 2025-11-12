package week10.devices2;



public class Demo {

    public static void main(String[] args) {
        TV tv = new TV();
        AirConditioner ac = new AirConditioner();
        GarageDoor gd = new GarageDoor();
        Lamp lamp = new Lamp();

        RemoteController rc = new RemoteController();

        rc.addDevice(tv);
        rc.addDevice(ac);
        rc.addDevice(gd);
        rc.addDevice(lamp);

        rc.setCurrentDevice(0);

        rc.pressOn();

        rc.setCurrentDevice(1);

        rc.setCurrentDevice(3);

        rc.pressOn();





    }






}
