#include <iostream>
using namespace std;
class base{
    private:
     int id;
    protected:
    string name;
    int age;
    public:
     void set(string n, int a, int Id){ name =n; age =a; id=Id;}
     int getId(){ return id;}
    
};
 class student: public base{
    public:
     void show(){
        cout<<"ID no: "<<getId()<<"\n Name: "<<name<<"\nAge: "<<age<<endl;
     }
 };

 int main(){
    student s;
    s.set("noor khan", 39, 101);
    s.show();
 }