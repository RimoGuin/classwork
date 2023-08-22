/**Write a program in Java to create nested and inner classes */
class OuterClass {
    private int outerData = 10;

    // Nested class
    static class NestedClass {
        void display() {
            System.out.println("Nested class method");
        }
    }

    // Inner class
    class InnerClass {
        void display() {
            System.out.println("Inner class method, outerData: " + outerData);
        }
    }
}

public class NewClasses {
    public static void main(String[] args) {
        // Creating an instance of the nested class
        OuterClass.NestedClass nestedObj = new OuterClass.NestedClass();
        nestedObj.display();

        // Creating an instance of the outer class
        OuterClass outerObj = new OuterClass();
        // Creating an instance of the inner class using the outer class instance
        OuterClass.InnerClass innerObj = outerObj.new InnerClass();
        innerObj.display();
    }
}
