/*Create a class 2DFigure that contains data members to represent dimensions
 * & a method calc_area to calculate the corresponding area. Derive two classes
 * rectangle & triangle from 2DFigure and calculate the corresponding areas.
 */

class TwoDFigure {
    double length;
    double width;

    TwoDFigure(double length, double width) {
        this.length = length;
        this.width = width;
    }

    double calcArea() {
        return 0.0; // Default implementation, to be overridden by subclasses
    }
}

class Rectangle extends TwoDFigure {
    Rectangle(double length, double width) {
        super(length, width);
    }

    @Override
    double calcArea() {
        return length * width;
    }
}

class Triangle extends TwoDFigure {
    double base;
    double height; 

    Triangle(double base, double height) {
        super(base, height);
        this.base = base;
        this.height = height;
    }

    @Override
    double calcArea() {
        return 0.5 * base * height;
    }
}

public class FigureMain {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(5.0, 4.0);
        Triangle triangle = new Triangle(6.0, 3.0);

        double rectangleArea = rectangle.calcArea();
        double triangleArea = triangle.calcArea();

        System.out.println("Area of Rectangle: " + rectangleArea);
        System.out.println("Area of Triangle: " + triangleArea);
    }
}
