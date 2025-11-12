package week3.accessmodifiers.goodcase;

 public class Student {
     private int id;
     private int birthYear;
     private String firstName;
     private String lastName;
     private double gpa;

     public void setBirthYear(int birthYear) {
         this.birthYear = birthYear;
     }

     public int getBirthYear() {
         return birthYear;
     }

     public String getFirstName() {
         return firstName;
     }

     public String getLastName() {
         return lastName;
     }

     public double getGpa() {
         return gpa;
     }

     static int graduationECTS = 240;

   Student()
   {
       System.out.println("A student object is created");

   }

   Student(int stuNumber, int birthYear, String firstName, String lastName , double gpa )
   {
       System.out.println("A student object with values is created");

       this.id = stuNumber;
       this.firstName = firstName;
       this.lastName = lastName;
       this.birthYear = birthYear;
       this.gpa = gpa;

   }
     Student(int stuNumber, int birthYear, String firstName , double gpa )
     {
         System.out.println("A student object with values is created");

         this.id = stuNumber;
         this.firstName = firstName;

         this.birthYear = birthYear;
         this.gpa = gpa;

     }

   String introduce()
   {
       return  "[" + id + "] " + firstName + " " + lastName + " ("+ birthYear + ") GPA:"+ gpa;
   }

   static int getGraduationECTS()
   {
       return graduationECTS;
   }

   public int getStuNumber()
   {
       return id;
   }

   boolean isEqual( Student other)
   {
       return (id == other.id && firstName.equals( other.firstName) && lastName.equals(other.lastName)
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
        Student s = new Student(1,2001,"Ahmet","Celik",3.2);

        Student s3 = s;



        //System.out.println(s3.introduce());


        ///System.out.println(s.introduce());

        int a = 3;
        int b = 3;

        if (a == b)
            System.out.println("a is equal to b");
        else System.out.println("a and b are different");

        Student s1 = new Student(1,2000,"Ayşe","Celik",3.0);
        Student s4 = new Student(1,2000,"Ayşe","Celik",3.0);

        if (  s1 == s4)
            System.out.println("s1 is equal to s4");
        else System.out.println("s1 and s4 are different");

        System.out.println(s1);



    }
}
