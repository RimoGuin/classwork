/*Create a class Point for storing the coordinates of a geometrical point. 
Write static functions to calculate distance between two points. Write it in Java
*/

import java.lang.Math;

class Point {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public static double distance(Point p1, Point p2) {
        double deltaX = p2.x - p1.x;
        double deltaY = p2.y - p1.y;
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }
}

public class PointMain {
    public static void main(String[] args) {
        Point p1 = new Point(1.0, 2.0);
        Point p2 = new Point(4.0, 6.0);

        double distance = Point.distance(p1, p2);
        System.out.println("Distance between the points: " + distance);
    }
}
