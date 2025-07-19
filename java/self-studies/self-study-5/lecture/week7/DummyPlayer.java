package week7;

public class DummyPlayer extends AIPlayer{

    public DummyPlayer(String name) {
        super(name);
    }

    @Override
    public int makeGuess() {
        return MasterMindUtils.randomNumber(digitCount).toInt();
    }


}
