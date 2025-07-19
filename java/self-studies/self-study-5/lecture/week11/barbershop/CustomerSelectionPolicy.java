package week11.barbershop;

import java.util.List;

public interface CustomerSelectionPolicy {
    Customer select(List<Customer> customers, List<Barber> barbers, long clock);
}
