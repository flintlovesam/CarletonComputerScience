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

#ifndef _Tracks_H
#define _Tracks_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "track.h"

class Tracks {
	/*
	Tracks represents a collection of compositions, specifically Track objects
	A Tracks container OWNS the Tracks within it.
	If the container is destroyed it deletes the Track objects it contains
	If a Track is removed from the container the Track object is deleted from heap space.
	*/
	public:
	Tracks(); 
	~Tracks(void){
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Tracks in this container
}


	Track * findByID(int anID){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

vector<Track*> getCollection(){return collection;}
	void add(Track & aTrack){
	collection.push_back(&aTrack);
}

	void remove(Track & aTrack){
	vector<Track*>::iterator index = findPosition(aTrack);
	if(index != collection.end()) {
		Track * theTrack = *index;
		collection.erase(index);
		delete theTrack; //free the memory of theTrack
	}
}

	void showOn(UI & aView){
  view.printOutput("Tracks:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());	  
}

	void showOn(UI & aView, int memberID) {
  view.printOutput("Track:");
  Track * track = findByID(memberID);
  if( track != NULL)
       view.printOutput(track->toString());	  
}


	private:
	vector<Track*> collection;
	vector<Track*>::iterator findPosition(Track & aTrack){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aTrack) return it;
	return collection.end();
}
};

#endif