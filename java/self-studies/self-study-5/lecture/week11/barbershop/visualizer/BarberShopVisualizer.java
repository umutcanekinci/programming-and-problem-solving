package week11.barbershop.visualizer;


import week11.barbershop.Barber;
import week11.barbershop.BarberShop;
import week11.barbershop.BarberState;
import week11.base.Simulatable;
import week11.base.SystemVisualizer;
import week11.utils.Color;
import week11.utils.ConsolUtils;

public class BarberShopVisualizer implements SystemVisualizer {

    private static final String SMILEY = "\ud83d\udc7e";
    private static final Color C_HEADER = Color.BLUE_BRIGHT;
    private static final Color C_HEADER_TEXT = Color.YELLOW_BOLD_BRIGHT;
    private static final Color C_CLOCK = Color.WHITE_BOLD;
    private static final String HEADER = "BARBER SHOP SIMULATION";
    private static final int PROGRESS_WIDTH = 30;
    private final int WIDTH= 80;

    private final StringAligner aligner = new StringAligner();

    BarberShop bs;

    private void drawHLine(Color color)
    {
        String st ="+";
        for (int i = 0; i < WIDTH; i++) {
            st+="-";
        }
        st += "+";

        ConsolUtils.println(st,color);
    }


    private String lineOf(char c, int count)
    {
        StringBuilder sb= new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(c);
        }
        return sb.toString();
    }

    @Override
    public void visualize( Simulatable system) {

        ConsolUtils.clearScreen();

        bs = (BarberShop) system;

        drawHeader();
        drawBarbers();
        drawWaiters();
        printStats();
    }

    private void printStats() {
        skipLine();

        printTotalMoney();
        printCustomerCount();
        printAverageWaitTime();
        printRejectedCustomerCount();
        skipLine();
        drawHLine(C_HEADER);


    }

    private void printStat(String statName, String statVal, Color color)
    {
        ConsolUtils.print("|",C_HEADER);

        ConsolUtils.print(aligner.rAligned(statName + ": ", 40),Color.WHITE);
        ConsolUtils.print(aligner.lAligned(statVal + "", 20),color);

        ConsolUtils.println(aligner.indented("|", WIDTH - 60),C_HEADER);
    }

    private void printTotalMoney() {
        printStat("Total Money",bs.getTM()+" TL",Color.YELLOW);
    }



    private void printCustomerCount() {
        printStat("Served Customer Count",bs.getTCC()+"",Color.WHITE);
    }

    private void printAverageWaitTime()
    {
        double averageWaitingTime = bs.getAWT();
        printStat("Average Waiting Time",String.format("%.1f",averageWaitingTime),Color.WHITE);
    }

    private void printRejectedCustomerCount() {
        printStat("Rejected Customer Count",bs.getRCC()+"",Color.WHITE);
    }


    private void drawWaiters() {
        skipLine();
        int max = bs.getCapacity()*2;
        int current = bs.getCustomers().size();
        ConsolUtils.print("|",C_HEADER);

        ConsolUtils.print(" WAITERS: [",Color.WHITE);
        for (int i = 0; i < current; i++) {
            ConsolUtils.print("@ ",Color.RED_BRIGHT);
        }
        if (max>2*current)
            ConsolUtils.print(aligner.indented("", max - 2 * current),Color.WHITE);
        ConsolUtils.print("]",Color.WHITE);
        ConsolUtils.println(aligner.indented("|", WIDTH - max - 12),C_HEADER);

        skipLine();
        drawHLine(C_HEADER);
    }

    private void drawBarbers() {
        skipLine();
        for(Barber b:bs.getBarbers())
        {
            drawBarber(bs.getClock(),b);
        }
        drawHLine(C_HEADER);
    }

    private void skipLine() {
        ConsolUtils.println(String.format("|%"+WIDTH+"s|",""),C_HEADER);
    }

    private void drawBarber(long clock, Barber b) {
        int lineWidth=0;
        ConsolUtils.print("|",C_HEADER);
        ConsolUtils.print(aligner.rAligned(b.getName() + ": ", 10),Color.WHITE);
        ConsolUtils.print(aligner.lAligned("SCC:" + b.getSCC(), 10),Color.WHITE);
        ConsolUtils.print(aligner.lAligned(b.getState().toString(), 8),Color.WHITE);
        lineWidth = 28;
        if (b.getState()== BarberState.Busy)
        {
            ConsolUtils.print(aligner.rAligned(b.getCustomer().getJob().toString() + " ", 15),Color.WHITE);
            drawProgress(clock,b);
            lineWidth += PROGRESS_WIDTH+21;
        }
        ConsolUtils.println(aligner.rAligned("|", WIDTH - lineWidth + 1),C_HEADER);
    }

    private void drawProgress(long clock, Barber b) {
        int max = PROGRESS_WIDTH;
        int duration = (int) b.serviceTime();
        int current = (int) ((clock-b.getLastStateChangeTime())*max/(duration));
        int percent = current*100/max;
        ConsolUtils.print("[",Color.WHITE);
        ConsolUtils.print(lineOf('=',current),Color.GREEN_BRIGHT);
        ConsolUtils.print(lineOf('-',max-current),Color.WHITE);
        ConsolUtils.print(String.format("]%%%3d",percent),Color.WHITE);
    }

    private void drawHeader() {
        drawHLine(C_HEADER);
        String stClock = String.format("CLOCK: %-10d",bs.getClock());
        ConsolUtils.print("|", C_HEADER);
        ConsolUtils.print(stClock,C_CLOCK);
        ConsolUtils.print(aligner.indented(HEADER, (WIDTH - HEADER.length()) / 2 - stClock.length(), (WIDTH - HEADER.length()) / 2),C_HEADER_TEXT);
        ConsolUtils.println("|", C_HEADER);
        drawHLine(C_HEADER);
    }


}
