package week11.utils;

import java.security.SecureRandom;
import java.util.Random;

public class RandomSource {
    Random rnd = new SecureRandom();

    public int randInt()
    {
        return rnd.nextInt();
    }

    public int randInt(int max)
    {
        return rnd.nextInt(max);
    }

    public int randBetween(int min, int max)
    {
        return randInt(max-min) +min; //   min <= r <max
    }

    // Returns a random integer with given number of digits
    public int randWithDigits(int digitCount)
    {
        int min = (int) Math.pow(10,digitCount-1);
        int max = (int) Math.pow(10,digitCount);

        return randBetween(min,max);
    }

    public static void main(String[] args) {
        RandomSource rs = new RandomSource();

        for (int i = 0; i <10; i++) {
            System.out.println(rs.randWithDigits(4));
        }
    }


}
