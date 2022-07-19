#include "Person.h"
#include <iostream>
#include "Incorrect.h"

using namespace std;

Person::Person()
{


}
 Person::Person(string temp_name, string temp_lastname, string temp_username, string temp_password, string date)
 {
     get_info(temp_name,temp_lastname, temp_username,temp_password,date);
 }
void Person::get_info(string temp_name,string temp_lastname,string temp_username,string temp_password,string date)

{

    birth_day.convert_date(date);
    if (temp_name.size() < 3 || temp_lastname.size() < 3)
    {
        throw Incorrect("invalid name !");
    }
    if (temp_username.size() < 3)
    {
        throw Incorrect("invalid username !");
    }
    if (temp_password.size() < 6)
    {
        throw Incorrect("invalid password !");
    }
    first_name=temp_name;
    last_name=temp_lastname;
    user_name=temp_username;
    password=temp_password;
}
