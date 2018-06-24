#include <iostream>
#include <cstring>
#include "date.h"
#include "emailaddress.h"
#include "person.h"
#include "collection.h"

using namespace std;


void runApp(){

	Person alan("Alan Day", "alan", "scs.carleton.ca", Date(2,7,1961));
    Person sue("Sue Smith", "Sue", "hotmail.com", Date(30, 6, 1974));
    Person lou("Lou Nel", "ldnel", "scs.carleton.ca", Date(29,7, 1977));

	//UNCOMMENT THIS FOR EXERCISE 1
	//test copy construction of person
	cout << "\n\nTest Person copy construction";
	Person temp = alan;

	//test assignment operator of person
	cout << "\n\nTest Person assignment";
	temp = lou;
	cout << "\n" << temp;


	/* UNCOMMENT THIS FOR EXERCISE 2
	cout << "\n\n";
    Collection people;
    people.addElementAt(alan,0).addElementAt(sue,1).addElementAt(lou,2);
    cout << people;

    //test initialization (copy construction) of collection
	cout << "\n\nTest Collection copy construction";
    Collection  morePeople = people;   //same as Collection morePeople(people);
	cout << morePeople;

	//test assignment operator for collections
	cout << "\n\nTest Collection assignment";
    Collection  others;
	cout << others;
    others = people;
    cout << others;
	*/

}

//The main program and its output
int main( ) {

	runApp();

    //Force Console window to remain open until user types ENTER
 	const int MAX_SIZE = 80;
	char response[MAX_SIZE];
	//keep console open until user types a key and enter
	cout <<"\n\n" << "Press ENTER to continue";
	cin.getline(response, MAX_SIZE);
    return 0;


}
