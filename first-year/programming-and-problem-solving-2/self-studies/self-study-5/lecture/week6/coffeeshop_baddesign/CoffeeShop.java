package week6.coffeeshop_baddesign;

public class CoffeeShop {


    public static void main(String[] args) {
        TurkishCoffee tc  = new TurkishCoffee(CupSize.Small, false, true);
        Espresso es  = new Espresso(CupSize.Small, false, true);
        FilterCoffee fc  = new FilterCoffee(CupSize.Small, false, true);

        System.out.println(tc);
        System.out.println(es);
        System.out.println(fc);
    }
}
