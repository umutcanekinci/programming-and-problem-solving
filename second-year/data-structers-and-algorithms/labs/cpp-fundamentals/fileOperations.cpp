#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


/* The data structures you will see in this semester can only keep values inside the RAM of the computer. However,
  we can also store information in the disk (HDD SSD etc.)  since they have bigger storage. That is learning
  how to read/write to a file with various extensions  (.txt,.dat .sql etc.) is necessary.

  In C++ when you read a file, the content of the file transformed to a sequence of bytes and most of the common
  processes required for this task is stored in "<fstream>" header.
 */

int main() {
    cout << endl << "FILE OPERATIONS" << endl;

    /* There are various output methods such as "cout" and "cerr" as it is used in here.
        Based on the output you use, the display format will be changed.
     */
    cout << "Using cout to print out this line" << endl;
    cerr << "Using cerr to print out this line" << endl;

    /* Accessing a file content with "input" mode (read mode)
      !!! If your C++ code AND the file are in the same folder, you can directly use file name to access file (if exist)
      otherwise provide the full path the file such as;
      "D:\Code\Clion\2020-2021\Fall\COMP2310\clients.dat"
     */
    cout << endl << "*Reading From File" << endl;
    ifstream read_file;
    // If you are using CLion, you have use "../" before file path to point the project folder
    read_file.open("../week3/clients.dat");

    // Check if the file is exist
    if (!read_file.is_open()) {
        cerr << "File  could not be opened" << endl;
        // Using function to stop execution of the code completely.
        exit(1);
    }

    //Create values to store file content temporarily,or create arrays/other data structures to store them for later use
    string line;
    string name;
    string department;
    string age;

    //You have to know file content structure and values types beforehand to be able to assign them to values
    while (getline(read_file, line)) {
        stringstream line_stream(line);
        /*Since our string contains 1 space character to separate values we passed ' ' to getline function as
        last variable, if you have another separator character such as ',' or ';' use that.
         */
        getline(line_stream, name, ' ');
        getline(line_stream, department, ' ');
        getline(line_stream, age, ' ');
        /* the values read from line and string can be only stored in another strings so you have to type cast
           if you want to use another variable type
           */
        int integer_age = stoi(age);
        cout << "Name : " << name << " Department : " << department << " Age : " << integer_age << endl;
    }
    // !!! ALWAYS CLOSE FILE
    read_file.close();
//    cout << endl << "*Writing to File" << endl;
//    ofstream write_file;
//    /* The second parameter use to determine operation type on file.
//      If you don't supply a second parameter on ofstream variable, THE CONTENT OF THE FILE WILL BE OVERWRITTEN
//      We can use "ios:app" to set the mode on "append" rather than "create".
//     */
//    write_file.open("../week3/clients.dat", ios::app);
//    string line_delimeter = " ";
//    string terminate_word = "Exit";
//    int integer_age;
//    write_file<<"\n";
//    while (true) {
//        cout << "Type Exit as name if you want to stop writing to file" << endl;
//        cout << "Enter name" << endl;
//        cin >> name;
//        if (name == terminate_word) {
//            break;
//        }
//        cout << "Enter department" << endl;
//        cin >> department;
//        cout << "Enter age" << endl;
//        cin >> integer_age;
//        write_file << name << line_delimeter << department << line_delimeter << integer_age << "\n";
//        cout << "Info is written to the file" << endl;
//
//    }
//    write_file.close();
    cout << endl << "*Reading From File Version 2" << endl;
    // If your file use single space as delimiter you can also use the below for read/write
    ifstream read_file_2("../week3/clients.dat", ios::in);
    if (read_file_2.fail()) {
        cerr << "Failed to open file" << endl;
        exit(1);
    }
    while (read_file_2 >> name >> department >> age) {
        int integer_age = stoi(age);
        cout << "Name : " << name << " Department : " << department << " Age : " << integer_age << endl;
    }

    read_file_2.close();

    return 0;
}

