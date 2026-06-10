// date.cpp file 
#include <iostream>
#include "date.h"

//constructor

Date::Date(int d, int m, int y)
{
    if (!setDate(d, m, y)){
        day = 1;
        month = 1;
        year = 2000;
    }
}

// Getters

int Date::getDay() const {return day;}
int Date::getMonth() const {return month;}
int Date::getYear() const {return year;}

// setters

bool Date::setDay(int d){
    if (isValidDate(d, month, year))
    {
        day =d;
        return true;
    }
    return false;
}

bool Date::setMonth(int m){
    if(isValidDate(day, m, year)){
        month =m;
        return true;
    }
    return false;
}

bool Date::setYear(int y){
    if(isValidDate(day, month, y))
    {
        year = y;
        return true;
    }
    return false;
}

bool Date::setDate(int d, int m, int y)
{
    if(isValidDate(d, m, y))
    {
        day = d;
        month = m;
        year = y;
        return true;
    }
    return false;
}

// add function 

void Date::addDays(int days)
{
    day += days;
    while (day > getDaysInMonth(month, year))
    {
        day -= getDaysInMonth(month, year);
        addMonths(1);
    }
}

void Date::addMonths(int months)
{
    month += months;
    while(month >12)
    {
        month -= months;
        addYears(1);
    }

    // hande edge case (march 31th = april 30th)
    int maxDays = getDaysInMonth(month, year);
    if (day > maxDays)
    {
        day = maxDays;
    }
}
void Date::addYears(int years)
{
    year += years;
    // handle leap year edge case (feb 29th)
    if (month ==2 && day == 29 && !isLeapYear(year))
    {
        day = 28;
    }
}

// print

void Date::print() const
{
    std::cout<<(day <10 ? "0" : "") <<day<< "/"
            <<(month < 10 ? "0" : "")<<month<<"/"
            <<year <<std::endl;
}

// private healer functions

bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 !=0 || (y % 400 == 0));
}

int Date::getDaysInMonth(int m, int y) const
{
    if ( m==2) return isLeapYear(y) ? 29 : 28;
    if (m==4 || m==6 || m==9 || m==11) return 30;
    return 31;
}
bool Date::isValidDate(int d, int m, int y) const
{
    if (y<0 || m <1 || m>12 || d <1) return false;
    return d <= getDaysInMonth(m,y);
}