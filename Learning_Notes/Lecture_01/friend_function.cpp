#include <iostream>
using namespace std;

class Box{
    private:
     int length;
    public:
     Box(){length =23;}
     void set(int l){ length = l;} 
     friend void show(Box a);
};
void show(Box a){
    cout<<"box size: "<<a.length<<endl;
};

int main(){
    Box obj;
    show(obj);
    obj.set(44);
    show(obj);
}