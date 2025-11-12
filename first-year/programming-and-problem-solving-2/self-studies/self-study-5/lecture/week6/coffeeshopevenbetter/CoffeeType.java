package week6.coffeeshopevenbetter;

public enum CoffeeType {
    TurkishCoffee("Turkish Coffee",50.0), Espresso("Espresso",150), FilterCoffee("Filter Coffee",100);

    CoffeeType(String name, double price) {
        this.name = name;
        this.price = price;
    }

    final String name;
    final double price;

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}
