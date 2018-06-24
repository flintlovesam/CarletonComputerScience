#include <iostream>
using namespace std;

class Date {
public:
        Date ( int aDay, int aMonth, int aYear);
        void print(ostream& o) const;

private:
   int day;
   int month;
   int year;

};

ostream& operator<< (ostream& o, const Date &b); 
