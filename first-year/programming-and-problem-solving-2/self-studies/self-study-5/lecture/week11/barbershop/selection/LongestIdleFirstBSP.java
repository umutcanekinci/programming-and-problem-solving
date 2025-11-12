package week11.barbershop.selection;

import week11.barbershop.Barber;
import week11.barbershop.BarberSelectionPolicy;
import week11.barbershop.Customer;

import java.util.List;

public class LongestIdleFirstBSP implements BarberSelectionPolicy {
    @Override
    public Barber select(List<Barber> idleBarbers, Customer customer, long clock) {
        if (idleBarbers.isEmpty())
            return null;

        Barber barber = idleBarbers.get(0);

        for (int i =1 ; i < idleBarbers.size() ; i++) {
            if  ( idleBarbers.get(i).getLastStateChangeTime() < barber.getLastStateChangeTime())
                barber = idleBarbers.get(i);
        }

        return barber;
    }
}
