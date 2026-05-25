#include <iostream>
using namespace std;

class A{
    private:
     string name;
     int age;
    public:
        A(string n, int a){name =n; age =a;}
    friend class B;
};

class B{
    public:
    void show(A obj)
    {
        cout<<"name: "<<obj.name<<"\n age: "<<obj.age<<endl;
    }
};

int main()
{
    A obj1("noor khan", 37);
    B obj2;
    obj2.show(obj1);

    return 0;
    
}