#include "student.h"
#include "course.h"
#include "assignment.h"
#include "submission.h"

Student::Student(string id) : id(id) {}

string Student::get_id() {
    return id;
}

void Student::enroll_course(Course *course) {
    enrolled_courses.push_back(course);
    course->add_student(this);
}

void Student::submit_assignment(Assignment *assignment) {
    assignment->add_submission(new Submission(id, "My submission"));
}

void Student::print_assignment() {
    for (int i=0; i < enrolled_courses.size(); i++)
        enrolled_courses[i]->print_assignments();
}

string Student::to_string() {
    return "ID: " + id;
}