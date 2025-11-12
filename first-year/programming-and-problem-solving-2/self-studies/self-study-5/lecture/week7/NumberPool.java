package week7;

import week7.utils.RandomSource;

import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Random;

public class NumberPool {

    RandomSource rng = new RandomSource();
    ArrayList<Digits> candidates;

    public void init(int digitCount) {
        candidates = new ArrayList<>();

        int min = (int) Math.pow(10,digitCount-1);
        int max = (int) Math.pow(10,digitCount)-1;

        for (int n = min; n <=max ; n++) {
            Digits d = new Digits(n);
            if (MasterMindUtils.isValid(d,digitCount))
                candidates.add(d);
        }
    }

    public boolean isEmpty() {
        return candidates.isEmpty();
    }

    public Digits pickARandomNumber() {

        int i = rng.randInt(candidates.size());
        return candidates.get(i);
    }

    public int size() {
        return candidates.size();
    }

    public void update(Digits guess, ComparisonResult cr) {
        ArrayList<Digits> newList = new ArrayList<>();

        for (Digits d: candidates)
        {
            ComparisonResult answer = MasterMindUtils.compare(d,guess) ;
            if ( cr.isEqual(answer) )
                newList.add(d);
        }

        candidates = newList;
     }
}
