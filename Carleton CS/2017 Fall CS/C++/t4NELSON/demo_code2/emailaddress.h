#ifndef _emailaddress_h
#define _emailaddress_h

#include <iostream>
#include <cstring>
using namespace std;

class EmailAddress{ 
//To represent someone's email address as a userid and domain
public:
EmailAddress( const char * aUserID, const char * aDomain) {
		userID = new char[strlen(aUserID) + 1];
		strcpy (userID, aUserID);
		domain = new char[strlen(aDomain) + 1];
		strcpy (domain, aDomain);
}
EmailAddress( const EmailAddress & anEmailAddress) {

//code not shown
		userID = new char[strlen(anEmailAddress.userID) + 1];
		strcpy (userID, anEmailAddress.userID);
		domain = new char[strlen(anEmailAddress.domain) + 1];
		strcpy (domain, anEmailAddress.domain);
}
EmailAddress & operator=(const EmailAddress & anEmailAddress) {

//code not shown 

        if(&anEmailAddress != this) {
		   delete [] userID;
		   delete [] domain;
		   userID = new char[strlen(anEmailAddress.userID) + 1];
		   strcpy (userID, anEmailAddress.userID);
		   domain = new char[strlen(anEmailAddress.domain) + 1];
		   strcpy (domain, anEmailAddress.domain);

		}
		return *this;
	}
~EmailAddress(){
         delete [] userID;
         delete [] domain;
}
void printOn(ostream & ostr) const {ostr << userID << "@" << domain;}

private:
	char * userID; //points to character array on the heap
	char * domain; //point to character array on the heap
};

ostream & operator<<(ostream & ostr, const EmailAddress & anEmailAddress) {
	anEmailAddress.printOn(ostr);  return ostr;
}

#endif