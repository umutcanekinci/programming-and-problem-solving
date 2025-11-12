#include <iostream>

using namespace std;


class Submission {
private:
    string owner;
    string attachment;

public:

    Submission(string owner, string attachment) {
        this->owner = owner;
        this->attachment = attachment;
    }

    bool operator==(Submission other) {
        return owner == other.owner && attachment == other.attachment;
    }

    string toString() {
        return "Owner : " + owner + " Attachment : " + attachment;
    }

};