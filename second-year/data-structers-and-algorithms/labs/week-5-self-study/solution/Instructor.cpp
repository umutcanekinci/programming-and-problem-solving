#include <iostream>
#include "Course.cpp"
#include "Student.cpp"


using namespace std;

class Instructor {
private:
    string name;
    string surname;
    string academicTitle;
    // ArrayList does not have a default constructor (with empty parameter and body) to prevent null allocation
    // Therefore it can not be initiated by compiler as it is forced by C++ so we use pointer based declaration
    ArrayList<Course> *instructorCourses;
public:

    Instructor(string name, string surname, string academicTitle, int courseCount) {
        this->name = name;
        this->surname = surname;
        this->academicTitle = academicTitle;
        this->instructorCourses = new ArrayList<Course>(courseCount);
    }

    void enrollStudent(int courseIndex, Student *student) {
        Course *course = instructorCourses->getByIndex(courseIndex);
        if (course != NULL) {
            student->enrollCourse(course);
            course->addStudent(student);
        } else {
            cout << "Course does not exist : " << course->getName() << endl;
        }

    }


    void createCourse(string name, int studentCount, int assignmentCount) {
        Course *course = new Course(name, studentCount, assignmentCount);
        if (instructorCourses->getByObject(course) == NULL) {
            instructorCourses->add(course);
        } else {
            cout << "Course already exist : " << course->getName() << endl;
        }
    }

    bool createAssignment(int courseIndex, string title, string instructions) {
        bool added = false;
        Course *existingCourse = instructorCourses->getByIndex(courseIndex);
        if (existingCourse != NULL) {
            Assignment *assignment = new Assignment(title, instructions, existingCourse->getStudents()->size());
            existingCourse->addAssignment(assignment);
        } else {
            cout << "Course does not exist : " << courseIndex << endl;
        }
        return added;
    }

    void printStudentList() {
        for (int i = 0; i < instructorCourses->size(); i++) {
            Course *course = instructorCourses->getByIndex(i);
            if (course != NULL) {
                cout << course->getName() << endl;
                ArrayList<Student> *students = course->getStudents();
                for (int j = 0; j < students->size(); j++) {
                    Student *student = students->getByIndex(j);
                    if (student != NULL) {
                        cout << student->getID() << endl;
                    }
                }
                cout << endl;
            }
        }
    }

    //will trigger same method in Course class
    void printAssignments() {
        cout<<"Assignments from Instructor : "<<name<<" "<<surname<<endl;
        for (int i = 0; i < instructorCourses->size(); i++) {
            Course *course = instructorCourses->getByIndex(i);
            if (course != NULL) {
                cout << course->getName() << endl;
                course->printAssignments();
            }
        }
    }

    //will trigger printSubmission() in Assignment class
    void viewSubmissions() {
        for (int i = 0; i < instructorCourses->size(); i++) {
            Course *course = instructorCourses->getByIndex(i);
            if (course != NULL) {
                cout << "Submissions for "<<course->getName() << endl;
                ArrayList<Assignment> *assignments = course->getAssignments();
                for (int j = 0; j < assignments->size(); j++) {
                    Assignment *assignment = assignments->getByIndex(j);
                    if (assignment != NULL) {
                        assignment->printSubmissions();
                    }
                }
            }
        }
    }

    Course *getCourseByIndex(int courseIndex) {
        return instructorCourses->getByIndex(courseIndex);
    }
};