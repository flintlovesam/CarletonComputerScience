#include <iostream>
#include <typeinfo>

using namespace std;

class  VectorOfDate {
 public:
  VectorOfDate (int len = 100){
    cout << "Vector(int)\n";
    mysize = len;
    buffer = new  Date*[len];
  }
  
  ~VectorOfDate (void){ 
     cout << "~Vector(void)\n";
     delete  [] buffer; 
   }
   int capacity (void) const { 
      return mysize; 
   }
   void addElementAt(Date & x, int index){ 
      if(index < mysize) buffer[index] = &x;
   }
   Date & elementAt(int index) const { 
      return *buffer[index] ;
   }
   
  private:
  int mysize;
  Date **buffer;
}; 