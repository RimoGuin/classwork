/**Write a program in Java to implement the concept of method overriding */

class Animal {
    void speak() {
        System.out.println("Animals don't speak");
    }
}

class Dog extends Animal {
    @Override
    void speak() {
        System.out.println("Woof!");
    }
}

class Cat extends Animal {
    @Override
    void speak() {
        System.out.println("Meow!");
    }
}

public class OverrideMain {
    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.speak();

        Dog dog = new Dog();
        dog.speak();

        Cat cat = new Cat();
        cat.speak();
    }
}

