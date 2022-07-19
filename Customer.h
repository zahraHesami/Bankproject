#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <string>
#include <vector>
#include"Person.h"
#include "Account.h"
using namespace std;
class Customer : public Person
{
public:
    Customer();
    void set_info(string temp_name, string temp_lastname, string temp_username, string temp_password, string date,string code);
    void get_nationalcode(string);
    void show_info();
    void check_equal_accounts();
    void taking_account();
    void raise_accounts();
    void add_account(const Account & temp );
    void delete_account(int index);
    long long int get_national(){return national_code;}
    vector<Account> get_accounts();
    void accounts_informations();
    friend  ostream &operator<<(ostream &output, Customer * one);
private:
    vector<Account> account;
    long long int national_code;
};
class Invalid_code
{
public:
    string show_error();

private:
    string invalid_ncode;
};
class Invalid_account_number
{
public:
    string invalid();

private:
    string error;
};
class Equal_account_number
{
public:
    string show_invalidation();

private:
    string invalid_acc;
};


#endif // CUSTOMER_H
