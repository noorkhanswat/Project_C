#include <iostream>
#include <cstring>
using namespace std;
class student{
    private:
    const int id;
    int rollNo;
    char* name; // Raw pointer to a character array (string) dynamically allocated the memory
    static int count; // Static member to keep track of the number of student objects created
    public:
    //Constructor
    student (int id, int r, const char* n) :id (id), rollNo (r) { // constant character pointer to avoid modifying the input string
        name = new char[strlen(n) + 1]; // Allocate memory for the name with addition of 1 for the null terminator
        strcpy(name, n); // Copy the name to the allocated memory , ensuring that the original string can be safely modified or deallocated without affecting the student object.   
        count++; // Increment the count of student objects created
    }
    void show() const  {
        cout << "ID: " << id << ", Roll No: " << rollNo << ", Name: " << name << endl;
    }
    student& setRoll(int r) {if (r >0) rollNo = r; return *this;} // Return reference to the current object to allow method chaining
    static int getCount() { return count; } // Static member function to get the count of student objects created
    ~student() {
        delete[] name; // Deallocate memory to prevent memory leaks
    }
};
int student::count = 0; // Initialize the static member variable

int main() {
    
    student* s[5]; // Array of pointers to student objects
    for (int i = 0; i < 5; i++) {
        int id, roll;
        char name[100]; // Temporary buffer to hold the name input
        cout << "Enter ID, roll number and name for student " << (i + 1) << ": ";
        cin >> id >> roll >> name; // Read ID, roll number and name from user input
        s[i] = new student(id, roll, name); // Create a new student object and store its pointer in the array
    }
    for(int i = 0; i < 5; i++) {
        s[i]->show(); // Display the details of each student
    }
    cout << "Total number of students created: " << student::getCount() << endl; // Display the total count of student objects created
    for(int i = 0; i < 5; i++) {
        delete s[i]; // Deallocate memory for each student object to prevent memory leaks
    }

    return 0;
}