#include "course.h"
#include "student.h"
#include "assignment.h"
#include "instructor.h"
#include <iostream>

using namespace std;

Course::Course(string name) : name(name) {}

string Course::get_name() {
    return name;
}

void Course::add_student(Student *student) {
    cout << "Enrolling student: " << student->get_id() << " in course: " << name << endl;
    enrolled_students.push_back(student);
}

void Course::add_assignment(Assignment *assignment) {
    cout << "Adding assignment: " << assignment->to_string() << " to course: " << name << endl;
    assignments.push_back(assignment);
}

void Course::print_assignments() {
    cout << "Assignments for Course: " << name << endl;
    for (int i=0; i < assignments.size(); i++) {
        cout << assignments[i]->to_string();
    }
}

vector<Assignment *> Course::get_assignments() {
    return assignments;
}

vector<Student *> Course::get_students() {
    return enrolled_students;
}