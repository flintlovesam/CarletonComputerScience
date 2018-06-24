#include <iostream>
using namespace std;
#include "date.h"
#include "bankaccount.h"
#include "vector.h" 


const int MAX_BANK_ACCTS = 80;

int main (void)
{
Vector<BankAccount> accounts (MAX_BANK_ACCTS);  
Vector<Date> dates;
Vector<int> someInts;

  Date day1 = Date(1,1,1970);
  Date day2 = Date(12,11,2005);

  dates.addElementAt(day1,0);
  dates.addElementAt(day2,1);

  cout << dates.elementAt(0);
  cout << dates.elementAt(1);

   int x = 5, y=6, z=7;
   someInts.addElementAt(x,0);

   BankAccount b1("Sue", "Miss", 100.00);
   BankAccount b2("Lou", "Mr", 500.00);
 
   accounts.addElementAt(b1, 0);
   accounts.addElementAt(b2, 1);
 
   for(int i = 0; i<2; i++)
     cout << accounts.elementAt(i);

   if (&accounts.elementAt(0) == &b1) 
	  cout << "the objects are the same!!!\n";
   else 
	  cout << "the objects are copied\n";

   // BankAccount b3("Mary", 1000.00); would be an error
   BankAccount b3("Mary");
 
   accounts.elementAt(1) = b3;
 
   //v.elementAt(2) = BankAccount("Sam", "Mr", 300.00); //ERROR WHY?
 
   for(int i = 0; i<2; i++)
     cout << accounts.elementAt(i);
 
 return 0;
} 