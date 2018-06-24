#include <iostream>
using namespace std;
#include "date.h"

Date::Date ( int aDay, int aMonth, int aYear)
        {
           day = aDay;
		   month = aMonth;
		   year = aYear;
        }
void Date::print(ostream& o) const
        {  o <<"date:"<< day << "/ "
             <<month << "/ " << year; }

ostream& operator<< (ostream& o, const Date &b)
{
 b.print(o);
 o << "\n";
 return o;
} 