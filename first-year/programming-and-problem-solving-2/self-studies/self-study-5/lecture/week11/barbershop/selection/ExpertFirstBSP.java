package week11.barbershop.selection;

import week11.barbershop.Barber;
import week11.barbershop.BarberSelectionPolicy;
import week11.barbershop.Customer;

import java.util.List;

public class ExpertFirstBSP implements BarberSelectionPolicy {

    /**
     * TODO: Implement this BSP to select expert barber first
     * @param idleBarbers
     * @param customer
     * @param clock
     * @return
     */
    @Override
    public Barber select(List<Barber> idleBarbers, Customer customer, long clock) {
        return null;
    }
}
