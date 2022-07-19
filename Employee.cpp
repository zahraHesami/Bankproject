#include"Person.h"
#include "Employee.h"
#include "Customer.h"
#include "Incorrect.h"

Employee::Employee()
{

}

void Employee:: set_info(int money, int code,string temp_name, string temp_lastname, string temp_username, string temp_password, string date)
{
    this->get_info(temp_name,temp_lastname, temp_username,temp_password,date);
    if(money==0 || money<0)
    {
        throw Incorrect("invalid number !");
    }
    if(code<0||code>1000||code<100)
    {
        throw Incorrect("invalid number !");
    }
    salary=money;
    em_code=code;
    over_time=0;
    vacation_time=0;
}
void Employee::print_info() const
{
    cout<<"employee  name :"<<first_name<<'\n';
    cout<<"employee  last_name:"<<last_name<<'\n';
    cout<<"employee  birthday :";
    birth_day.print_date();
    cout<<"employee user_name :"<<user_name<<'\n';
    cout<<"employee  password:"<<password<<'\n';
    cout<<"employee  salary:"<<salary<<'\n';
    cout<<"employee   vacation hour "<<vacation_time<<'\n';
    cout<<"employee   overtime "<<over_time<<'\n';


}

void  Employee::get_overtime()
{
    int time;
    cout<<"Enter the number of overtime hours\n";
    cin>>time;
    if(time<0 )
    {
       throw Incorrect("invalid time !");
    }
    over_time=over_time+time;
    if(over_time>12)
    {
        cout<<"You can not apply for overtime for more than 12 hours per month\n";
         over_time=over_time-time;
    }
   else if( over_time<=12)
    {
        salary=salary+(time*120000);
        cout<<"Your salary after overtime is "<<salary<<'\n';
    }
}

void  Employee::get_vacationtime()
{
    int time;
    cout<<"Enter the number of vacation hours\n";
    cin>>time;
    if(time<0 )
    {
        throw Incorrect("invalid time !");
    }
    vacation_time=vacation_time+time;
    if(vacation_time>15)
    {
        cout<<"You  apply for vacation hour for more than 15 hours per month\n";
       salary=salary-(time*100000);
       cout<<"Your salary after vacation hour is "<<salary<<'\n';
    }

    if( vacation_time<=15)
    {
        int a=15;
        cout<<" Your request has been approved"<<'\n';
      cout<<"you can apply "<<(a-vacation_time)<<"hours for vacation in month\n";
    }


}

void Employee::creat_newaccount(Customer * customer)
{
     Account first ;
     string temp_account;
     string date;
     long long int raise;
         cout << "enter the number of  account: " << '\n';
         cin >> temp_account;
         cout << "how much do you want to raise your account?" << '\n';
         cin>>raise;
         cout<<"enter date\n";
         cin>>date;
       long long int national_code =customer->get_national();
     first.set_infoaccount(temp_account,date,raise,national_code);
     customer->add_account(first);


}

void Employee:: remove_account(Customer * customer)
{

    long long int account_number ;
     int index=-1;
    cout << "enter the number of account:" << '\n';
    cin >> account_number;
    for (int i = 0; i < customer->get_accounts().size(); i++)
    {
     if (account_number ==customer->get_accounts().at(i).get_accountnumber())
        {
          index=i;
        }

   }
   if(index>-1)
   {
    customer->delete_account(index);
   }
   if (index==-1)
    {
    cout<<"account not found please try again"<<'\n';
    }

}

void Employee:: show_customerinfo(Customer * customer)
{

   customer->show_info();
}

void Employee:: disable_enable(Customer * customer)
{

     bool mood;
     int number;
     cout<<"enter the  number\n";
     cout<<"1)if you want to disable account\n";
     cout<<"2)if you want to enable account \n ";
     cin>>number;

          if(number==1)
          {
              mood=false;
          }
          if(number==2)
          {
              mood=true;
          }
          long long int account_number ;
          cout << "enter the number of account:" << '\n';
          cin >> account_number;
          for (int i = 0; i < customer->get_accounts().size(); i++)
             {
               if (account_number ==  customer->get_accounts().at(i).get_accountnumber())
                  {
                  customer->get_accounts().at(i).set_activeaccount(mood);
                   }
             }

}













