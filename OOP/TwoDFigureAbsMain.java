/* Rewrite the 2DFigure program  using the concept of abstract class & abstract methods */

 abstract class TwoDFigure {
    double dimension1;
    double dimension2;

    TwoDFigure(double dimension1, double dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }

    // Abstract method for calculating the area
    abstract double calcArea();
}

class Rectangle extends TwoDFigure {
    Rectangle(double length, double width) {
        super(length, width);
    }

    @Override
    double calcArea() {
        return dimension1 * dimension2;
    }
}

class Triangle extends TwoDFigure {
    Triangle(double base, double height) {
        super(base, height);
    }

    @Override
    double calcArea() {
        return 0.5 * dimension1 * dimension2;
    }
}

public class TwoDFigureAbsMain {
    public static void main(String[] args) {
        TwoDFigure rectangle = new Rectangle(5.0, 4.0);
        TwoDFigure triangle = new Triangle(6.0, 3.0);

        double rectangleArea = rectangle.calcArea();
        double triangleArea = triangle.calcArea();

        System.out.println("Area of Rectangle: " + rectangleArea);
        System.out.println("Area of Triangle: " + triangleArea);
    }
}
