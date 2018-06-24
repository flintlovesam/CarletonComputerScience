/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _Users_H
#define _Users_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "user.h"



class Users {
	/*
	Users represents a collection of compositions, specifically User objects
	A Users container OWNS the Users within it.
	If the container is destroyed it deletes the User objects it contains
	If a User is removed from the container the User object is deleted from heap space.
	*/
	public:
	Users(){}
	~Users(void){
	for(int i=0; i<collection.size(); i++)
	   delete collection[i]; //delete Users in this container
}


	User * findByID(int anID){
	for (vector<User*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
		if((*itr)->getID() == anID) return *itr;
	return NULL;
}


	User * findByUserID(const string & aUserID){
	for (vector<User*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
		if(((*itr)->getUserID()).compare(aUserID) == 0) return *itr;
	return NULL;
}
	vector<User*> getCollection(){
	return collection; //return copy of collection
}

	void add(User & aUser){
	collection.push_back(&aUser);
}
	void remove(User & aUser){
	vector<User*>::iterator itr = findPosition(aUser);
	if(itr != collection.end()) {
		User * theUser = *itr;
		collection.erase(itr);
		delete theUser; //free the memory of theUser
	}
}
	void showOn(UI & aView){
  view.printOutput("Users:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());	  
}

	void showOn(UI & aView, const string & memberID){
  view.printOutput("User:");
  User * user = findByUserID(memberID);
  if( user != NULL)
       view.printOutput(user->toString());	  
}
	private:
	vector<User*> collection;
	vector<User*>::iterator findPosition(User & aUser);
};

#endif