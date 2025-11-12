package week6.coffeeshop_baddesign;

public class TurkishCoffee {
    private final CupSize cupSize;
    private final boolean  hasSugar;
    private final boolean hasMilk;

    public TurkishCoffee(CupSize cupSize, boolean hasSugar, boolean hasMilk) {
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
        String desc = "Turkish Coffee";

        if (hasSugar)
            desc += " with sugar";

        if (hasMilk)
            desc += " with milk";

        desc += "(" + cupSize.toShortString() + ")";

        return desc;

    }

    public double price()
    {
        double price = 50.0;
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
        TurkishCoffee tc1= new TurkishCoffee(CupSize.Large, true, false);
        TurkishCoffee tc2= new TurkishCoffee(CupSize.Small, false, true);

        System.out.println(tc1);
        System.out.println(tc2);

    }
}
