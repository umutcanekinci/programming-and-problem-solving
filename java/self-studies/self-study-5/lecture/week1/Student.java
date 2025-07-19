package week1;

public class Student {
    public int id;
    public int birthYear;
    public String name;
    public double gpa;


   static int graduationECTS = 240;

   public Student()
   {
       System.out.println("A student object is created");

   }

   public Student(int id, int birthYear,String name, double gpa )
   {
       System.out.println("A student object with values is created");

       this.id = id;
       this.name = name;
       this.birthYear = birthYear;
       this.gpa = gpa;

   }

   String introduce()
   {
       return  "[" + id + "] " + name + " ("+ birthYear + ") GPA:"+ gpa;
   }

   static int getGraduationECTS()
   {
       return graduationECTS;
   }

   boolean isEqual( Student other)
   {
       return (id == other.id  && name.equals( other.name)
               && birthYear ==other.birthYear && gpa == other.gpa);

   }

   public String toString()
   {
       return introduce();
   }

    public static void main(String[] args) {

        System.out.println("Graduation ECTS:" + Student.getGraduationECTS());

        int x = 5;
        System.out.println("Hello");
        System.out.println(x);

        Student s2 = new Student();
        Student s = new Student(1,2001,"Ahmet",3.2);

        Student s3 = s;

        s.name = "Ali";

        s3.name = "Şeyma";

        //System.out.println(s3.introduce());


        ///System.out.println(s.introduce());

        int a = 3;
        int b = 3;

        if (a == b)
            System.out.println("a is equal to b");
        else System.out.println("a and b are different");

        Student s1 = new Student(1,2000,"Ayşe",3.0);
        Student s4 = new Student(1,2000,"Ayşe",3.0);

        if (  s1 == s4)
            System.out.println("s1 is equal to s4");
        else System.out.println("s1 and s4 are different");

        System.out.println(s1);



    }
}
