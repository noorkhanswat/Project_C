#include <iostream>
#include "date.h"
using namespace std;
int main()
{
    Date myDate(29,2,2024); //leap year

    cout<<"Orignal Date: ";
    myDate.print(); 

    myDate.addDays(2);
    cout<<"Afrer adding 2 days: ";
    myDate.print();

    return 0;
}