
#include "Bank.h"
#include "Employee.h"
#include "Manager.h"
#include "Incorrect.h"
using namespace std;

Manager::Manager()
{

}

void Manager::set_managerinfo(int money, int code, string temp_name, string temp_lastname, string temp_username, string temp_password, string date, Bank *temp)
{
    this->set_info( money,code,temp_name,temp_lastname, temp_username,temp_password,date);
    bank_manager=temp;
}

void Manager::showing_emp_info()
{

    int temp_emp_code;
    cout << "enter the code : " << '\n';
    cin >> temp_emp_code;

    if (check_valid_code(temp_emp_code) < 0)
    {
        throw Incorrect(" Invalid Number !");
    }
    else
    {     int employee_index=search_emp_info(temp_emp_code);
        bank_manager->get_emp().at(employee_index)->print_info();
    }
}

void Manager::adding_new_emp(Employee *temp_manager_emp)
{


    bank_manager->add_employee(temp_manager_emp);

}

void Manager::removing_emp()
{

    int temp_code;
    int index_emp;

    cout << "Enter the Employee Code :" << '\n';
    cin >> temp_code;
    if (check_valid_code(temp_code) < 0)
    {
        throw Incorrect(" Invalid Code !");
    }

        for (int i = 0; i < bank_manager->get_emp().size(); i++)
        {
            if (temp_code == bank_manager->get_emp().at(i)->get_code())
            {
                index_emp=i;
            }
        }
        bank_manager->get_emp().erase(bank_manager->get_emp().begin() +index_emp);
}

int Manager::check_valid_code(int input_code)
{

    if (input_code < 0 || input_code > 1000 || input_code < 100)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int Manager::search_emp_info(int temp_code)
{

    int emp_index = bank_manager->search_emp(temp_code);

    if (emp_index < 0)
    {
        throw Incorrect(" Not Found !");
    }
    if (emp_index >= 0)
    {
        return emp_index;
    }
}
