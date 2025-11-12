package week11.barbershop;

public class Customer {
    private final BarberJob job;
    private final long arrivalTime;

    public Customer(BarberJob job, long arrivalTime) {
        this.job = job;
        this.arrivalTime = arrivalTime;
    }

    public BarberJob getJob() {
        return job;
    }

    public long getArrivalTime() {
        return arrivalTime;
    }
}
