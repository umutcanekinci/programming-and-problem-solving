public class Math {
    private Math() {}
    
    public static double pow(double number, double power) {
        if(power == 0)
            return 1;

        return number * pow(number, power-1);
    }

    public static double abs(double number) {
        return number > 0 ? number : -number;
    }

    public static double sqrt(double x) {
        double result = x;
        double epsilon = 0.000001;
        while(abs(result*result - x) > epsilon) 
            result = (result + x/result) / 2;
        return result;
    }

    public static double distance(double deltaX, double deltaY) {
        return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    }
}
