#include <iostream>
#include "Incorrect.h"
#include "Invaliditem.h"
#include "Manager.h"
#include"Person.h"
#include"Date.h"
#include"Account.h"
#include"Customer.h"
#include"Employee.h"
#include "Bank.h"
#include<fstream>
#include <ctime>
using namespace std;
 class Manager;
 class Bank;
 class Customer;
 class Account;
 class Employee;
void vacation_request(Bank & bank, int index);

void over_request(Bank & bank,int);

void show_info(const Bank &bank,int);

void show_customerinfo(Bank &bank, int);

void creat_account( Bank &bank,int);

void remove_account(Bank &bank,int);

void vacation_request(Bank & bank);

void over_request(Bank & bank);

void show_info(const Bank &bank);

void show_customerinfo(Bank &bank);

void creat_account( Bank &bank);

void remove_account(Bank &bank);

int print_mainmenu();

int print_employeemenu();

void switch_employeemenu(Bank & bank);

void switch_customer_menu(Bank &bank);

int print_customer_menu();

void raise_account(Bank & bank, int index);

void taking_account(Bank & bank, int index);

void account_information(Bank & bank, int index);

void customer_info(Bank&bank, int index);

void switch_managermenu(Bank &bank);

int print_managermenu();

void show_employeeinfo(Bank &bank);

void add_employee(Bank &bank);

void remove_employee(Bank &bank);

ostream &operator<<(ostream &output,const Date &one)
{
    output<<one.year<<"/";
     output<<one.month<<"/";
     output<<one.day;
     return output;
}

ostream &operator<<(ostream &output,Employee *one)
{
    output<<one->first_name<<'\t';
    output<<one->last_name<<'\t';
    output<<one->user_name<<'\t';
    output<<one->password<<'\t';
    output<<one->birth_day<<'\t';
    output<<one->em_code<<'\t';
    output<<one->over_time<<'\t';
    output<<one->vacation_time<<'\t';
    output<<one->salary;
return output;
}

ostream &operator<<(ostream &output, Customer *one)
{
    output<<one->first_name<<'\t';
    output<<one->last_name<<'\t';
    output<<one->user_name<<'\t';
    output<<one->password<<'\t';
    output<<one->birth_day<<'\t';
    output<<one->national_code<<'\t';
    for(int i=0;i<one->get_accounts().size();i++)
    {
        output<<one->get_accounts()[i].get_accountnumber()<<'\t';
        output<<one->get_accounts()[i].get_dateaccount()<<'\t';
        output<<one->get_accounts()[i].set_inventory()<<'\t';
    }

 return output;
}
void report_cusromer(int index, Bank &bank)
{

    ofstream customer_report("customer_report.txt", ios::trunc);
    if (customer_report.is_open())
    {
//        time_t login = time();

//        char *dt = ctime(&login);

        long long int temp = bank.get_cus().at(index)->get_national();

        customer_report << "Account wiith National Code :" << temp;
        //customer_report << "Login in Date and Time : " << dt;

        customer_report.close();
    }
    if (customer_report.fail())
    {
        cerr << " Error !";
    }
}
void report_employee(int index, Bank &bank)
{

    ofstream employee_report("employee_report.txt", ios::trunc);
    if (employee_report.is_open())
    {
        //time_t login = time();

       // char *dt = ctime(&login);

        long long int temp = bank.get_emp().at(index)->get_code();

        employee_report << "Employee wiith National Code :" << temp;
        //employee_report << "Login in Date and Time : " << dt;

        employee_report.close();
    }
    if (employee_report.fail())
    {
        cerr << " Error !";
    }
}

void report_create_account(int index, Bank &bank)
{

    ofstream create_account_report("create_account_report.txt", ios::trunc);
    if (create_account_report.is_open())
    {
       // time_t login = time();

       // char *dt = ctime(&login);

        long long int temp = bank.get_cus().at(index)->get_accounts().at(index).get_accountnumber();

        create_account_report << "Account wiith National Code :" << temp;
       // create_account_report << "created in : " << dt;

        create_account_report.close();
    }
    if (create_account_report.fail())
    {
        cerr << " Error !";
    }
}

