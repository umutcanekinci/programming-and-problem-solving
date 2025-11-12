package week6.coffeeshop_baddesign;

public class FilterCoffee {
    private final CupSize cupSize;
    private final boolean  hasSugar;
    private final boolean hasMilk;

    public FilterCoffee(CupSize cupSize, boolean hasSugar, boolean hasMilk) {
        this.cupSize = cupSize;
        this.hasSugar = hasSugar;
        this.hasMilk = hasMilk;
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
        String desc = "Filter Coffee";

        if (hasSugar)
            desc += " with sugar";

        if (hasMilk)
            desc += " with milk";

        desc += "(" + cupSize.toShortString() + ")";

        return desc;

    }

    public double price()
    {
        double price = 100.0;
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
        FilterCoffee tc1= new FilterCoffee(CupSize.Large, true, false);
        FilterCoffee tc2= new FilterCoffee(CupSize.Small, false, true);

        System.out.println(tc1);
        System.out.println(tc2);

    }
}
