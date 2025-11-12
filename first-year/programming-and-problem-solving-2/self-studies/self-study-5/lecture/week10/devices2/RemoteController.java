package week10.devices2;

import java.util.ArrayList;
import java.util.List;

public class RemoteController {
    List<Device> devices;

    int  currentDevice;

    public RemoteController() {
        devices = new ArrayList<>();
    }

    void setCurrentDevice(int deviceIndex)
    {
        currentDevice = deviceIndex;
    }


    void addDevice( Device device)
    {
        devices.add(device);
    }


    public void pressOn()
    {
        devices.get(currentDevice).on();
    }

    public void pressOff()
    {
        devices.get(currentDevice).off();
    }

    public void leavingHome()
    {
        for (Device d:devices)
        {
            d.off();  // Polymorphism
        }
    }



}
