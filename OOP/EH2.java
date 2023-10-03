/* WAP in Java to implement exception handling using nested try block. In order to do that the code must throw atleast two different exceptions. */
public class EH2 {
    public static void main(String args[]) {
        try {
            int a = args.length;

            /*If no command-line args given then 
            * divide-by-zero exception
            */
            int b = 42 / a;

            System.out.println("a = " + a);
            try { // nested try block
                if(a == 1) a = a / (a - a);

                if(a == 2) {
                    int c[] = {1};
                    c[42] = 99;
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Aray index out-of-bounds: " + e);
            }
        } catch (ArithmeticException e) {
            System.out.println("Divide by 0: " + e);
        }
    }
}
