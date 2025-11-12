package week2;



import week1.Student;

import java.util.ArrayList;

class Classroom {

    ArrayList<Student> students;

    public Classroom() {
        students = new ArrayList<>();
    }

    void register(Student s)
    {
        students.add(s);
    }

    int count()
    {
        return students.size();
    }

    Student getStudent(int index)
    {
        return students.get(index);
    }


    public static void main(String[] args) {
        Classroom cr1 = new Classroom();

        System.out.println("Count:" + cr1.count());

        cr1.register(new Student(3, 2000 ,"Ali",2.0));

        System.out.println("Count:" + cr1.count());

        System.out.println(cr1.getStudent(0));

        // !Out of bounds error!
        System.out.println(cr1.getStudent(5));
    }
}
