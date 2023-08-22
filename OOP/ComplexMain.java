/**create a class Complex for storing the real and imaginary parts of a complex number. 
 * The class should have static members to store the numbers of complex numbers created and display it. 
 * Write functions(static and non static as required) to calculate 1) sum, difference and products of two complex numbers, 2) modulus and component of a complex number. Define required constructors and destructors of the class. 
 * Implement the class by a main function.
 */

class Complex {
    private double real;
    private double imaginary;
    private static int count = 0;

    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
        count++;
    }

    public static int getComplexCount() {
        return count;
    }

    public static Complex add(Complex c1, Complex c2) {
        return new Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
    }

    public static Complex subtract(Complex c1, Complex c2) {
        return new Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
    }

    public static Complex multiply(Complex c1, Complex c2) {
        double realPart = c1.real * c2.real - c1.imaginary * c2.imaginary;
        double imaginaryPart = c1.real * c2.imaginary + c1.imaginary * c2.real;
        return new Complex(realPart, imaginaryPart);
    }

    public double modulus() {
        return Math.sqrt(real * real + imaginary * imaginary);
    }

    public double getReal() {
        return real;
    }

    public double getImaginary() {
        return imaginary;
    }
}

public class ComplexMain {
    public static void main(String[] args) {
        Complex c1 = new Complex(3.0, 4.0);
        Complex c2 = new Complex(1.0, 2.0);

        Complex sum = Complex.add(c1, c2);
        Complex difference = Complex.subtract(c1, c2);
        Complex product = Complex.multiply(c1, c2);

        System.out.println("Number of complex numbers created: " + Complex.getComplexCount());
        System.out.println("Sum: " + sum.getReal() + " + " + sum.getImaginary() + "i");
        System.out.println("Difference: " + difference.getReal() + " + " + difference.getImaginary() + "i");
        System.out.println("Product: " + product.getReal() + " + " + product.getImaginary() + "i");

        System.out.println("Modulus of c1: " + c1.modulus());
    }
}
    