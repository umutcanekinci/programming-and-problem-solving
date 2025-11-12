package week11.barbershop;

import week11.barbershop.arrival.UniformArrivalGenerator;
import week11.barbershop.selection.FirstComeFirstCSP;
import week11.barbershop.selection.LongestIdleFirstBSP;
import week11.barbershop.visualizer.BarberShopVisualizer;
import week11.barbershop.visualizer.SimpleBarberShopVisualizer;
import week11.base.Simulator;
import week11.base.SystemVisualizer;
import week11.schedule.SimpleRegularSchedule;

public class BarberDemo {
    public static void main(String[] args) {
        BarberShop bs = new BarberShop( 10,
                                        new UniformArrivalGenerator(0.3),
                                        new FirstComeFirstCSP(),
                                        new LongestIdleFirstBSP()) ;

        bs.addBarber( new Barber( "Sefa", BarberSkill.Novice));
        bs.addBarber( new Barber( "Ayşe", BarberSkill.Moderate));
        bs.addBarber( new Barber("Can", BarberSkill.Expert));
        bs.addBarber( new Barber("Murat", BarberSkill.Expert));
        bs.addBarber( new Barber("Sevgi", BarberSkill.Expert));
        SystemVisualizer bsv= new BarberShopVisualizer();

        Simulator simulator = new Simulator( bs,
                                             bsv,
                                             new SimpleRegularSchedule(0,2000000,1),
                                             true,
                                            0);

        simulator.simulate();


    }
}
