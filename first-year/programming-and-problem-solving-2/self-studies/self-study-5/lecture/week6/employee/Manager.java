package week6.employee;

public class Manager extends Employee{
    public Manager(String name) {
        super(name);
    }

    public int getPayment()
    {
        return (int)(1.9* Employee.MIN_WAGE);
    }

}
