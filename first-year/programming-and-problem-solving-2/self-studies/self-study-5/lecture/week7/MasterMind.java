package week7;

import week7.utils.ConsolUtils;

import java.util.ArrayList;

public class MasterMind {

    int digitCount;
    Digits secretNumber;

    ArrayList<Player> players;
    int currentPlayer;
    int roundStarter;

    int[] scores;
    private boolean roundIsOver;


    public MasterMind() {
        players = new ArrayList<>();
    }

    void play(int roundCount, int digitCount)
    {
        initGame(roundCount, digitCount);

        for (int round = 1; round <= roundCount; round++) {
            playOneRound(round);
        }

        endGame();

    }

    private void playOneRound(int round) {
        initRound(round);

        do
        {
            playOneTurn();
        }
        while (!roundIsOver);

        endRound(round);
    }

    private void endRound(int round) {
        System.out.println(ConsolUtils.colorize("Round-"+ round+ " is over!" , ConsolUtils.ANSI_BLUE));

        printScores();

    }

    private void playOneTurn() {
        Player current = players.get(currentPlayer);

        System.out.println( current + " is making a guess:" );

        int guess =  current.makeGuess();
        Digits dGuess = new Digits(guess);

        if (!MasterMindUtils.isValid(dGuess,digitCount))
        {
            System.out.println(ConsolUtils.colorize("INVALID GUESS!", ConsolUtils.ANSI_RED));
            currentPlayer = (currentPlayer+1)%players.size();
            return;
        }

        answerGuess(dGuess);
        currentPlayer = (currentPlayer+1)%players.size();
    }

    private void answerGuess(Digits guess) {
        Player current = players.get(currentPlayer);

        ComparisonResult cr = MasterMindUtils.compare(guess,secretNumber);

        System.out.println(guess +  " " + cr);

        for (Player p:players)
            p.giveAnswer(guess,cr);

        if (cr.getPlus() == digitCount)
        {
            current.winRound();
            scores[currentPlayer]++;
            roundIsOver = true;
            System.out.println(ConsolUtils.colorize(current + "won the round!",ConsolUtils.ANSI_BLUE ));
        }
    }

    private void initRound(int round) {
        System.out.println(ConsolUtils.colorize("Round-"+ round+ " started!",ConsolUtils.ANSI_BLUE) );

        for (Player p:players)
        {
            p.initRound(round);
        }

        pickASecretNumber();

        currentPlayer = roundStarter;
        roundStarter = (roundStarter+1)%players.size();

        roundIsOver = false;
    }

    private void pickASecretNumber() {
        secretNumber = MasterMindUtils.randomNumber(digitCount);
    }

    private void endGame() {

        printScores();
        congratulateWinner();

        System.out.println(
                ConsolUtils.colorize( "Thank you for playing Master Mind game!",ConsolUtils.ANSI_BLUE));

    }

    private void congratulateWinner() {
        int winner =0;

        for (int p = 1; p < players.size(); p++) {
            if (scores[p]>scores[winner])
                winner = p;
        }

        System.out.println(players.get(winner) + " won the game with score "+ scores[winner]);
        players.get(winner).congratulate();
    }

    private void printScores() {
        System.out.println(ConsolUtils.colorize("Scores:",ConsolUtils.ANSI_YELLOW));
        System.out.println(ConsolUtils.colorize("--------------------------------",ConsolUtils.ANSI_YELLOW));

        for (int p = 0; p < players.size(); p++) {
            System.out.printf("%20s %5d \n" , players.get(p) , scores[p] );
        }
    }

    private void initGame(int roundCount, int digitCount) {
        ConsolUtils.clearScreen();
        System.out.println(
                ConsolUtils.colorize( roundCount + " rounds of "+ digitCount+"-digits Master Mind game started",ConsolUtils.ANSI_BLUE));

        for ( Player p: players)
        {
            p.initGame(roundCount,digitCount);
        }

        this.digitCount = digitCount;
        scores =  new int[players.size()];
        roundStarter=0;
    }



    void addPlayer(Player p)
    {
        players.add(p);
    }


    public static void main(String[] args) {
        Player p = new DummyPlayer("Dummy");
        Player s = new SmartPlayer("Smarty");

        MasterMind mm = new MasterMind();

        mm.addPlayer(p);
        mm.addPlayer(s);

        mm.play(100,4);

    }

}