void save_employee(const Bank &bank)
{
    ofstream myfile("employee.txt",ios::trunc);
    if (myfile.is_open())
    {
       for(int i=0;i<bank.get_emp().size();i++)
       {
         myfile<<bank.get_emp()[i];
                 myfile<<'\n';
       }

        myfile.close();
    }
   if(myfile.fail())
    {
        cerr << "There is an error in the file";
    }
}

void save_customer(const Bank &bank)
{
    ofstream myfile("customer.txt", ios::trunc);
    if (myfile.is_open())
    {
       for(int i=0;i<bank.get_cus().size();i++)
       {
         myfile<<bank.get_cus()[i];
                 myfile<<'\n';
       }
       myfile<<"0";
        myfile.close();
    }
   if(myfile.fail())
    {
        cerr << "There is an error in the file";
    }
}

void load_employee(Bank &bank)
{
    string name;
    string last_name;
    string user_name;
    string password;
    string  birth_day;
    int  em_code;
    int over_time;
    int vacation_time;
    int salary;
    ifstream myfile("employee.txt", ios::in);
    Employee *person = new Employee;
    vector<Employee*>temp;
    if(myfile.is_open())
    {
        while (myfile)
        {

            myfile>>name;
            myfile>>last_name;
            myfile>>user_name;
            myfile>>password;
            myfile>> birth_day;
            myfile>>em_code;
            myfile>>over_time;
            myfile>>vacation_time;
            myfile>>salary;
             try{
            person->set_info(salary,em_code,name,last_name,user_name,password,birth_day);
            person->set_over(over_time);
            person->set_vacation(vacation_time);
             temp.push_back(person);
            }
            catch(Incorrect error)
            {
                cout<<error.show_invalid();
            }

          }
        delete person;
          temp.pop_back();
           myfile.close();
    }
    else
    {
        cout<<"error";
        throw Incorrect("There is an error in the file");
    }
    bank.set_emp(temp);
}

void load_customer(Bank&bank)
{
     string name;
     string last_name;
     string user_name;
     string password;
     string  birth_day;
     string national_code;
     string account_number;
     string opening;
     long long int inventory;
     ifstream myfile("customer.txt", ios::in);
     Customer *person = new Customer;
     Account first;
     vector<Customer*>temp;
    if(myfile.is_open())
    {
        while (myfile)
        {

            myfile>>name;
            myfile>>last_name;
            myfile>>user_name;
            myfile>>password;
            myfile>> birth_day;
            myfile>>national_code;
            myfile>>account_number;
            myfile>>opening;
            myfile>>inventory;
         try{
             person->set_info(name,last_name,user_name,password,birth_day,national_code);
             long long int code=stoll(national_code);
             first.set_infoaccount(account_number,opening,inventory,code);
             person->add_account(first);
             temp.push_back(person);
            }
            catch(Incorrect error)
            {
                cout<<error.show_invalid();
            }
           catch(Invalid_code error)
            {
               cout<< error.show_error();
            }

          }
        delete person;
           temp.pop_back();
           myfile.close();
    }
    else
    {
        cout<<"error";
        throw Incorrect("There is an error in the file");
    }
    bank.set_cus(temp);

}

void switch_employeemenu(Bank & bank)
{
    bool showmenu = true;
    string username;
    string password;
    int index;
    cout << "enter user name:" << '\n';
    cin >> username;
    cout << "enter password:" << '\n';
    cin >> password;
   index=bank.login_employee(password,username);
   if(index==-2)
   {
       switch_managermenu(bank);
   }
   if(index==-1)
   {
       throw Invaliditem("please enter correct (password or username)");
   }
   if(index>-1)
   {
    while (showmenu)
    {

        try
      {

           int itemmenu= print_employeemenu();
            switch (itemmenu)
        {
            case 1:

            vacation_request(bank,index);

                break;

            case 2:

            over_request(bank,index);

                break;

            case 3:

            show_info(bank,index);

                break;

            case 4:

            show_customerinfo(bank,index);

                break;

            case 5:

            creat_account(bank,index);

                break;

            case 6:

            remove_account(bank,index);

                break;

            case 7:

            save_employee(bank);
            save_customer(bank);
            showmenu=false;

                break;

            default:
                break;
            }
      }

        catch (Invaliditem error)
        {
          cout<<error.get_error()<<'\n';
        }

    }
   }
}

