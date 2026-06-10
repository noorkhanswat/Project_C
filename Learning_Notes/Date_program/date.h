//header file for date

#pragma once

class Date{
private:    
    // variable define for date 
    int day;
    int month;
    int year;
    // helper function to validate if a date is correct
     bool isValidDate(int d, int m, int y) const;

    // helper function to check for leap years
     bool isLeapYear(int y) const;
    // helper function to get ay in a specfic month
    int getDaysInMonth(int m, int y) const;

 public:
    // constructor (default to 01/01/2000)
    Date(int d=1, int m=1, int y=2000);

    //Getters

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // setters (return false if the date is invalid)

    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);
    bool setDate(int d, int m, int y);

    // add functions

    void addDays(int day);
    void addMonths(int month);
    void addYears(int year);

    //print utility

    void print() const;
};
