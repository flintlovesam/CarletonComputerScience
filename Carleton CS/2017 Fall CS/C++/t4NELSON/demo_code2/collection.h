
#ifndef _collection_h
#define _collection_h

#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

const int INITIAL_COLLECTION_SIZE = 12;

typedef Person T;
class  Collection {
public:
Collection (int len = INITIAL_COLLECTION_SIZE) { //constructor
	cout << "\nCollection(int) CREATE COLLECTION\n";
      mysize = len;
      buffer = new T*[len];
	     for(int i=0; i<mysize; i++) buffer[i] = NULL;
}

Collection(const Collection &c){
	mysize = c.mysize;
	buffer = new T*[mysize];
	for(int i=0; i<mysize; i++){
		buffer[i] = c.buffer[i];
	}
}


	Collection & operator=(const Collection &c){
		if(&c != this){
			mysize = 0;
			delete [] buffer;
			mysize = c.mysize;
			buffer = new T*[mysize];
			for(int i=0; i<mysize; i++){
				buffer[i] = c.buffer[i];
			}
		}
		return *this;
	}


~Collection (void) {
	  cout << "\n~Collection DELECT COLLECTION";
      delete  [] buffer;
}


int capacity (void) { return mysize; }

Collection & addElementAt(T & x, int index) {
			if(index < mysize) buffer[index] = &x;
            return *this;
	}

T& elementAt(int index) { return *buffer[index] ;}


void printOn(ostream & o) const {
//This method should print all the non NULL
//elements in the container


	o << "Contents:\n";
	for (int i=0; i<mysize; i++)
			if(buffer[i] != NULL)
			 o << *buffer[i] << "\n";


}

private:

     int mysize;
	 T **buffer;

}; //end class Collection


ostream & operator<<(ostream & o, const Collection & c) {
	c.printOn(o);
	return o;
}

#endif
