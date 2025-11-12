#include "Instructor.cpp"


int main() {
    Instructor *instructor = new Instructor("Umut", "Avcı", "Assist. Prof", 2);
    Student *s1 = new Student("1", 2);
    Student *s2 = new Student("2", 5);
    Student *s3 = new Student("3", 7);
    Student *s4 = new Student("4", 1);
    instructor->createCourse("SE2310", 5, 2);
    instructor->createCourse("ECON3300", 2, 0);

    instructor->enrollStudent(0,s1);
    instructor->enrollStudent(0,s2);
    instructor->enrollStudent(0,s3);
    instructor->enrollStudent(0,s4);
    instructor->enrollStudent(1,s3);
    instructor->printStudentList();
    s3->printCourses();


    instructor->createAssignment(0,"Homework 1","Lorem ipsum dolar sit amet");
    instructor->printAssignments();
    Course *firstCourse = instructor->getCourseByIndex(0);

    s3->submitAssignment(firstCourse,0,"Solution");
    instructor->viewSubmissions();
    free(instructor);

    return 0;
}