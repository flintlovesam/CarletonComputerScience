#ifndef _person_h
#define _person_h

#include <iostream>
#include <cstring>
#include "date.h"
#include "emailaddress.h"


using namespace std;

class Person
{
public:
Person(const char * aName, const char * userID, const char * domain, Date aDate) {
//This constructor should create heap objects

	name = new char[strlen(aName) + 1];
    strcpy (name, aName);
	emailAddress = new EmailAddress(userID, domain);
	birthday = new Date(aDate);

	cout << "\nPerson(...) CREATING: ";
	printOn(cout);
}

Person(const Person &p){
	name = new char[strlen(p.name) + 1];
	strcpy (name, p.name);
	emailAddress = new EmailAddress(*(p.emailAddress));
	birthday = new Date(*(p.birthday));
}

Person & operator=(const Person &p){
	if(&p != this){
		cout << "\n" << p.name << " @ address: " << this << endl;
		delete birthday;
		delete emailAddress;
		delete [] name;
		name = new char[strlen(p.name) + 1];
		strcpy (name, p.name);
		emailAddress = new EmailAddress(*(p.emailAddress));
		birthday = new Date(*(p.birthday));
	}
	return *this;
}

~Person() {
   //notice the destructor expects these to be on the heap
	cout << "\n~Person() DELETING: ";
	printOn(cout);

    delete birthday;
	delete emailAddress;
	delete [] name;

}


void printOn(ostream & ostr) const {
  ostr << name << " (" << *birthday << ") " << *emailAddress;
}

private:
   char * name; //pointer to a person's name
   EmailAddress * emailAddress; //pointer to a person's email address
   Date * birthday; //pointer to persons birthday


}; //end class Person

ostream & operator<<(ostream & out, const Person & p) {
   p.printOn(out);
   return out;
}

#endif
