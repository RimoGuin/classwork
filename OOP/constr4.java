/**
 * Write a program that contains as a data members 
 * of a class a method that returns objects
 */

class Student {
    private int studentId;
    private String studentName;

    public Student(int id, String name) {
        studentId = id;
        studentName = name;
    }

    public int getStudentId() {
        return studentId;
    }

    public String getStudentName() {
        return studentName;
    }
}

public class constr4 {

    public static Student createStudent(int id, String name) {
        Student student = new Student(id, name);
        return student;
    }

    public static void main(String[] args) {
        Student student1 = createStudent(1, "Alice");
        System.out.println("Student 1 - ID: " + student1.getStudentId() + ", Name: " + student1.getStudentName());

        Student student2 = createStudent(2, "Bob");
        System.out.println("Student 2 - ID: " + student2.getStudentId() + ", Name: " + student2.getStudentName());
    }
}
