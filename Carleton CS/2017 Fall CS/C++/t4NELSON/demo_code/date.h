#ifndef _date_h
#define _date_h

#include <iostream>
#include <cstring>
using namespace std;

class Date{ //this class is complete
//This class represents a date

public:
	  Date(int aDay, int aMonth, int aYear) : day(aDay), month(aMonth), year(aYear) {} 
	  Date(const Date & aDate) :  day(aDate.day), month(aDate.month), year(aDate.year) {};
	  void printOn(ostream & out) const {out << day <<"/" << month << "/" << year;}
private: 
	  int day, month, year; 
};
ostream & operator<<(ostream & ostr, const Date & d) {
	  d.printOn(ostr);
	  return ostr;
}

#endif
 