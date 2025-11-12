#include "Submission.cpp"
#include "ArrayList.h"


class Assignment {

private:
    string title;
    string instructions;
    ArrayList<Submission> *submissions;
public:
    Assignment(string title, string instructions, int studentCount) {
        this->title = title;
        this->instructions = instructions;
        this->submissions = new ArrayList<Submission>(studentCount);
    }

    bool addSubmission(Submission *submission) {
        bool added = false;
        if (submissions->getByObject(submission) == NULL) {
            submissions->add(submission);
            added = true;
        } else {
            cout << "The submission already exist : " << submission->toString() << endl;
        }

        return added;
    }

    void printSubmissions() {
        for (int i = 0; i < submissions->size(); i++) {
            Submission *submission = submissions->getByIndex(i);
            if (submission != NULL) {
                cout << submission->toString() << endl;
            }
        }
    }

    string getTitle() {
        return title;
    }

    string toString() {
        return "Title : " + title + " Instructions : " + instructions;
    }
};