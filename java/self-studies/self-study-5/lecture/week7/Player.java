package week7;

public abstract class Player {

    protected final String name;

    protected int  digitCount;
    protected int  roundCount;

    public Player(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "["+ name+"]";
    }

    public void initGame(int roundCount, int digitCount) {
        this.digitCount = digitCount;
        this.roundCount = roundCount;
    }

    public void initRound(int round) {

    }

    public abstract int makeGuess();

    public void giveAnswer(Digits guess, ComparisonResult cr) {
    }

    public void winRound() {

    }

    public void congratulate() {

    }
}
