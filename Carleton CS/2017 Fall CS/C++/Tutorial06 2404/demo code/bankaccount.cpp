#include <iostream>
#include <string>
using namespace std;
#include "bankaccount.h"

BankAccount::BankAccount ( const string & name,
                      const string & mr, double aBalance)
{
   title = mr;
   owner =  name;
   balance = aBalance;
}
void BankAccount::print(ostream& o) const
{  o <<"who:"<< title << " "
             << owner<<" how much="<< balance<<"\n"; 
}

ostream& operator<< (ostream& o, const BankAccount &b)
{
 b.print(o);
 o << endl;
 return o;
} 