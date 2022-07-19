#ifndef MANAGER_H
#define MANAGER_H

#include "Bank.h"
class Manager : public Employee
{
public:
   Manager();
   void set_managerinfo(int money, int code,string temp_name, string temp_lastname, string temp_username, string temp_password, string date,Bank *temp);
   void showing_emp_info();
   void adding_new_emp(Employee *);
   void removing_emp();
   int check_valid_code(int input_code);
   int search_emp_info(int temp_code);

private:
   Bank *bank_manager;
};

#endif // MANAGER_H
