#include "submission.h"

Submission::Submission(string owner, string attachment) : owner(owner), attachment(attachment) {}

string Submission::to_string() {
    return owner + ": " + attachment;
}