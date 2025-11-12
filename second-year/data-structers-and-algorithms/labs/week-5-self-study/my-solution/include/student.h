#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Course;
class Assignment;

class Student {
private:
    string id;
    vector<Course *> enrolled_courses;
public:
    Student(string id);
    string get_id();
    void enroll_course(Course *course);
    void submit_assignment(Assignment *assignment);
    void print_assignment();
    string to_string();
};

#endif