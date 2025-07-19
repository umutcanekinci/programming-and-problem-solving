package week11.barbershop;

public class Barber {
    String name;
    BarberSkill skill;
    BarberState state;
    Customer customer;


    public Barber(String name, BarberSkill skill) {
        this.name = name;
        this.skill = skill;
    }

    // # of served customers
    int servedCustomerCount;

    // Total money earned by this barber
    int totalMoney;

    // Total idle time
    long totalIdleTime;

    // Most recent state change time
    long lastStateChangeTime;

    public void init(long clock) {
        servedCustomerCount =0;
        totalIdleTime=0;
        totalMoney =0;
        state = BarberState.Idle;
        lastStateChangeTime = clock;
        customer = null;
    }

    public void update(long clock) {
        switch (state)
        {
            case Busy:{
                updateBusyBarber(clock);
                break;
            }
            case Resting:
            {
                updateRestingBarber(clock);
                break;
            }
        }
    }

    private void updateRestingBarber(long clock) {
        if (state!= BarberState.Resting)
            return;
        if ( clock - lastStateChangeTime >= BarberShop.REST_TIME)
        {
            state = BarberState.Idle;
            lastStateChangeTime = clock;
        }
    }

    private void updateBusyBarber(long clock) {
        if (state != BarberState.Busy)
            return;

        int serviceTime = serviceTime();
        if ( clock-lastStateChangeTime >= serviceTime)
        {
            servedCustomerCount++;
            state = BarberState.Resting;
            lastStateChangeTime = clock;
        }

    }

    public boolean isIdle() {
        return state == BarberState.Idle;
    }

    public void takeCustomer(Customer customer, long clock) {
        this.customer = customer;
        totalIdleTime += clock-lastStateChangeTime;
        state = BarberState.Busy;
        totalMoney += customer.getJob().toMoney();
        lastStateChangeTime = clock;
    }

    public long getLastStateChangeTime() {
        return lastStateChangeTime;
    }

    public String getName() {
        return name;
    }

    public BarberSkill getSkill() {
        return skill;
    }

    public BarberState getState() {
        return state;
    }

    public int getSCC() {
        return servedCustomerCount;
    }

    public int getTM() {
        return totalMoney;
    }

    public Customer getCustomer() {
        return customer;
    }

    public int serviceTime() {
        return (int)(customer.getJob().toTime()* skill.toTimeCoefficient());
    }
}
