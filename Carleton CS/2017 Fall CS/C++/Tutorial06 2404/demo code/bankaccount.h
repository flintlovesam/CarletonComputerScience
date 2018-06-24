#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
        BankAccount ( const string & name ="unknown",
                      const string & mr = "Miss", double aBalance =0.0);        
        void print(ostream& o) const;

private:
     string title;
     string owner;
     double balance;
};

ostream& operator<< (ostream& o, const BankAccount &b);  //notice pass by const reference