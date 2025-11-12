#include "assignment.h"
#include "submission.h"
#include <iostream>

Assignment::Assignment(string title, string instructions) : title(title), instructions(instructions) {}

void Assignment::add_submission(Submission *submission) {
    cout << "Adding submission to Assignment: " << title << endl;
    submissions.push_back(submission);
}

void Assignment::print_submission() {
    cout << "Submissions for Assignment: " << title << endl;
    for (int i=0; i < submissions.size(); i++)
        cout << submissions[i]->to_string() << endl;
}

string Assignment::to_string() {
    return "Title: " + title + "\nInstructions: " + instructions + "\n";
}