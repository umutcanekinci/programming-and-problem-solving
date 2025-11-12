#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>

using namespace std;

class Submission {
private:
    string owner, attachment;
public:
    Submission(string owner, string attachment);
    string to_string();
};

#endif