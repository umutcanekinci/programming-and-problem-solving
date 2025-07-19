package week10.devices;

public class TV {
    private static final int MAX_VOLUME = 20;

    boolean standBy;
    int channel;
    int volume;

    public TV() {
        standBy = true;
        channel = 1;
        volume = 8;
    }

    public boolean isStandBy() {
        return standBy;
    }

    public int getChannel() {
        return channel;
    }

    public int getVolume() {
        return volume;
    }

    public void on()
    {
        standBy = false;
        System.out.println("TV is ON");
    }

    public  void standBy()
    {
        standBy = true;
        System.out.println("TV is stand by");
    }
    public void setChannel(int channel)
    {
        if (standBy)
            return;

        this.channel =channel;
        System.out.println("TV is set to channel "+ channel);
    }
    public void increaseVolume() {
        if (standBy)
            return;
        if (volume<MAX_VOLUME)
            this.volume++;
        System.out.println("TV volume is increased to " + volume);
    }

    public static void main(String[] args) {
        TV tv = new TV();

        tv.on();
        tv.setChannel(3);
        tv.increaseVolume();
        tv.standBy();
    }




}
