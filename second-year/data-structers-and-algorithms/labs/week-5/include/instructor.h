#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>

using namespace std;

class Course;
class Assignment;

class Instructor {
private:
    string name, surname, academic_title;
    vector<Course *> courses;
    string mail, fullname;
public:
    Instructor(string name, string surname, string academic_title);
    Course *create_course(string course_name);
    Assignment *create_assignment(string title, string instructions, Course &course);
    void print_student_list();
    void print_assignments();
    void view_submissions();
};

#endif