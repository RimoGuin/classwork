/*Write a program in Java to define a method taht returns an object. 
Define that mehod sutiability in the class*/
class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

class PersonFactory {
    public static Person createPerson(String name, int age) {
        return new Person(name, age);
    }
}

public class PersonMain {
    public static void main(String[] args) {
        Person person = PersonFactory.createPerson("Alice", 30);
        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());
    }
}
