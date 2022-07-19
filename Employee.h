#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Customer.h"
class Employee :public Person
{
public:
    Employee();
    void set_info(int,int,string temp_name, string temp_lastname, string temp_username, string temp_password, string date);
    void set_vacation(int time){vacation_time=time;}
    void set_over(int time){over_time=time;}
    void print_info() const;
    int get_code(){return em_code;}
    void get_overtime();
    void get_vacationtime();
    void creat_newaccount(Customer * customer);
    void remove_account(Customer * customer);
    void show_customerinfo(Customer * customer);
    void disable_enable(Customer * customer);
    friend ostream &operator<<(ostream &output, Employee *one);
private:
    int em_code;
    int over_time;
    int vacation_time;
    int salary;

};

#endif // EMPLOYEE_H