int print_mainmenu()
{
     int itemMenu;
     cout<<"1- Employee \n";
     cout<<"2- Customer \n";
     cout<<"3- Quit \n";
    cin>>itemMenu;
    if(itemMenu>3 || itemMenu<=0)
    {
        throw Invaliditem("Invalid value selected!!!");
    }
     return itemMenu;
}

int print_employeemenu()
{
    int itemMenu;
    cout<<"1- vacation request\n";
    cout<<"2- over time request\n";
    cout<<"3- show information\n";
    cout<<"4- show  customer info \n";
    cout<<"5- creat new account\n";
    cout<<"6- remove account\n";
    cout<<"7- Quit\n";
   cin>>itemMenu;
   if(itemMenu>7|| itemMenu<=0)
   {
       throw Invaliditem("Invalid value selected!!!");
   }
    return itemMenu;
}

void vacation_request(Bank & bank, int index)
{
    try
    {
        bank.get_emp()[index]->get_vacationtime();
    }
    catch (Incorrect error)
    {
       cout<< error.show_invalid();
    }


}

void over_request(Bank & bank, int index)
{
    try
    {
        bank.get_emp()[index]->get_overtime();
    }
    catch (Incorrect error)
    {
       cout<< error.show_invalid();
    }
}

void show_info(const Bank &bank,int index)
{
    bank.get_emp()[index]->print_info();

}

void show_customerinfo(Bank &bank, int index)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);
    if(customer_index==-1)
    {
        cout<<"Customer not found";
    }
    if(customer_index>-1)
    {
        bank.get_emp()[index]->show_customerinfo(bank.get_cus()[customer_index]) ;
    }

}

void creat_account( Bank &bank,int index)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);
    if(customer_index==-1)
    {
       Customer *temp=new Customer;
        try{

        string first_name;
        string last_name;
        string user_name;
        string password;
        string  birth_day;
        string code;
            cout << "enter customer name:" << '\n';
            cin >> first_name;
            cout << "enter customer  last name:" << '\n';
            cin >> last_name;
            cout << "enter customer your birthday:" << '\n';
            cin >>birth_day;
            cout << "enter customer user name:" << '\n';
            cin >>user_name;
            cout << "enter customer password:" << '\n';
            cin >> password;
            cout<<"Enter customer national code:";
            cin>>code;
        temp->set_info(first_name,last_name,user_name,password,birth_day,code);
         bank.get_emp()[index]->creat_newaccount(temp);
         bank.add_customer(temp);
       }
       catch(Incorrect error)
        {
           cout<< error.show_invalid()<<'\n';
           delete temp;
        }
       catch(Invalid_code error)
        {
            cout<<error.show_error()<<'\n';
            delete temp;
        }

    }
    if(customer_index>-1)
    {
        try {
              bank.get_emp()[index]->creat_newaccount(bank.get_cus()[customer_index]);
        } catch (Incorrect error)
        {
            cout<<error.show_invalid()<<'\n';
        }

    }

}

void remove_account(Bank &bank, int index)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);

    bank.get_emp()[index]->remove_account(bank.get_cus()[customer_index]);

}

int print_customer_menu()
{
    int choice;
    cout << "1)Raising Account's stock" << '\n';
    cout << "2)Taking From Account" << '\n';
    cout << "3)Print Information" << '\n';
    cout << "4)Print Account's Information" << '\n';
    cout << "5) Quit\n";
    cin >> choice;
    if (choice > 5 || choice < 0)
    {
        throw Invaliditem("Invalid Choice !");
    }
    return choice;
}

