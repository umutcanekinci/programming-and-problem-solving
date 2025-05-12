public class Demo {

    public static void main(String[] args) {

        Point2D point1 = new Point2D(1.0, 2.0);
        System.out.println("point1: " + point1);

        Point2D point2 = new Point2D(-2, 6);
        System.out.println("point2: " + point2);
        System.out.println("Distance between point1 and point2: " + point1.distanceTo(point2));

        Line2D line1 = new Line2D(2, 3);
        System.out.println("line1: " + line1);

        System.out.println("Distance between point1 and line1: " + point1.distanceTo(line1));
        System.out.println("Distance between point2 and line1: " + point2.distanceTo(line1));
      
        Line2D line2 = new Line2D(2, 5);
        System.out.println("line2: " + line2);

        System.out.println("Line1 is parallel to line2: " + line1.isParallel(line2));
        System.out.println("Intersection between line1 and line2: " + line1.intersection(line2));

        Line2D line3 = new Line2D(1, 3);
        System.out.println("line3: " + line3);

        System.out.println("Line1 is parallel to line3: " + line1.isParallel(line3));
        System.out.println("Intersection between line1 and line3: " + line1.intersection(line3));

        Line2D line4 = new Line2D(Double.POSITIVE_INFINITY, 5);
        System.out.println("line4: " + line4);

        System.out.println("Distance between point1 and line4: " + point1.distanceTo(line4));

        Path2D path1 = new Path2D();
        path1.addPoint(point1);
        path1.addPoint(point2);
        System.out.println("path1: " + path1);

        Path2D path2 = new Path2D();
        path2.addPoint(point2);
        path2.addPoint(point1);
        System.out.println("path2: " + path2);

        System.out.println("Size of path1: " + path1.size());
        System.out.println("Size of path2: " + path2.size());

        System.out.println("Length of path1: " + path1.length());
        System.out.println("Length of path2: " + path2.length());

        Path2D path3 = path1.combine(path2);
        System.out.println("path3: " + path3);

    }

}
