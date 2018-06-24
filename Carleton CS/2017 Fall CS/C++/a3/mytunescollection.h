/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors:  Sam Diamantstein #101060342       */
/*  Date:  NOV 16 -2017                              */
/*                                                   */
/*  (c) Nov 2017                                     */
/*                                                   */
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

template <typename Temp>

class MyTunesCollection {
public:
	MyTunesCollection(){};
	~MyTunesCollection(void){
		for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Vector in this container

	}
	Temp * findByID(int anID){
		for (typename std::vector<Temp*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
		return NULL;
	}
	Temp * findByID(const string & anID){
		for (typename std::vector<Temp*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(((*it)->getUserID()).compare(anID) == 0) return *it;
		return NULL;
	};


	typename std::vector<Temp*> getCollection(){return collection;
	};



	void add(Temp & aTemp){
		collection.push_back(&aTemp);
	}
	void remove(Temp & aTemp){
		typename std::vector<Temp*>::iterator index = findPosition(aTemp);
		if(index != collection.end()) {
			Temp * theTemp = *index;
			collection.erase(index);
			delete theTemp; //free the memory of theRecording
		}
	}
	void showOn(UI & view){
		view.printOutput("Vector:");
		for(int i=0; i<collection.size(); i++){
			view.printOutput((*collection[i]).toString());
		}
	}

	void showOn(UI & view, const string & memberID){
		view.printOutput("Temp:");
		Temp * temp = findByID(memberID);
		if( temp != NULL)
		view.printOutput(temp->toString());
	}

	void showOn(UI & view, const int memberID){
		view.printOutput("Temp:");
		Temp * temp = findByID(memberID);
		if( temp != NULL)
		view.printOutput(temp->toString());
	}

private:
	vector<Temp*>collection;
	typename std::vector<Temp*>::iterator findPosition(Temp & x){
		for (typename std::vector<Temp*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &x) return it;
		return collection.end();
	};
};

#endif
