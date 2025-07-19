package week7.utils;

import java.security.SecureRandom;
import java.util.Random;

/**
 * TODO: Implement the following methods
 */
public class RandomSource {
    Random rnd = new SecureRandom();

    /**
     * TODO: Generates a random integer
     * @return
     */
    public int randInt()
    {
        return Math.abs(rnd.nextInt());
    }

    /**
     * TODO: Generates a random integer smaller than max (exclusive)
     * @param max
     * @return
     */
    public int randInt(int max)
    {
        return randInt() % max;
    }

    /**
     * TODO: Generates a random integer between min(inclusive) and max (exclusive)
     * @param min
     * @param max
     * @return
     */
    public int randBetween(int min, int max)
    {
        return min  + randInt(max-min);
    }

    /**
     * TODO: Generates a random integer with given number of digits
     */

    public int randWithDigits(int digitCount)
    {
        int min = (int)Math.pow(10,digitCount-1);
        int max = (int)Math.pow(10,digitCount);

        return randBetween(min,max);
    }

    public static void main(String[] args) {
        RandomSource rs = new RandomSource();

        for (int i = 0; i <10; i++) {
            System.out.println(rs.randWithDigits(4));
        }
    }


}
