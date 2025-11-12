package week10.devices;

public class Demo {
    public static void main(String[] args) {

        TV tv = new TV();
        AirConditioner ac = new AirConditioner();
        GarageDoor gd = new GarageDoor();

        RemoteController rc = new RemoteController();
        rc.registerTV(tv);
        rc.registerAC(ac);
        rc.registerGarageDoor(gd);


        rc.tvOn();
        rc.doorOpen();
        rc.acPowerOn();

        rc.leavingHome();



    }
}
