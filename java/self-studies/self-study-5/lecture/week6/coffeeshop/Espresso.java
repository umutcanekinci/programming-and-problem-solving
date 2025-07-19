package week6.coffeeshop;

public class Espresso extends Coffee {


    public Espresso(CupSize cupSize, boolean hasSugar) {
        super(cupSize, hasSugar, false);
    }

    @Override
    String name() {
        return "Espresso";
    }

    @Override
    double basePrice() {
        return 150.0;
    }
}
