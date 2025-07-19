package week11.barbershop.selection;

import week11.barbershop.Barber;
import week11.barbershop.Customer;
import week11.barbershop.CustomerSelectionPolicy;

import java.util.List;


/**
 * TODO: Implement this CSP to select the expensive customer first
 */
public class ExpensiveJobFirstCSP implements CustomerSelectionPolicy {
    @Override
    public Customer select(List<Customer> customers, List<Barber> barbers, long clock) {
        return null;
    }
}
