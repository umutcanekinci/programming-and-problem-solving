package week11.barbershop.selection;

import week11.barbershop.Barber;
import week11.barbershop.Customer;
import week11.barbershop.CustomerSelectionPolicy;

import java.util.List;

public class FirstComeFirstCSP implements CustomerSelectionPolicy {
    @Override
    public Customer select(List<Customer> customers, List<Barber> barbers, long clock) {

        if (customers.isEmpty())
            return null;

        Customer customer = customers.get(0);

        for (int i =1 ; i < customers.size() ; i++) {
            if  ( customers.get(i).getArrivalTime() < customer.getArrivalTime())
                customer = customers.get(i);
        }

        return customer;
    }
}