void switch_customer_menu(Bank &bank)
{
    bool print_menu = true;
    string username;
    string password;
    int index;
    cout << "enter user name:" << '\n';
    cin >> username;
    cout << "enter password:" << '\n';
    cin >> password;
    index = bank.login_customer(password, username);
    if (index == -1)
    {
        throw Invaliditem("please enter correct (password or username)");
    }
    while (print_menu)
    {

        try
        {
            int choosing = print_customer_menu();
            switch (choosing)
            {
            case 1:
               raise_account(bank,index);
                break;
            case 2:
                taking_account(bank,index);
                break;
            case 3:
              account_information( bank,index);
                break;
            case 4:
                customer_info(bank,index);
                break;
               case 5:
                save_customer(bank);
                print_menu=false;
            default:
                break;
            }
        }
        catch (Invaliditem error)
        {
            cout << error.get_error() << '\n';
        }
    }
}

void raise_account(Bank & bank,int index)
{
     bank.get_cus().at(index)->raise_accounts();
}

void taking_account(Bank & bank, int index)
{
    try
    {
     bank.get_cus().at(index)->taking_account();
    }
    catch (Not_active_account unactive)
           {
               cout << unactive.show_notactive();
           }
    catch (Not_enough_inventory notenough)
           {
               cout << notenough.show_error();
           }

}

void account_information(Bank & bank, int index)
{

      bank.get_cus().at(index)->show_info();
}

void customer_info(Bank&bank, int index)
{
    bank.get_cus().at(index)->accounts_informations();
}

void switch_managermenu(Bank &bank)
{
     bool showmenu = true;

    while (showmenu)
    {

        try
      {

           int itemmenu= print_managermenu();
            switch (itemmenu)
        {
            case 1:

            vacation_request(bank);

                break;

            case 2:

            over_request(bank);

                break;

            case 3:

            show_info(bank);

                break;

            case 4:

            show_customerinfo(bank);

                break;

            case 5:

            creat_account(bank);

                break;

            case 6:

            remove_account(bank);

                break;
            case 7:

                show_employeeinfo(bank);

               break;
            case 8:
         add_employee(bank);
               break;
            case 9:
      remove_employee(bank);
               break;
            case 10:

            save_employee(bank);
            save_customer(bank);
            showmenu=false;
                break;
            default:
                break;
            }
      }

        catch (Invaliditem error)
        {
          cout<<error.get_error()<<'\n';
        }

}
}

int print_managermenu()
{
    int itemMenu;
    cout<<"1- vacation request\n";
    cout<<"2- over time request\n";
    cout<<"3- show information\n";
    cout<<"4- show  customer info \n";
    cout<<"5- creat new account\n";
    cout<<"6- remove account\n";
    cout<<"7)Print Employee Information " << '\n';
    cout<<"8)Adding New Employee " << '\n';
    cout<<"9)Removing Employee " << '\n';
    cout<<"10- Quit\n";
   cin>>itemMenu;
   if(itemMenu>10|| itemMenu<=0)
   {
       throw Invaliditem("Invalid value selected!!!");
   }
    return itemMenu;
}

void vacation_request(Bank & bank)
{
    try
    {
      bank.get_manager()->get_vacationtime();
    }
    catch (Incorrect error)
    {
       cout<< error.show_invalid();
    }
}

void over_request(Bank & bank)
{
    try
    {
        bank.get_manager()->get_overtime();
    }
    catch (Incorrect error)
    {
       cout<< error.show_invalid();
    }
}

void show_info(const Bank &bank)
{
    bank.get_manager()->print_info();

}

void show_customerinfo(Bank &bank)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);
    if(customer_index==-1)
    {
        cout<<"Customer not found";
    }
    if(customer_index>-1)
    {
        bank.get_manager()->show_customerinfo(bank.get_cus()[customer_index]) ;
    }
}

