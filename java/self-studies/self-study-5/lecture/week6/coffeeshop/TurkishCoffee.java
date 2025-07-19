package week6.coffeeshop;

public class TurkishCoffee extends Coffee {

    boolean hasMastic;

    public TurkishCoffee(CupSize cupSize, boolean hasSugar, boolean hasMilk, boolean hasMastic) {
        super(cupSize, hasSugar, hasMilk);
        this.hasMastic = hasMastic;
    }


    String name() {
        return "Turkish Coffee";
    }


    double basePrice() {
        return 50.0;
    }

    public double price()
    {
        double price = super.price();

        if (hasMastic)
            price += 5.0*cupSize.toPriceFactor();

        return price;
    }

    public String description()
    {
        String desc = super.description();

        if (hasMastic)
            desc += " with mastic";

        return desc;
    }


}
