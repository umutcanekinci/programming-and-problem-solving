#include "Assignment.cpp"

// Check AdditionalTopics - Dependency
class Student;

class Course {
private:
    string name;
    ArrayList<Student> *enrolledStudents;
    ArrayList<Assignment> *assignments;

public:

    Course(string name, int studentCount, int assignmentCount) {
        this->name = name;
        this->enrolledStudents = new ArrayList<Student>(studentCount);
        this->assignments = new ArrayList<Assignment>(assignmentCount);
    }

    bool addStudent(Student *student) {
        bool added = false;
        if (enrolledStudents->getByObject(student) == NULL) {
            enrolledStudents->add(student);
            added = true;
        }

        return added;
    }

    bool addAssignment(Assignment *assignment) {
        bool added = false;
        if (assignments->getByObject(assignment) == NULL) {
            assignments->add(assignment);
            added = true;
        } else {
            cout << "The assignment already exist : " << assignment->toString() << endl;
        }

        return added;
    }

    void printAssignments() {
        for (int i = 0; i < assignments->size(); ++i) {
            Assignment *assignment = assignments->getByIndex(i);
            if (assignment != NULL) {
                cout << assignment->toString()<<endl;
            }
        }
    }

    ArrayList<Assignment> *getAssignments() {
        return assignments;
    }

    ArrayList<Student> *getStudents() {
        return enrolledStudents;
    }

    bool operator==(Course other) {
        return name == other.name;
    }

    string getName() {
        return this->name;
    }
};