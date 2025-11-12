
public class Line2D {

    private double m, n;

    public Line2D(double m, double n) {
        this.m = m;
        this.n = n;
    }

    public Line2D(double m, Point2D point) {
        if(point == null)
            return;
        
        // y=mx+n
        // n=y-mx
        
        this.m = m;
        n = point.getY() - m * point.getX();
    }

    public Line2D(Point2D point, double n) {
        if(point == null)
            return;

        // y=mx+n
        // m=(y-n)/x
        
        this.n = n;
        m = (point.getY() - n) / point.getX();

    }

    public Line2D(Line2D line) { // Copy constructor
        this.m = line.getM();
        this.n = line.getN();
    }

    public double getM() {
        return m;
    }

    public double getN() {
        return n;
    }

    public String toString() {
        return "y = " + m + "x + " + n;
    }

    public boolean isParallel(Line2D other) {
        return m == other.getM();
    }

    public Point2D intersection(Line2D other) {
        if(isParallel(other))
            return null;

        double x = (other.getN() - n) / (m - other.getM());
        return new Point2D(x, m * x + n);
    }

}
