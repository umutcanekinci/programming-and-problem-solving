package week6.employee;

public class Engineer extends Employee{
    public Engineer(String name) {
        super(name);
    }

    @Override
    public int getPayment()
    {
        return (int)(1.5*Employee.MIN_WAGE);
    }


}
