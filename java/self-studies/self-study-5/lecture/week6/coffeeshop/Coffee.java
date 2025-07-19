package week6.coffeeshop;

public abstract class Coffee extends HotDrink {
    protected final CupSize cupSize;
    protected final boolean  hasSugar;
    protected final boolean hasMilk;

    public Coffee(CupSize cupSize, boolean hasSugar, boolean hasMilk) {
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
        String desc = name();

        if (hasSugar)
            desc += " with sugar";

        if (hasMilk)
            desc += " with milk";

        desc += "(" + cupSize.toShortString() + ")";

        return desc;

    }

    abstract String name();

    public double price()
    {
        double price =basePrice();
        if (hasSugar)
            price += 3.0;
        if (hasMilk)
            price += 5.0;


        return price* cupSize.toPriceFactor();

    }

    abstract double basePrice();


    public String toString() {
        return "[ " + description() + " ]" + "( " + price() + " TL)";
    }

    public static void main(String[] args) {

    }
}
