package week3.accessmodifiers.goodcase;



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


    void printAttendance()
    {
        for (int s = 0; s < students.size(); s++) {
            Student stu = students.get(s);
            System.out.println("["+ stu.getStuNumber() + "] " + stu.getFirstName() + " " + stu.getLastName());
        }
    }

    public static void main(String[] args) {
        Classroom cr1 = new Classroom();

        System.out.println("Count:" + cr1.count());

        cr1.register(new Student(3, 2000 ,"Ali",2.0));
        cr1.register(new Student(1, 2000 ,"Sefa",3.0));
        cr1.register(new Student(2, 2000 ,"Deniz",2.5));

        cr1.printAttendance();


    }
}
