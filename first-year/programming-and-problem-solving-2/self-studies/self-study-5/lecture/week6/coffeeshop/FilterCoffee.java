package week6.coffeeshop;

public class FilterCoffee extends Coffee {

    public FilterCoffee(CupSize cupSize, boolean hasSugar, boolean hasMilk) {
        super(cupSize, hasSugar, hasMilk);
    }

    @Override
    String name() {
        return "Filter Coffee";
    }

    @Override
    double basePrice() {
        return 100.0;
    }
}
