/*Modify the program above (OverrideMain.java) to demonstrate the fact that in the event of
 inheritance involving super class and subclass methods with same name 
 but different type signatures are not overriden but actually overloaded
*/

class Animal {
    void speak(int i) {
        System.out.println("Animals don't speak " + i);
    }
}

class Dog extends Animal {
    void speak(String s) {
        System.out.println("Woof! " + s);
    }
}

class Cat extends Animal {
    void speak(double d) {
        System.out.println("Meow! " + d);
    }
}

public class OverrideMain2 {
    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.speak(10);

        Dog dog = new Dog();
        dog.speak("Hello");

        Cat cat = new Cat();
        cat.speak(1.23);
    }
}
