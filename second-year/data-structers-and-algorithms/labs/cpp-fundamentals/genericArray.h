/*
 * Generally header files are used for the collection of reference pointers for functions,constants etc.
 * similar to "interfaces". However, for simplicity we are going to define the classes and their functionalities
 * directly in this file.
 *
 * For the Clion users ;
 * Please add the line in below to your CMakeList.txt to be able to run this example.
 * add_executable(Lab4-GenericArray SubFolderNameIfExist/genericArrayTest.cpp)
 */
#include <iostream>

using namespace std;

/*
 * T is a generic type "placeholder". The type of the variable will be converted to the user defined
 * variables on the initialization. Please refer to the "genericArrayTest.cpp" for the examples.
 */
template<class T>
class ArrayList {
    int size;

    T *elements; // T* is necessary to allocate the necessary space after its declaration.
public:
    ArrayList(int size) {
        this->size = size;
        elements = new T[size];
        // Override the random values in memory with NULL
        for (int i = 0; i < size; i++) {
            elements[i] = NULL;
        }
    }

    void printElements() {
        cout << "ArrayList : {";
        for (int i = 0; i < size; i++) {
            // NULL value printed as 0 for the integer type variables
            cout << elements[i] << ",";
        }
        cout << "}" << endl;
    }

    int getSize() {
        return size;
    }

    // What is missing in this function?
    T get(int index) {
        return elements[index];
    }

    // Add value to specific index
    bool add(int index, T element) {
        bool success = false;
        if ((index >= 0) && (index < size)) {
            elements[index] = element;
            success = true;
        }
        return success;
    }

    // Add value to first available position
    bool add(T element) {
        bool success = false;
        for (int i = 0; i < size; i++) {
            if (elements[i] == NULL) {
                elements[i] = element;
                success = true;
                break;
            }
        }
        return success;
    }

    // Search an element, and return True if it exists.
    bool searchElement(T element) {
        return false;
    }

    // Remove the element in specific index
    void removeElement(int index) {
        elements[index] = NULL;
    }

};
