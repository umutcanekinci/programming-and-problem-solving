#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <vector>

using namespace std;

class Submission;

class Assignment {
private:
    string title, instructions;
    vector<Submission *> submissions;
public:
    Assignment(string title, string instructions);
    void add_submission(Submission *submission);
    void print_submission();
    string to_string();
};

#endif