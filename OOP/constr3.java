/**
 * Demonstrate method overloading with a suitable example involving 
 * implicit type casting
 */

public class constr3 {

    public int add(int a, int b) {
        System.out.println("Adding integers");
        return a + b;
    }

    public double add(double a, int b) {
        System.out.println("Adding double and int");
        return a + b;
    }

    public double add(int a, double b) {
        System.out.println("Adding int and double");
        return a + b;
    }

    public double add(double a, double b) {
        System.out.println("Adding doubles");
        return a + b;
    }

    public static void main(String[] args) {
        constr3 example = new constr3();

        int intResult = example.add(5, 10);
        System.out.println("Result (int): " + intResult);

        double doubleResult1 = example.add(5.5, 10);
        System.out.println("Result (double 1): " + doubleResult1);

        double doubleResult2 = example.add(5, 10.5);
        System.out.println("Result (double 2): " + doubleResult2);

        double doubleResult3 = example.add(5.5, 10.5);
        System.out.println("Result (double 3): " + doubleResult3);
    }
}
