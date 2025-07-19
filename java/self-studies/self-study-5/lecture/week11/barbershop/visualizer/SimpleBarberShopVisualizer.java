package week11.barbershop.visualizer;

import week11.barbershop.Barber;
import week11.barbershop.BarberJob;
import week11.barbershop.BarberShop;
import week11.base.Simulatable;
import week11.base.SystemVisualizer;

import java.util.List;

public class SimpleBarberShopVisualizer implements SystemVisualizer {
    @Override
    public void visualize(Simulatable system) {
        BarberShop bs = (BarberShop) system;

        displayBarbers(bs.getBarbers());
        System.out.println("---------------------------------------------------------");
        displayStats(bs);
    }

    private void displayStats(BarberShop bs) {
        System.out.println("    Total Customer Count : "+ bs.getTCC());
        System.out.println(" Rejected Customer Count : " + bs.getRCC());
        System.out.println("             Total Money : " + bs.getTM());
        System.out.println("       Average Wait Time : " + bs.getAWT());
    }

    private void displayBarbers(List<Barber> barbers) {
        for (Barber b: barbers)
            displayBarber(b);
    }

    private void displayBarber(Barber b) {
        System.out.println( b.getName()+ "  " +
                            b.getSkill() + " " +
                            b.getState() + " " +
                            " SCC: "+b.getSCC() + "  "+
                            " TM:" + b.getTM());
    }
}
