#include <iostream>
using namespace std;

class base{
    private:
     int id;
      string name;
    protected:
        int rollNo;
    public:
        base()
        {
        }
        void set(int d, string n)
        {
            id=d;
            name=n;
        }
        int get()
        {
            return id;
        }
        string getname(){return name;}
};
class derived: public base{
    public:
    void show(base a)
    {
        cout<<"ID: "<<a.get()<<"name: "<<a.getname()<<"roll no: "<<endl;
    }
};

int main(){
    base b;
    b.set(101, "noor");
    derived a;
    a.show(b);
  
    return 0;
}