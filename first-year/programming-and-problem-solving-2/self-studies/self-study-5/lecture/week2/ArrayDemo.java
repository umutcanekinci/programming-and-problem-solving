package week2;

import week1.Student;

import java.util.ArrayList;

class ArrayDemo {


    static void demo1()
    {
        int[] arr = new int[5];

        int [] arr2 = new int[] { 1,2,3};

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }

        Student[] sArr = new Student[3];

        sArr[0] = new Student();
        sArr[0].id = 2;
        sArr[0].name = "Ali";
        sArr[0].birthYear = 2000;
        sArr[0].gpa = 2.3;

        sArr[1] = new Student();
        sArr[1].id = 2;
        sArr[1].name = "Ali";
        sArr[1].birthYear = 2000;
        sArr[1].gpa = 2.3;

        sArr[2]= sArr[0];


        System.out.println(sArr[0]);


    }

    static void demoArrayExpansion()
    {
        int[] arr = new int[] {1,2,3};

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        int[] arr2 = new int[5];

        for (int i = 0; i < arr.length; i++) {
            arr2[i]= arr[i];
        }

        arr= arr2;
    }

    static void demoArrayList()
    {
        ArrayList<Student> list = new ArrayList<>();

        System.out.println(list.size());
        list.add(new Student(2,2000,"Sefa", 3.9));
        list.add(new Student(2,2000,"Sefa", 3.9));
        list.add(new Student(2,2000,"Sefa", 3.9));

        System.out.println(list.size());

        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));

        }

    }

    public static void main(String[] args) {

            demoArrayList();
    }
}
