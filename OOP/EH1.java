/* WAP in Java to implement exception handling using try-catch block. The code inside the try block should throw atleast 3 different exceptions
 * which should be caught using individual catch clauses.
 */
public class EH1 {
    public static void main(String args[]) {
        try{
            int[] arr = new int[10];
            arr[10] = 100; //ArrayIndexOutOfBoundsException
            
            int a = 10, b = 0;
            int c = a / b; //ArithmeticException

            String str = "abc";
            int x = Integer.parseInt(str); //NumberFormalException

        } catch (ArrayIndexOutOfBoundsException e) { 
            System.out.println("ArrayIndexOutOfBoundsException caught: " + e); 
        } catch (ArithmeticException e) { 
            System.out.println("ArithmeticException caught: " + e); 
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException caught: " + e);
        }
    }
}