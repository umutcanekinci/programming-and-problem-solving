package week10.devices2;

import java.util.List;

public class MediaDeviceRC extends RemoteController{
    @Override
    void addDevice(Device device) {

        if ( !(device instanceof  AudibleDevice))
        {
            System.out.println("I can not this device");
            return;
        }

        super.addDevice(device);
    }

    @Override
    public String toString() {
        return super.toString();
    }

    public void presssVolumeUp()
    {
        AudibleDevice ad = (AudibleDevice) devices.get(currentDevice);
        ad.volumeUp();
    }
}
