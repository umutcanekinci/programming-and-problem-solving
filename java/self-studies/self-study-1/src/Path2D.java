import java.util.ArrayList;

public class Path2D extends ArrayList<Point2D> {

    Path2D() {
        super();
    }

    Path2D(Path2D other) {
        this();
        addAll(other);
    }

    public String toString() {
        StringBuilder str = new StringBuilder();

        for(int i = 0; i < size(); i++) {
            if(i != 0)
                str.append("===");

            str.append(get(i));
        }

        return str.toString();
    }

    public double length() {
        double result = 0;
        for(int i = 0; i < size() - 1; i++)
            result += get(i).distanceTo(get(i+1));

        return result;
    }

    public void addPoint(Point2D point) {
        if(point == null)
            return;

        add(point);
    }

    public Path2D combine(Path2D other) {
        Path2D concatenation = new Path2D(this);
        concatenation.addAll(other);
        return concatenation;
    }


}
