#ifndef BANK_H
#define BANK_H

#include "Employee.h"
#include "Customer.h"
#include<iostream>


class Manager;
class Bank
{
public:
    Bank();
    Bank(const Bank &other);
    void set_info(int,string);
    void add_manager(Manager *temp);
    void set_emp(vector<Employee*>);
    void set_cus(vector<Customer*>);
    void add_employee(Employee *);
    void add_customer(Customer*);
    int search_emp(int );
    int search_cus(long long int);
    int search_numberaccount(string temp_account);
    int search_nationalcode(string);
    int search_employeecode(int temp_emcode);
    vector<Employee*> get_emp() const{return branch_employee;}
    vector<Customer*> get_cus() const {return branch_customer;}
    void remove_bank();
    int login_employee(string temp_password,string temp_username);
    int login_customer(string temp_password,string temp_username);
     Bank &operator=(const Bank &first);
    Manager*  get_manager() const {return branch_manager;}
private:
    int branch_code;
    std::string branch_name;
    vector<Employee*>branch_employee;
    vector<Customer*>branch_customer;
    Manager *branch_manager;
};


#endif // BANK_H
