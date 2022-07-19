#ifndef PERSON_H
#define PERSON_H
#include "Date.h"
#include <string>
#include <iostream>

using namespace std ;
class Person
{
public:
    Person();
    Person(string temp_name, string temp_lastname, string temp_username, string temp_password, string date);
    void get_info(string temp_name, string temp_lastname, string temp_username, string temp_password, string date);
    void check_info();
    string get_password(){return password;}
    string get_username(){return user_name;}
protected:
    string first_name;
    string last_name;
    Date birth_day;
    string user_name;
    string password;
};



#endif // PERSON_H
