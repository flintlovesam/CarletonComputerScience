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

#ifndef _SONGS_H
#define _SONGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "song.h"

class Songs {
	/*
	Songs represents a collection of compositions, specifically Song objects
	A Songs container OWNS the songs within it.
	If the container is destroyed it deletes the Song objects it contains
	If a song is removed from the container the Song object is deleted from heap space.
	*/
	public:
	Songs(); 
	~Songs(void){
			for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete songs in this container
	}
	Song * findByID(int anID){
	for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
	}
	void add(Song & aSong){
	collection.push_back(&aSong);
}
	void remove(Song & aSong){
	vector<Song*>::iterator index = findPosition(aSong);
	if(index != collection.end()) {
		Song * theSong = *index;
		collection.erase(index);
		delete theSong; //free the memory of theSong
	}
}
	void showOn(UI & aView){
  view.printOutput("Songs:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());	  
}


	void showOn(UI & aView, int memberID) {
  view.printOutput("Song:");
  Song * song = findByID(memberID);
  if( song != NULL)
       view.printOutput(song->toString());	  
}




	private:
	vector<Song*> collection;
	vector<Song*>::iterator findPosition(Song & aSong){
	for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aSong) return it;
	s
}


};

#endif