package week6.employee;

public class Employee {

    protected static final int MIN_WAGE = 100;

    private final String name;

    /**
     * Creates an employee object
     * @param name
     */
    public Employee(String name) {
        this.name = name;

    }

    public String getName() {
        return name;
    }

    public int getPayment()
    {
        return MIN_WAGE;
    }
}
