package week11.dummy;

import week11.base.Simulatable;

import java.security.SecureRandom;
import java.util.Random;

public class SimpleBactery implements Simulatable {

    public static final double MAX_SALT = 3.0;
    public static final double MAX_SUGAR = 10.0;
    public static final double MAX_CALCIUM = 1.0;
    private static final double MAX_SALT_CHANGE = 1.0;
    private static final double MAX_SUGAR_CHANGE = 2.0;
    private static final double MAX_CALCIUM_CHANGE = 0.05;


    private double salt;
    private double sugar;
    private double calcium;

    private Random rng = new SecureRandom();

    @Override
    public void update(long clock) {
        double dSalt = (rng.nextBoolean() ? 1:-1)* rng.nextDouble() * MAX_SALT_CHANGE;
        double dSugar = (rng.nextBoolean() ? 1:-1)*rng.nextDouble() * MAX_SUGAR_CHANGE;
        double dCalcium = (rng.nextBoolean() ? 1:-1)*rng.nextDouble() * MAX_CALCIUM_CHANGE;

        salt =  Math.max(Math.min( MAX_SALT, salt+dSalt),0);
        sugar =  Math.max(Math.min( MAX_SUGAR, sugar+dSugar),0);
        calcium =  Math.max(Math.min( MAX_CALCIUM, calcium+dCalcium),0);
    }

    @Override
    public void init(long clock) {
        salt = rng.nextDouble() * MAX_SALT;
        sugar = rng.nextDouble() * MAX_SUGAR;
        calcium = rng.nextDouble() * MAX_CALCIUM;
    }

    @Override
    public void endSimulation(long clock) {
        System.out.println("The bactery died..");
    }

    public double getSalt() {
        return salt;
    }

    public double getSugar() {
        return sugar;
    }

    public double getCalcium() {
        return calcium;
    }
}
