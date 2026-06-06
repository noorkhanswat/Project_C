#include <iostream>
#include <cstring>
using namespace std;

class Student{
    private:
        int rollNo;
        char* name;
    public:
        Student(int r, const char* n) :rollNo(r){
            name = new char[strlen(n) +1];
            strcpy(name, n);
        }
        Student(const Student& other){
           rollNo = other.rollNo;
            name = new char[strlen(other.name)+1];
            strcpy(name, other.name);
        
        }
        Student& operator= (const Student& other){
              if(this != &other)
            {
                delete [] name;
                rollNo = other.rollNo;
                name = new char[strlen(other.name)+1];
                strcpy(name, other.name);
            }
           
            return *this;
        }
        void display() const{
            cout<<"Roll No: "<<rollNo<<"\nName: "<<name<<endl;
        }
        ~Student()
        {
            delete [] name;
        }
};

int main()
{
    Student studentA(101, "noor");
    Student studentB(102, "noorkhan");
    studentA.display();
    studentB.display();
    studentA = studentB;
    studentA.display();
    studentB.display();

    return 0;
}