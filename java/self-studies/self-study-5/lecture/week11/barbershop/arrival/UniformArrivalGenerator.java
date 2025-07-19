package week11.barbershop.arrival;

import week11.barbershop.ArrivalGenerator;
import week11.barbershop.BarberJob;
import week11.barbershop.Customer;

import java.security.SecureRandom;
import java.util.Random;

public class UniformArrivalGenerator implements ArrivalGenerator {


    double arrivalRate;

    Random r = new SecureRandom();

    public UniformArrivalGenerator(double arrivalRate) {
        this.arrivalRate = arrivalRate;
    }

    @Override
    public Customer generateCustomer(long clock) {

        if ( r.nextDouble() < arrivalRate)
        {
            BarberJob job = BarberJob.values()[ r.nextInt(BarberJob.values().length)];
            Customer c = new Customer( job ,  clock);
            return c;
        }

        return null;
    }
}