void creat_account( Bank &bank)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);
    if(customer_index==-1)
    {
       Customer *temp=new Customer;
        try{

        string first_name;
        string last_name;
        string user_name;
        string password;
        string  birth_day;
        string code;
            cout << "enter customer name:" << '\n';
            cin >> first_name;
            cout << "enter customer  last name:" << '\n';
            cin >> last_name;
            cout << "enter customer your birthday:" << '\n';
            cin >>birth_day;
            cout << "enter customer user name:" << '\n';
            cin >>user_name;
            cout << "enter customer password:" << '\n';
            cin >> password;
            cout<<"Enter customer national code:";
            cin>>code;
        temp->set_info(first_name,last_name,user_name,password,birth_day,code);
        bank.get_manager()->creat_newaccount(temp);
         bank.add_customer(temp);
       }
       catch(Incorrect error)
        {
           cout<< error.show_invalid()<<'\n';
           delete temp;
        }
       catch(Invalid_code error)
        {
            cout<<error.show_error()<<'\n';
            delete temp;
        }

    }
    if(customer_index>-1)
    {
        try {
              bank.get_manager()->creat_newaccount(bank.get_cus()[customer_index]);
        } catch (Incorrect error)
        {
            cout<<error.show_invalid()<<'\n';
        }

    }
}

void remove_account(Bank &bank)
{
    int customer_index;
    long long int n_code;
    cout<<"Enter customer national code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);

    bank.get_manager()->remove_account(bank.get_cus()[customer_index]);
}

void show_employeeinfo(Bank &bank)
{

    try
    {
         bank.get_manager()->showing_emp_info();
    }
    catch (Incorrect error)
    {
        cout<<error.show_invalid();
    }



}

void add_employee(Bank &bank)
{
    int customer_index;
    int n_code;
    cout<<"Enter employee code:";
    cin>>n_code;
    customer_index=bank.search_cus(n_code);
    if(customer_index==-1)
    {
       Employee *temp=new Employee;
        try{

        string first_name;
        string last_name;
        string user_name;
        string password;
        string  birth_day;
        int salary;
            cout << "Enter  Employee name:" << '\n';
            cin >> first_name;
            cout << "enter  Employee  last name:" << '\n';
            cin >> last_name;
            cout << "Enter  Employee  birthday:" << '\n';
            cin >>birth_day;
            cout << "Enter  Employee user name:" << '\n';
            cin >>user_name;
            cout << "Enter  Employee password:" << '\n';
            cin >> password;
            cout<<"Enter Employee salary"<< '\n';
            cin>>salary;
       temp->set_info(salary,n_code,first_name,last_name,user_name,password,birth_day);
       bank.get_manager()->adding_new_emp(temp);
       }
       catch(Incorrect error)
        {
           cout<< error.show_invalid()<<'\n';
           delete temp;
        }
    }
    if(customer_index>-1)
    {
     cout<<"you entered a duplicate code "<<'\n';
    }
}

void remove_employee(Bank &bank)
{
    try
    {
        bank.get_manager()->removing_emp();
    }
    catch (Incorrect error)
    {
        cout<<error.show_invalid();
    }

}


int main()
{
   Bank bank;
   bank.set_info(123,"meli");
   Manager * branch_manager=new Manager;
   branch_manager->set_managerinfo(1230000,110,"ali","saeedi","saeed","111111","1355/04/18",&bank);
   bank.add_manager(branch_manager);

//  load_employee(bank);
//  load_customer(bank);
   bool showmenu=true;

   while (showmenu)
   {

       try
       {
           int itemmenu=print_mainmenu();
           switch (itemmenu)
           {
           case 1:
               switch_employeemenu(bank);
               break;
           case 2:
              switch_customer_menu(bank);
               break;

           case 3:
               bank.remove_bank();
              showmenu=false;

               break;
           default:

               break;
           }
       }
       catch (Invaliditem error)
       {
         cout<<error.get_error();
       }

   }
  save_customer(bank);
//   save_employee(bank);
   return 0;
}
