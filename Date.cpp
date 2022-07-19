#include "Date.h"
#include "Incorrect.h"

Date::Date()
{

}
void Date::convert_date(string date)
{    int d_day;
     int d_month;
     int d_year;
      for(int i=0;i<date.size();i++)
     {
         if(date[i]>57||date[i]<47)
         {
             throw Incorrect("incurrect date !");
         }

     }
    int slash_pos=date.find('/');
     d_year=stoi(date.substr(0,slash_pos));
     date=date.substr(slash_pos+1);
     slash_pos=date.find('/');
     d_month=stoi(date.substr(0,slash_pos));
     d_day=stoi(date.substr(slash_pos+1));
      set_date(d_day, d_month, d_year);

}
void Date::set_date(int d_day,int d_month, int d_year)
{

    bool result;
    result=check_date( d_day, d_month, d_year);
     if(result)
     {
         day=d_day;
         month=d_month;
         year=d_year;
     }
     if(!result)
     {
         throw Incorrect("incorrect date !");
     }
}
bool Date::check_date(int d,int m,int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 )
    {
        return false;
    }

    else if((m<7 && d>31) || (m>6 && d>30))
    {
        return false;
    }

   else{
        return true;
    }
}
void Date::print_date() const
{
   cout<<year<<"/"<<month<<"/"<<day<<endl;
}
