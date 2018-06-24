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

#ifndef _RECORDINGS_H
#define _RECORDINGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "recording.h"

class Recordings {
	/*
	Recordings represents a collection of Recording objects
	A Recordings container OWNS the Recording objects within it.
	If the container is destroyed it deletes the Recording objects it contains
	If a Recording is removed from the container the Recording object is deleted from heap space.
	*/
	public:
	Recordings(); 
	~Recordings(void){
			for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Recordings in this container

	}
	Recording * findByID(int anID){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
	}
	vector<Recording*> getCollection(){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aRecording) return it;
	return collection.end();

	}



	void add(Recording & aRecording){
			collection.push_back(&aRecording);
	}
	void remove(Recording & aRecording){
			vector<Recording*>::iterator index = findPosition(aRecording);
	if(index != collection.end()) { 
		Recording * theRecording = *index;
		collection.erase(index);
		delete theRecording; //free the memory of theRecording
	}
	}
	void showOn(UI & aView){
		  view.printOutput("Recordings:");
  for(int i=0; i<collection.size(); i++){	   
       view.printOutput((*collection[i]).toString());
  }	
	}
	void showOn(UI & aView, int memberID){
		  view.printOutput("Recording:");
  Recording * recording = findByID(memberID);
  if( recording != NULL)
       view.printOutput(recording->toString());	  
	}
	
	private:
	vector<Recording*> collection;
	vector<Recording*>::iterator findPosition(Recording & aRecording);
};

#endif





















