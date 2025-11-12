#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

using namespace std;

class Student;
class Assignment;

class Course {
private:
    string name;
    vector<Student *> enrolled_students;
    vector<Assignment *> assignments;
public:
    Course(string name);
    string get_name();
    void add_student(Student *student);
    void add_assignment(Assignment *assignment);
    void print_assignments();
    vector<Assignment *> get_assignments();
    vector<Student *> get_students();
};

#endif