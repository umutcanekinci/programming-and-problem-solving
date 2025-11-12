package week7;

public class ComparisonResult {
    private final int plus;
    private final int minus;

    public ComparisonResult(int plus, int minus) {
        this.plus = plus;
        this.minus = minus;
    }

    public int getPlus() {
        return plus;
    }

    public int getMinus() {
        return minus;
    }

    @Override
    public String toString() {
        return "+" + plus + "-"+ minus;
    }

    public boolean isEqual(ComparisonResult other) {
        return plus ==other.plus && minus == other.minus;
    }
}
