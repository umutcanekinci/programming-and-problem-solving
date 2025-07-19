package week11.dummy;

import week11.base.Simulatable;
import week11.base.SystemVisualizer;
import week7.utils.ConsolUtils;

public class AdvancedBacteryVisualizer implements SystemVisualizer {

    private final static int HIGH_PERCENTAGE    = 80;
    private final static int LOW_PERCENTAGE     = 20;
    @Override
    public void visualize(Simulatable system) {
        if ( !( system instanceof SimpleBactery))
        {
            System.out.println("This system can not be visualized!");
        }
        else{
            SimpleBactery sb = (SimpleBactery) system;
            displayBactery(sb);
        }
    }

    private void displayBactery(SimpleBactery sb) {
        diplayHeader();
        displayContent(sb);
    }

    private void displayContent(SimpleBactery sb) {

        int saltRatio = (int) (100 * sb.getSalt()/SimpleBactery.MAX_SALT);
        int sugarRatio = (int) (100 * sb.getSugar()/SimpleBactery.MAX_SUGAR);
        int calciumRatio = (int) (100 * sb.getCalcium()/SimpleBactery.MAX_CALCIUM);

        String stSalt = ConsolUtils.colorize(String.format("%.2f", sb.getSalt()), (saltRatio> HIGH_PERCENTAGE || saltRatio<LOW_PERCENTAGE ?  ConsolUtils.ANSI_RED :ConsolUtils.ANSI_WHITE ) );
        String stSugar = ConsolUtils.colorize(String.format("%.2f", sb.getSugar()), (sugarRatio> HIGH_PERCENTAGE || sugarRatio<LOW_PERCENTAGE ?  ConsolUtils.ANSI_RED :ConsolUtils.ANSI_WHITE ) );
        String stCalcium = ConsolUtils.colorize(String.format("%.2f", sb.getCalcium()), (calciumRatio> HIGH_PERCENTAGE || calciumRatio<LOW_PERCENTAGE ?  ConsolUtils.ANSI_RED :ConsolUtils.ANSI_WHITE ) );

        System.out.printf("%20s : %s \n", ConsolUtils.colorize("Salt",ConsolUtils.ANSI_YELLOW), stSalt );
        System.out.printf("%20s : %s \n", ConsolUtils.colorize("Sugar",ConsolUtils.ANSI_YELLOW), stSugar);
        System.out.printf("%20s : %s \n", ConsolUtils.colorize("Calcium",ConsolUtils.ANSI_YELLOW), stCalcium);
    }

    private void diplayHeader() {
        System.out.println();
        System.out.println();
        System.out.println(ConsolUtils.colorize("Simple Bactery",ConsolUtils.ANSI_CYAN));
        System.out.println(ConsolUtils.colorize("-----------------------------", ConsolUtils.ANSI_CYAN));

    }
}
