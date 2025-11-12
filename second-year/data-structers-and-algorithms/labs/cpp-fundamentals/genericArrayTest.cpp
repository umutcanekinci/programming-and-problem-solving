#include "genericArray.h"

#define prettyPrint(value) (value?"Passed":"Failed")

int main() {
    ArrayList<int> *integers = new ArrayList<int>(5);
    integers->add(5);
    integers->add(3);
    integers->printElements();
    ArrayList<char> *chars = new ArrayList<char>(3);
    chars->add(1, 'A');
    chars->add(2, 'B');
    chars->printElements();

    // Testing part. Be careful about the cases.
    cout << "Test case 1 : " << prettyPrint(chars->searchElement('A')) << endl;
    cout << "Test case 2 : " << prettyPrint(chars->searchElement(NULL)) << endl;
    cout << "Test case 3 : " << prettyPrint(!integers->searchElement(4)) << endl;
    integers->removeElement(0);
    cout << "Test case 4 : " << prettyPrint(integers->get(0) == NULL) << endl;

    return 0;
}