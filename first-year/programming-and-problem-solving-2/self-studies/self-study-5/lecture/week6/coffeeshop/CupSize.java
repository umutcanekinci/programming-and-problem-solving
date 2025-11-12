package week6.coffeeshop;

public enum CupSize {
    Small(1.0), Medium(1.5), Large(2.0), ExtraLarge(3.0);

    private final double priceFactor;

    CupSize(double priceFactor) {
        this.priceFactor = priceFactor;
    }

    public String toShortString()
    {
       switch (this)
       {
           case Large: return "L";
           case Medium: return "M";
           case Small: return "S";
           case ExtraLarge: return "XL";
           default: return "L";
       }
    }

    public double toPriceFactor()
    {
        return priceFactor;
    }
}
