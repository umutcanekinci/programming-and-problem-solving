package week11.dummy;

import week11.base.Simulatable;
import week11.base.SystemVisualizer;
import week7.utils.ConsolUtils;

public class BacteryVisualizer implements SystemVisualizer {
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
        System.out.printf("%20s : %.2f \n", ConsolUtils.colorize("Salt",ConsolUtils.ANSI_YELLOW), sb.getSalt());
        System.out.printf("%20s : %.2f \n", ConsolUtils.colorize("Sugar",ConsolUtils.ANSI_YELLOW), sb.getSugar());
        System.out.printf("%20s : %.2f \n", ConsolUtils.colorize("Calcium",ConsolUtils.ANSI_YELLOW), sb.getCalcium());
    }

    private void diplayHeader() {
        System.out.println();
        System.out.println();
        System.out.println(ConsolUtils.colorize("Simple Bactery",ConsolUtils.ANSI_CYAN));
        System.out.println(ConsolUtils.colorize("-----------------------------", ConsolUtils.ANSI_CYAN));

    }
}
