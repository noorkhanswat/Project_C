#include <iostream>
#include <cstring> // For strlen and strcpy functions

using namespace std;

class student{
    private:
    int rollNo;
    char* name; // Raw pointer to a character array (string) dynamically allocated the memory for the name

    public:
    //Constructor
    student (int r, const char* n) { // constant character pointer to avoid modifying the input string
        rollNo = r;
        name = new char[strlen(n) + 1]; // Allocate memory for the name with addition of 1 for the null terminator
        strcpy(name, n); // Copy the name to the allocated memory , ensuring that the original string can be safely modified or deallocated without affecting the student object.   
    }
    // setter /Getter
    void setRoll(int r) {if (r >0) rollNo = r;}
    int getRoll() {return rollNo;}
    void show() const  {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }

    ~student() {
        delete[] name; // Deallocate memory to prevent memory leaks
    }
};

int main() {
    
    student* s[5]; // Array of pointers to student objects
    for (int i = 0; i < 5; i++) {
        int roll;
        char name[100]; // Temporary buffer to hold the name input
        cout << "Enter roll number and name for student " << (i + 1) << ": ";
        cin >> roll >> name; // Read roll number and name from user input
        s[i] = new student(roll, name); // Create a new student object and store its pointer in the array
    }
    for(int i = 0; i < 5; i++) {
        s[i]->show(); // Display the details of each student
    }
    for(int i = 0; i < 5; i++) {
        delete s[i]; // Deallocate memory for each student object to prevent memory leaks
    }

    return 0;
}