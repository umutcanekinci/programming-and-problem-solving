package week11.barbershop;

public enum BarberSkill {
    Novice(1.5), Moderate(1.0), Expert(0.5);

    private final double toTimeCoefficient;

    BarberSkill(double toTimeCoefficient) {
        this.toTimeCoefficient = toTimeCoefficient;
    }

    double toTimeCoefficient()
    {
        return toTimeCoefficient;
    }
}
