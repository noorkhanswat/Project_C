#include <iostream>
#include <string>
using namespace std;
class Date {int dd, mm, yy;};
class student{
    private:
     char* name; // Raw pointer to a character array (string) dynamically allocated the memory  
     Date dob; // Date of birth as a member variable of type Date
    public:
    student (const char* n, int d, int m, int y) : dob(d, m, y) {
        name = new char[strlen(n) + 1]; // Allocate memory for the name with addition of 1 for the null terminator
        strcpy(name, n); // Copy the name to the allocated memory , ensuring that the original string can be safely modified or deallocated without affecting the student object.   
    }
    void show() const  {
        cout << "Name: " << name << ", Date of Birth: " << dob.dd << "/" << dob.mm << "/" << dob.yy << endl;
    }
    ~student() {
        delete[] name; // Deallocate memory to prevent memory leaks
    }
};  
int main() {
    student s("John Doe", 15, 8, 1995); // Create a student object with name and date of birth
    s.show(); // Display the details of the student
    return 0;
}