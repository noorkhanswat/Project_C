#include <iostream>
#include <string>
using namespace std;

class student{
    private:
        int rollNo;
        char* name;
    public:
    student(int r, const char* n)
    {
        rollNo = r;
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }

    void show() const
    {
        cout<<"roll no:" <<rollNo<<"\n name: "<<name;
    }



};

int main()
{
    student s(101, "noor khan");
    s.show();

}