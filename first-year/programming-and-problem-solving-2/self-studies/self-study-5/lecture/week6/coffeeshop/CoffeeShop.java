package week6.coffeeshop;

public class CoffeeShop {


    public static void main(String[] args) {
        TurkishCoffee tc  = new TurkishCoffee(CupSize.Small, false, true,false);
        Espresso es  = new Espresso(CupSize.Small, false);
        FilterCoffee fc  = new FilterCoffee(CupSize.Small, false, true);

        Coffee c = new Espresso(CupSize.Large,true);

        c = new TurkishCoffee(CupSize.Small,false,false,true);

        System.out.println(tc);
        System.out.println(es);
        System.out.println(fc);
    }
}
