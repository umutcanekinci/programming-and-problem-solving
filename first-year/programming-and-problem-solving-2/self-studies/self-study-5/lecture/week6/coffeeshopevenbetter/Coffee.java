package week6.coffeeshopevenbetter;

import week6.coffeeshop.CupSize;
import week6.coffeeshop.HotDrink;

public class Coffee  {
    protected final CupSize cupSize;
    protected final boolean  hasSugar;
    protected final boolean hasMilk;

    // Composing the coffe type
    private  CoffeeType  coffeeType;

    public Coffee(CoffeeType coffeeType,CupSize cupSize, boolean hasSugar, boolean hasMilk) {
        this.cupSize = cupSize;
        this.hasSugar = hasSugar;
        this.hasMilk = hasMilk;
        this.coffeeType = coffeeType;
    }

    public CupSize getCupSize() {
        return cupSize;
    }

    public boolean isHasSugar() {
        return hasSugar;
    }

    public boolean isHasMilk() {
        return hasMilk;
    }

    public String description()
    {
        String desc = coffeeType.getName();

        if (hasSugar)
            desc += " with sugar";

        if (hasMilk)
            desc += " with milk";

        desc += "(" + cupSize.toShortString() + ")";

        return desc;

    }



    public double price()
    {
        double price = coffeeType.getPrice();
        if (hasSugar)
            price += 3.0;
        if (hasMilk)
            price += 5.0;


        return price* cupSize.toPriceFactor();

    }


    public String toString() {
        return "[ " + description() + " ]" + "( " + price() + " TL)";
    }

    public static void main(String[] args) {
        Coffee coffee = new Coffee(CoffeeType.TurkishCoffee,CupSize.Large,true,true);
        Coffee coffee2 = new Coffee(CoffeeType.Espresso,CupSize.Large,true,true);
    }
}
