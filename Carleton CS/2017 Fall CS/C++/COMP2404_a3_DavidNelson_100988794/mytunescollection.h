/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Constributor:  David Nelson 100988794            */
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

#ifndef _MYTUNESCOLLETION_H
#define _MYTUNESCOLLETION_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "recording.h"
#include "user.h"
#include "track.h"
#include "song.h"

template <typename T>
class MyTunesCollection {
	/*
	MyTunesCollection represents a collection of compositions, specifically T objects
	A MyTunesCollection container OWNS the MyTunesCollection within it.
	If the container is destroyed it deletes the User objects it contains
	If a T is removed from the container the T object is deleted from heap space.
	*/
	public:
	MyTunesCollection(){};
	~MyTunesCollection(void){
		for(int i=0; i<collection.size(); i++)
		   delete collection[i]; //delete MyTunesCollection in this container
	}
	T * findByID(int anID) {
		for (typename std::vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
			if((*itr)->getID() == anID) return *itr;
		return NULL;
	};
	T * findByID(const string & anID) {
		for (typename std::vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
			if(((*itr)->getUserID()).compare(anID) == 0) return *itr;
		return NULL;
	};
	vector<T*> getCollection(){return collection; //return copy of collection
	};
	void add(T & x){
		collection.push_back(&x);
	};
	void remove(T & x){
		typename std::vector<T*>::iterator itr = findPosition(x);
		if(itr != collection.end()) {
			T * theX = *itr;
			collection.erase(itr);
			delete theX; //free the memory of theX
		}
	};
	void showOn(UI & view) {
	  view.printOutput("Objects in this Container:");
	  for(int i=0; i<collection.size(); i++)
	       view.printOutput((*collection[i]).toString());
	};
	void showOn(UI & view, const string & memberID) {
	  view.printOutput("Objects in this Container:");
	  T * t = findByID(memberID);
	  if( t != NULL)
	       view.printOutput(t->toString());
	};
	void showOn(UI & view, const int & memberID) {
	  view.printOutput("Objects in this Container:");
	  T * t = findByID(memberID);
	  if( t != NULL)
	       view.printOutput(t->toString());
	};




	private:
	vector<T*> collection;
	typename std::vector<T*>::iterator findPosition(T & x)  {
		for (typename std::vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
			if(*it == &x) return it;
		return collection.end();
	};
};

#endif
