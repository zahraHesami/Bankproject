#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "Date.h"
#include <string>
using namespace std ;
class Account
{
public:
    Account();
    void set_activeaccount(bool temp);
    void set_infoaccount( string temp_account, string date, long long int raise,long long int temp_code);
    void stock_account();
    long long int get_accountnumber() const {return account_number;}
    Date get_dateaccount() const{return opening;}

    void raise_account();
    void taking_();
    void print_acc();
    long long int set_inventory();
private:
    Date opening ;
    bool is_active=true;
    long long int customer_code;
    long long int account_number;
    long long int inventory ;
};
class Not_enough_inventory
{
public:
    string show_error();

private:
    string not_enough;
};
class Not_active_account
{
public:
    string show_notactive();

private:
    string not_active;
};
#endif // ACCOUNT_H
