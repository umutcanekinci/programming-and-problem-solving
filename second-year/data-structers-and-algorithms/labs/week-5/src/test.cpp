#include "assignment.h"
#include "course.h"
#include "instructor.h"
#include "student.h"
#include "submission.h"


#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{        
    Instructor* instructor = new Instructor("Dindar", "Öz", "Assist.Prof.");
    Student* alice = new Student("2021001");
    
    Course * cs101 = instructor->create_course("CS101 Introduction to Computer Science");
    
    cout << "----------------------------------------" << endl;
    
    Assignment *hw1 = instructor->create_assignment("HW1", "Solve the problems.", *cs101);
    
    alice->enroll_course(cs101);

    cout << "----------------------------------------" << endl;

    alice->submit_assignment(hw1);

    cout << "----------------------------------------" << endl;

    instructor->view_submissions();

    cout << "----------------------------------------" << endl;

    instructor->print_student_list();

    cout << "----------------------------------------" << endl;

    delete instructor;
    delete hw1;
    delete cs101;
    delete alice;
    return 0;
}
