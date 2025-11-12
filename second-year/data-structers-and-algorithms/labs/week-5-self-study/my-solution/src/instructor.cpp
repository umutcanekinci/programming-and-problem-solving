#include "instructor.h"
#include "course.h"
#include "assignment.h"
#include "student.h"
#include <iostream>

using namespace std;

Instructor::Instructor(string name, string surname, string academic_title) {
    this->name = name;
    this->surname = surname;
    this->academic_title = academic_title;
    this->mail = name + "." + surname + "@yasar.edu.tr";
    this->fullname = academic_title + " " + name + " " + surname;
}

Course *Instructor::create_course(string course_name) {
    cout << "Creating course: " << course_name << endl;
    Course *course = new Course(course_name);
    courses.push_back(course);
    return course;
}

Assignment *Instructor::create_assignment(string title, string instructions, Course &course) {
    cout << "Creating assignment: " << title << " for course: " << course.get_name() << endl;
    Assignment *assignment = new Assignment(title, instructions);
    course.add_assignment(assignment);
    return assignment;
}

void Instructor::print_student_list() {
    cout << "Student List:" << endl;
    for (int i=0; i < courses.size(); i++) {
        vector<Student *> students = courses[i]->get_students();

        for (int j = 0; j < students.size(); j++)
            cout << students[j]->to_string() << endl;   
    }
}

void Instructor::print_assignments() {
    cout << "Assignments List for Instructor: " << fullname << endl;
    for (int i=0; i < courses.size(); i++) {
        courses[i]->print_assignments();
    }
}

void Instructor::view_submissions() {
    cout << "Viewing Submissions for Instructor: " << fullname << endl;
    for (int i=0; i < courses.size(); i++) {
        cout << "Course: " << courses[i]->get_name() << endl;
        vector<Assignment *> assignments = courses[i]->get_assignments();

        for (int j = 0; j < assignments.size(); j++)
            assignments[j]->print_submission();   
    }
}