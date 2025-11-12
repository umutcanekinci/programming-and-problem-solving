package week11.barbershop;

import java.util.List;

public interface BarberSelectionPolicy {
    Barber select(List<Barber> idleBarbers, Customer customer, long clock);
}
