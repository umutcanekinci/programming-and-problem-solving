public class Point2D {

    private double x, y;

    Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    Point2D(Point2D point) {
        this.x = point.getX();
        this.y = point.getY();
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public String toString() {
        return "[" + x + ", " + y + "]";
    }

    public double distanceTo(Point2D other) {
        return Math.distance(x - other.getX(), y - other.getY());
    }

    public double distanceTo(Line2D line) {
        if (line.getM() == Double.POSITIVE_INFINITY || line.getM() == Double.NEGATIVE_INFINITY) {
            return Math.abs(x - line.getN());
        }

        // The shortest distance can be calculated by getting the distance to the point which is on the perpendicular line and other line.
        // So, let's create a line perpendicular to the given line and passing through the point
        // perpendicular tangent * tangent = -1
        // perpendicular tangent = -1/m
        double tangent = -1 / line.getM();

        // perpendicular line: y = (-1/m)x + n
        // this point should be on the perpendicular line
        // this.y = -this.x/m + n
        // n = this.y + this.x / m
        
        Line2D perpendicularLine = new Line2D(tangent, y + x / tangent);
        Point2D otherPoint = perpendicularLine.intersection(line);
        return distanceTo(otherPoint);
    }

}
