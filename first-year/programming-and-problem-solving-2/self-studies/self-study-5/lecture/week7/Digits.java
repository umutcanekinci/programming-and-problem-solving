package week7;

import java.util.Arrays;

/**
 * TODO: Implement Digits class representing a number by storing its digits in an array
 */
public class Digits {
    private int[] digits; // Digits of the number


    /**
     * TODO: Returns the digits of a given number as an array
     *  Assume that n is positive
     * @param n
     * @return
     */
    public static int[] digitsOf(int n)
    {
        int digitCount = (int)Math.log10(n) + 1;
        int[] digits = new int[digitCount];

        for (int i = digitCount-1; i >=0 ; i--) {
            digits[i] = n %10;
            n /= 10;
        }

        return digits;
    }

    /**
     * TODO: Returns the integer whose digits are given
     * @param digits
     * @return
     */
    public static int valueOf(int[] digits)
    {
        int n =0;
        for (int i = 0; i < digits.length; i++) {
            n =  10*n + digits[i];
        }
        return n;
    }

    // TODO: Implement the following methods
    // !-> Copy Constructor X
    // !-> Constructor taking int X
    // !-> Getter X
    // !-> digitCount X
    // !-> toInt X
    // !-> toString X

    /**
     * !Copy Constructor
     * @param d
     */
    Digits( Digits d)
    {

        digits = new int[d.digits.length];

        for (int i = 0; i < digits.length; i++) {
            digits[i]= d.digits[i];
        }
    }


    Digits(int n)
    {
        digits = digitsOf(n);
    }

    /**
     * A dangerous getter returning reference to an attribute
     * @return
     */
    int[] getDigits()
    {
        return digits;
    }

    public int getDigit(int d)
    {
        return digits[d];
    }

    public int digitCount()
    {
        return digits.length;
    }

    public int toInt()
    {
        return valueOf(digits);
    }


    @Override
    public String toString() {
        return toInt()+ "";
    }

    public static void main(String[] args) {
       // System.out.println(Arrays.toString( digitsOf(0)) );

        System.out.println( valueOf(digitsOf(214)));

        Digits d = new Digits(123);


        System.out.println(d);

    }
}
