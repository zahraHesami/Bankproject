#include <iostream>
#include"Account.h"
#include "Incorrect.h"
#include  "Date.h"
using namespace std;

Account::Account()

{

}
void Account::set_activeaccount(bool temp)
{
    is_active=temp;
}
void Account::stock_account()
{
    cout << "the amount of money stored in your account is:" << '\t' << inventory << '\n';
}
void Account::raise_account()
{
            long long int raise;
            cout << "how much do you want to raise your account?" << '\n';
            cin >> raise;
            inventory += raise;
}

void Account::taking_()
{
    long long int take;

            if (is_active)
            {
                cout << "how much do you want to take from your account?" << '\n';
                cin >> take;
                if (take > inventory)
                {
                    throw Not_enough_inventory();
                }
                inventory -= take;
            }
            else
            {
                throw Not_active_account();
            }
}

void Account::set_infoaccount( string temp_account, string date, long long int raise,long long int temp_code)
{


    if (temp_account.size() < 13 || temp_account.size() > 13)
    {
        throw Incorrect("Invalid_account_number");
    }


   if(raise<500000)
   {
       cout<<"enough money for add  acount is 500000 but you enter"<<raise<<'\n';
       cout<<"please enter new number\n";
       cin>>raise;
   }
     customer_code=temp_code;
     opening.convert_date(date);
     account_number=stoll(temp_account);
     inventory=raise;
}
long long int Account::set_inventory()
{
    return inventory;
}
void Account::print_acc()
{
    cout << account_number << '\n';
}

string Not_enough_inventory::show_error()
{
    not_enough = "there isn't enough inventory in your account!";
    return not_enough;
}
string Not_active_account::show_notactive()
{
    not_active = "this account is not active!";
    return not_active;
}
