#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{

public:
    Date();
    void convert_date(string date);
    void set_date(int,int,int);
    bool check_date(int,int,int);
    void print_date() const;
   friend ostream &operator<<(ostream &output,const Date &one);
private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
