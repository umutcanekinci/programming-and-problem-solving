package week7;

import com.sun.deploy.cache.Cache;
import week7.utils.ConsolUtils;

public class SmartPlayer extends AIPlayer{

    private final static String XQR = " / ___  ___ \\\n" +
                                            "/ / @ \\/ @ \\ \\\n" +
                    "\\ \\___/\\___/ /\\\n" +
            " \\____\\/____/||\n" +
                                    " /     /\\\\\\\\\\//\n" +
            "|     |\\\\\\\\\\\\\n" +
                    " \\      \\\\\\\\\\\\\n" +
                                    "   \\______/\\\\\\\\\n" +
            "    _||_||_";
    private NumberPool pool;

    @Override
    public void congratulate() {
        System.out.println(ConsolUtils.colorize(XQR,ConsolUtils.ANSI_YELLOW));
    }

    public SmartPlayer(String name) {
        super(name);
    }

    @Override
    public int makeGuess() {

        if (pool.isEmpty())
        {
            System.out.println("No possible answer!");
            return 0;
        }

        Digits d = pool.pickARandomNumber();

        return d.toInt();
    }

    @Override
    public void giveAnswer(Digits guess, ComparisonResult cr) {
        pool.update(guess,cr);

        int count = pool.size();
        System.out.println("I have current " + count +" number in my pool!");
    }

    @Override
    public void initRound(int round) {
        pool.init(digitCount);
    }


    @Override
    public void initGame(int roundCount, int digitCount) {
        super.initGame(roundCount, digitCount);
        pool = new NumberPool();
    }
}
