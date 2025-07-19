package week11.barbershop;

import week11.barbershop.arrival.UniformArrivalGenerator;
import week11.base.Simulatable;
import week7.NumberPool;


import java.util.ArrayList;
import java.util.List;

public class BarberShop implements Simulatable {

    public static final int REST_TIME = 5;
    private static final int DEFAULT_START_TIME = 0;

    long clock;
    List<Barber> barbers;
    List<Customer> customers;
    final int capacity;

    ArrivalGenerator vicinity;
    CustomerSelectionPolicy csp;
    BarberSelectionPolicy bsp;

    // Total # of customers served
    int totalCustomerCount;

    // Total # of rejected customers
    int rejectedCustomerCount;

    // Total money earned
    int totalMoney;

    // Total wait time
    int totalWaitTime;
    private long lastClock;


    public BarberShop(int capacity, ArrivalGenerator vicinity, CustomerSelectionPolicy csp, BarberSelectionPolicy bsp) {
        this.capacity = capacity;
        this.vicinity = vicinity;
        this.csp = csp;
        this.bsp = bsp;
        barbers = new ArrayList<>();
        customers = new ArrayList<>();
    }

    @Override
    public void update(long clock) {
        this.clock = clock;
        updateWaiters();
        updateBarbers();

        lastClock = clock;
    }

    private void updateWaiters() {
        totalWaitTime +=  customers.size()*(clock-lastClock);

        Customer customer = vicinity.generateCustomer(clock);
        if (customer == null)
        {
            return;
        }

        if (customers.size()>= capacity)
        {
            rejectCustomer(customer);
            return;
        }

        customers.add(customer);
        totalCustomerCount++;
    }

    private void rejectCustomer(Customer customer) {
        rejectedCustomerCount++;
    }

    private void updateBarbers() {
        List<Barber> idleBarbers = new ArrayList<>();
        for (Barber b: barbers){
            b.update(clock);
            if (b.isIdle())
                idleBarbers.add(b);
        }

        while (!idleBarbers.isEmpty() && !customers.isEmpty())
        {
            Customer customer = csp.select(customers, barbers ,clock);
            Barber barber = bsp.select(idleBarbers,customer, clock); ;

            barber.takeCustomer(customer,clock);
            totalMoney += customer.getJob().toMoney();
            idleBarbers.remove(barber);
            customers.remove(customer);
        }

    }

    @Override
    public void init(long clock) {
        this.clock = clock;

        for (Barber b: barbers)
            b.init(clock);

        customers.clear();

        totalCustomerCount = 0;
        totalMoney = 0;
        totalWaitTime =0;
        rejectedCustomerCount = 0;
        lastClock =0;
    }

    @Override
    public void endSimulation(long clock) {
        totalCustomerCount -= customers.size();
        customers.clear();
    }

    public void addBarber(Barber barber)
    {
        barbers.add(barber);
    }

    public List<Barber> getBarbers() {
        return barbers;
    }

    public int getTCC() {
        return totalCustomerCount;
    }

    public int getRCC() {
        return rejectedCustomerCount;
    }

    public long getTM() {
        return totalMoney;
    }

    public double getAWT() {
        if (totalCustomerCount==0)
            return 0.0;
        return (double) totalWaitTime/(double) totalCustomerCount;
    }

    public int getCapacity() {
        return capacity;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public long getClock() {
        return clock;
    }
}
