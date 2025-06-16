import java.util.ArrayList;
import java.util.List;

public class UtilityCompany {
    private List<Customer> customers;

    private UtilityCompany() {
        customers = new ArrayList<>();
    }

    public void addCustomer(Customer customer) {
        if(customer == null)
            return;

        customers.add(customer);
    }

    public void removeCustomer(Customer customer) {
        if(customer == null) 
            return;

        if(!customers.contains(customer)) 
            return;

        customers.remove(customer);
        System.out.println(customer.getName() + " is deleted succesfuly.\n");
    }

    public double getTotalRevenue(List<Double> usageUnitList) {
        double total = 0;
        if (usageUnitList == null)
            return -1;

        if(usageUnitList.size() != customers.size())
            return -1;

        for(int i=0; i<usageUnitList.size(); i++) {
            Customer customer = customers.get(i);

            if(customer == null)
                continue;

            Double usageUnits = usageUnitList.get(i);
            if(usageUnits == null)
                continue;

            total += customer.calculateBill(usageUnits);
        }
        
        return total;
    }

    public void increaseRatePerUnit(double amount) {
        for(Customer customer : customers)
            customer.ratePerUnit += amount;

        System.out.println("Rate per unit value is increased by " + amount + " for all customers.\n");
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("|Customers|\n");

        customers.forEach(customer -> sb.append(customer).append("\n"));
        return sb.toString();
    }

    public static void main(String[] args) {
        Customer[] customers = new Customer[] {
            new ResidentalCustomer(0, "Res. Customer 1", 100),
            new ResidentalCustomer(1, "Res. Customer 2", 110),
            new CommercialCustomer(2, "Com Customer 1", 110, 10),
            new CommercialCustomer(3, "Com Customer 1", 110, 20),
        };

        UtilityCompany utilityCompany = new UtilityCompany();
        for(Customer customer : customers)
            utilityCompany.addCustomer(customer);

        List<Double> usageUnitList = new ArrayList<>() {{
            add(10.);
            add(10.);
            add(10.);
        }};

        System.out.println(utilityCompany);
        utilityCompany.removeCustomer(customers[0]);
        System.out.println(utilityCompany);
        utilityCompany.increaseRatePerUnit(10);
        System.out.println(utilityCompany);
        System.out.println("Total revenue: " + utilityCompany.getTotalRevenue(usageUnitList));
    }


}
