package week7;

import week7.utils.RandomSource;

/**
 * TODO: Implement the methods about the Master Mind Game
 */
public class MasterMindUtils {

    /**
     * TODO: Returns if arr has any duplicate elements
     * @param arr
     * @return
     */
    public static boolean hasDuplicates(int[] arr )
    {
        for (int f1 = 0; f1 < arr.length - 1; f1++) {
            for (int f2 = f1+1; f2 < arr.length; f2++) {
                if (arr[f1]== arr[f2])
                    return true;
            }
        }
        return false;
    }

    /**
     * TODO: Returns if digits object has any duplicate elements
     * @param d
     * @return
     */
    public static boolean hasDuplicates(Digits d)
    {
        return hasDuplicates(d.getDigits());
    }

    /**
     * TODO: Returns if digits object is valid according to MasterMind
     * @param d
     * @return
     */
    public static boolean isValid(Digits d, int digitCount)
    {
        return d.digitCount()==digitCount && !hasDuplicates(d);
    }

    /**
     * TODO: Returns a random valid number as Digits object
     * @return
     */
    public static Digits randomNumber(int digitCount)
    {
        RandomSource rs = new RandomSource();


        Digits d = new Digits(100);

        while (!isValid(d,digitCount))
        {
            int n = rs.randWithDigits(digitCount);
            d = new Digits(n);
        }

        return d;
    }

    /**
     * TODO: Returns plus comparison of two numbers
     * @return
     */
    public static int plusOf(int[] d1, int[] d2)
    {
        int plus = 0;
        for (int f = 0; f < d1.length; f++) {
            if (d1[f]== d2[f])
                plus++;
        }
        return plus;
    }

    /**
     * TODO: Returns minus comparison of two numbers
     * @return
     */
    public static int minusOf(int[] d1, int[] d2)
    {
        int minus=0;

        for (int f1 = 0; f1 < d1.length; f1++) {
            for (int f2 = 0; f2 < d2.length; f2++) {
                if (d1[f1]== d2[f2] && f1 != f2)
                    minus++;
            }
        }

        return minus;
    }


    // TODO: Implement the following methods:
    // !-> compare(Digits d1, Digits d2)
    static ComparisonResult compare(Digits d1, Digits d2)
    {
        int plus = plusOf(d1.getDigits(), d2.getDigits());
        int minus = minusOf( d1.getDigits(), d2.getDigits());

        return new ComparisonResult(plus, minus);
    }

    public static void main(String[] args) {
        Digits d1 = new Digits(1980);
        Digits d2 = new Digits(7318);

        System.out.println(d1 + "  " + d2 + "  " + compare(d1,d2));
    }
}
