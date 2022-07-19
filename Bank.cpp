#include "Bank.h"
#include "Incorrect.h"
#include"Manager.h"
Bank::Bank()
{

}
Bank::Bank(const Bank &other)
 {

    delete branch_manager;
     branch_manager=other.branch_manager;
     branch_code=other.branch_code;
     branch_name=other.branch_name;
     for(int i=0;i<other.branch_employee.size();i++)
     {
         branch_employee[i]=other.branch_employee[i];
     }
     for(int i=0;i<other.branch_customer.size();i++)
     {
         branch_customer[i]=other.branch_customer[i];
     }
}
void Bank::remove_bank()
{
    delete branch_manager;
     for(int i=0;i<branch_employee.size();i++)
     {
         delete branch_employee[i];
     }
     for(int i=0;i<branch_customer.size();i++)
     {
         delete branch_customer[i];
     }
}
void Bank::add_manager(Manager *temp)
{
    branch_manager=temp;
}
void Bank::set_info(int bank_code, string bank_name)
{
    if(bank_code<3)
    {
        throw Incorrect("incorrect bank code");
    }
    if(bank_name==" ")
    {
        throw Incorrect("incorrect bank name");
    }

    branch_code=bank_code;
    branch_name=bank_name;
}

void Bank::set_emp(vector<Employee*> temp)
{
    for(int i=0;i<temp.size();i++)
    {
        branch_employee.push_back(temp[i]);
    }
}

void Bank::set_cus(vector<Customer*> temp)
{
    for(int i=0;i<temp.size();i++)
    {
        branch_customer.push_back(temp[i]);
    }
}

int Bank:: search_emp(int em_code)
{
    int index=-1;
    for(int i=0;i<branch_employee.size();i++)
    {
       if(branch_employee[i]->get_code()==em_code)
       {
           index=i;
       }
    }
    return index;
}

int Bank::search_cus(long long int national_code)
{
    int index=-1;
    for(int i=0;i<branch_customer.size();i++)
    {
       if(branch_customer[i]->get_national()==national_code)
       {
           index=i;
       }
    }
    return index;
}

void Bank:: add_employee(Employee * employee)
{
        branch_employee.push_back(employee);
}


void Bank::add_customer(Customer* customer)
{
      branch_customer.push_back(customer);
}

int Bank::search_numberaccount(string temp_account )
{
    long long int  account_number = stoll(temp_account);
    int index = -1;
    for(int i=0;i<branch_customer.size();i++)
    {
        for(int j=0;j<branch_customer[i]->get_accounts().size();i++)
        {
            if(branch_customer[i]->get_accounts()[j].get_accountnumber()==account_number)
            {
                index=1;
            }
        }
    }
    return index;
}

int Bank:: search_nationalcode(string temp_ncode)
{
    long long int temp = stoll(temp_ncode);
     int index = -1;
    for(int i = 0; i<branch_customer.size();i++)
    {
        if(branch_customer[i]->get_national()==temp)
        {
            index=i;
        }
    }
     return index;
}

int Bank:: search_employeecode(int temp_emcode)
{
  int index = -1;
    for(int i = 0;i<branch_employee.size();i++)
    {
        if(branch_employee[i]->get_code()==temp_emcode)
        {
            index=i;
        }
    }
     return index;
}

int Bank:: login_employee(string temp_password,string temp_username)
{
     int index = -1;
    for(int i = 0;i<branch_employee.size();i++)
    {
        if(branch_employee[i]->get_password()==temp_password && branch_employee[i]->get_username()==temp_username)
        {
            index=i;
        }
    }

   if(branch_manager->get_password()==temp_password && branch_manager->get_username()==temp_username)
   {
       index=-2;
   }
    return index;
}

int  Bank::login_customer(string temp_password,string temp_username)
{
    int index = -1;
   for(int i = 0; i<branch_customer.size();i++)
   {
       if(branch_customer[i]->get_password()==temp_password && branch_customer[i]->get_username()==temp_username )
       {
           index=i;
       }
   }
    return index;
}
Bank & Bank::operator=(const Bank &first)
{
    this->remove_bank();
    delete branch_manager;
    branch_manager=first.branch_manager;
    branch_code=first.branch_code;
    branch_name=first.branch_name;
    for(int i=0;i<first.branch_employee.size();i++)
    {
        branch_employee[i]=first.branch_employee[i];
    }
    for(int i=0;i<first.branch_customer.size();i++)
    {
        branch_customer[i]=first.branch_customer[i];
    }
}


















