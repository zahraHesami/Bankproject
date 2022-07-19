#include "Customer.h"
#include <iostream>
#include"Person.h"
#include "Account.h"

using namespace std;
Customer::Customer() :Person()
{

}

void Customer::set_info(string temp_name, string temp_lastname, string temp_username, string temp_password, string date,string code)
{
    this->get_info(temp_name,temp_lastname,temp_username,temp_password, date);
    this->get_nationalcode(code);
}
void Customer::get_nationalcode(string temp_ncode)
{

    if (temp_ncode.size() <9 || temp_ncode.size() > 11)
    {
        throw Invalid_code();
    }
    else
    {
        long long int temp = stoll(temp_ncode);
        national_code = temp;
    }
}
void Customer::add_account(const Account & temp )
{
    account.push_back(temp);
}
void Customer::delete_account(int index)
{
   account.erase(account.begin()+index);
}
void Customer::show_info()
{
    cout << "Name : " << first_name<<'\n';
    cout << "Last Name : " << last_name<<'\n';
    cout << "National Code : " <<national_code<<'\n';
    cout << "birthday : "  << birth_day<<'\n';
    cout << "Username : " << user_name<<'\n';
    for (int i = 0; i < account.size(); i++)
    {
        cout<<"date opening :"<<account[i].get_dateaccount()<<'\n';
        cout<< "Account number :"<<account[i].get_accountnumber()<<'\n';
        cout<<"inventory :"<<account[i].set_inventory()<<'\n';
    }

}

void Customer::accounts_informations()
{
    for (int i = 0; i < account.size(); i++)
    {
        account[i].print_acc();
        account[i].stock_account();
    }
}

void Customer::check_equal_accounts()
{
    for (int i = 0; i < account.size(); i++)
    {
        for (int j = 0; j < account.size() - 1; j++)
        {
            if (account.at(i).get_accountnumber() == account.at(j).get_accountnumber())
            {
                throw Equal_account_number();
            }
        }
    }
}

void Customer:: taking_account()
{
   long long int account_number ;

   cout << "enter the number of account:" << '\n';
   cin >> account_number;
   for (int i = 0; i < account.size(); i++)
   {
       if (account_number == account.at(i).get_accountnumber())
       {
          account.at(i).taking_();
       }
       else
       {
           cout<<"account not found\n";
       }
   }
}

void Customer:: raise_accounts()
{
    long long int account_number ;
    cout << "enter the number of account:" << '\n';
    cin >> account_number;
    for (int i = 0; i < account.size(); i++)
    {
        if (account_number == account.at(i).get_accountnumber())
        {
           account.at(i).raise_account();
        }
        else
        {
            cout<<"account not found\n";
        }
    }
}

vector<Account> Customer::get_accounts()
{
    return account;
}

string Invalid_code::show_error()
{
    invalid_ncode = "wrong national code!";
    return invalid_ncode;
}
string Invalid_account_number::invalid()
{
    error = "the number of account is invalid";
    return error;
}
string Equal_account_number::show_invalidation()
{
    invalid_acc = "there are equal account numbers!";
    return invalid_acc;
}



