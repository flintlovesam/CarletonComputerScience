
#include <iostream>
#include <typeinfo>

using namespace std;


typedef BankAccount T;



class  VectorOfBankAccount {
 public:
  VectorOfBankAccount (int len = 100){
    cout << "Vector(int)\n";
    mysize = len;
    buffer = new  T*[len];
  }
  
  ~VectorOfBankAccount (void){ 
     cout << "~Vector(void)\n";
     delete  [] buffer; 
   }
   int capacity (void) const { 
      return mysize; 
   }
   void addElementAt(T & x, int index){ 
      if(index < mysize) buffer[index] = &x;
   }
   T & elementAt(int index) const { 
      return *buffer[index] ;
   }
   
  private:
  int mysize;
  T **buffer;
}; 