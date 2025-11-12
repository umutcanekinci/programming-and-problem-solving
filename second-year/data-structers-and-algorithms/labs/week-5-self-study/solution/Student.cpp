#include "ArrayList.h"

// Check AdditionalTopics - Dependency
class Course;

class Student {
private:
    string ID;
    ArrayList<Course> *enrolledCourses;

public:

    Student(string ID, int courseCount) {
        this->ID = ID;
        this->enrolledCourses = new ArrayList<Course>(courseCount);
    }

    bool enrollCourse(Course *course) {
        bool added = false;
        if (enrolledCourses->getByObject(course) == NULL) {
            enrolledCourses->add(course);
            added = true;
        } else {
            cout << "The course already exist : " << course->getName() << endl;
        }

        return added;
    }

    bool submitAssignment(Course *course, int assignmentIndex, string attachment) {
        bool added = false;
        Course *existingCourse = enrolledCourses->getByObject(course);
        if (existingCourse != NULL) {
            Assignment *existingAssignment = existingCourse->getAssignments()->getByIndex(assignmentIndex);
            if (existingAssignment != NULL) {
                Submission *submission = new Submission(ID, attachment);
                added = existingAssignment->addSubmission(submission);
            } else {
                cout << "Assignment does not exist";
            }
        } else {
            cout << "Course does not exist" << course->getName() << endl;
        }
        return added;
    }

    void printCourses() {
        cout << "Courses of student ID: " << ID << endl;
        for (int i = 0; i < enrolledCourses->size(); i++) {
            Course *course = enrolledCourses->getByIndex(i);
            if (course != NULL) {
                cout << course->getName() << endl;
            }
        }
    }

    void printAssignments() {
        for (int i = 0; i < enrolledCourses->size(); i++) {
            Course *course = enrolledCourses->getByIndex(i);
            if (course != NULL) {
                course->printAssignments();
            }
        }
    }

    bool operator==(Student other) {
        return ID == other.ID;
    }

    string getID() {
        return ID;
    }

};