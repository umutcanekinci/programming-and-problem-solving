package week10.devices;

/**
 * TODO: Implement a remote controller class to control the devices at home
 */
public class RemoteController {
    TV tv;
    GarageDoor door;
    AirConditioner ac;

    public RemoteController() {
    }

    void registerTV(TV tv)
    {
        this.tv = tv;
    }
    void registerAC(AirConditioner ac)
    {
        this.ac = ac;
    }

    void registerGarageDoor(GarageDoor gd)
    {
        this.door = gd;
    }




    public void tvOn() {
        tv.on();
    }
    public void tvStandBy() {
        tv.standBy();
    }

    public void acPowerOn() {
        ac.powerON();
    }
    public void acPowerOff() {
        ac.powerOFF();
    }

    public void doorOpen() {
        door.open();
    }
    public void doorClose() {
        door.close();
    }


    public void leavingHome()
    {
        tv.standBy();
        ac.powerOFF();
        door.close();
    }





}
