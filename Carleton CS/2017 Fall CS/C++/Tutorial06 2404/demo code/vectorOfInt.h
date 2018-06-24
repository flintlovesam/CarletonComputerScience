#include <iostream>
#include <typeinfo>

using namespace std;

class  VectorOfInt {
 public:
  VectorOfInt (int len = 100){
    cout << "Vector(int)\n";
    mysize = len;
    buffer = new  int*[len];
  }
  
  ~VectorOfInt (void){ 
     cout << "~Vector(void)\n";
     delete  [] buffer; 
   }
   int capacity (void) const { 
      return mysize; 
   }
   void addElementAt(int & x, int index){ 
      if(index < mysize) buffer[index] = &x;
   }
   int & elementAt(int index) const { 
      return *buffer[index] ;
   }
   
  private:
  int mysize;
  int **buffer;
}; 