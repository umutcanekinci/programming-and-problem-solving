package week11.barbershop;

public enum BarberJob {
    LongHairCut(20,30), ShortHairCut(15,15), Shave(30,10), Dying(50,60), BrideHead(300,120);

    int money;
    int time;

    BarberJob(int money, int time) {
        this.money = money;
        this.time = time;
    }

    int toMoney()
    {
        return money;
    }

    int toTime()
    {
        return money;
    }
}
