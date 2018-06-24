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

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
#include "str_util.h"
#include "mytunes.h"
#include "UI.h"
#include "command.h"

MyTunes::MyTunes():view(this)
{
	nextAvailableSongID = 1;
	nextAvailableRecordingID = 1;
	nextAvailableTrackID = 1;
}

void MyTunes::run()
{
	//start user interface
	view.run();

}
void MyTunes::executeCommand(Command cmd){

    //execute application (non UI shell) commands
    //These are the commands that affect the data model
    //or retrieve contents from the data model
	if(cmd.isCommand(CMD_ADD)) executeCMDADD(cmd);
	else if(cmd.isCommand(CMD_DELETE)) executeCMDDELETE(cmd);
	else if(cmd.isCommand(CMD_SHOW)) executeCMDSHOW(cmd);
}

//CMD SHOW COMMANDS
void MyTunes::executeCMDSHOW(Command cmd){
    //show recordings
    //show recordings -r recording_id
    //show songs
    //show songs -s song_id
    //show tracks
    //show tracks -t track_id
    //show users
    //show users -u user_id

	enum arguments {SHOW, COLLECTION, FLAG, MEMBER_ID};

	if(cmd.isTokenAt(COLLECTION, "songs") && !cmd.hasToken("-s"))
		songs.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "songs") && cmd.hasToken("-s"))
		songs.showOn(view, stoi(cmd.getToken("-s")));
	else if(cmd.isTokenAt(COLLECTION, "recordings") && !cmd.hasToken("-r"))
		recordings.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "recordings") && cmd.hasToken("-r"))
		recordings.showOn(view, stoi(cmd.getToken("-r")));
	else if(cmd.isTokenAt(COLLECTION, "tracks") && !cmd.hasToken("-t"))
		tracks.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "tracks") && cmd.hasToken("-t"))
		tracks.showOn(view, stoi(cmd.getToken("-t")));
	else if(cmd.isTokenAt(COLLECTION, "users") && !cmd.hasToken("-u"))
		users.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "users") && cmd.hasToken("-u"))
		users.showOn(view, cmd.getToken("-u"));
    else view.printOutput("EXECUTING: " + cmd.getCommandString());
}

//CMD ADD COMMANDS
void MyTunes::executeCMDADD(Command cmd){
    //add recording
    //add -r id title artist producer year
    //add -r 103 "Beatles For Sale" "Beatles" "George Martin" 1964
    //add -r ? "Beatles For Sale" "Beatles" "George Martin" 1964
    //add song
    //add -s sid title composer //add song
    //add -s 1001 "Misery" "Paul McCartney, John Lennon"
    //add -s ? "Misery" "Paul McCartney, John Lennon"
    //add track
    //add -t trackID albumID songID track_number
    //add -t 12 100 1000 1
	//add -t 12 null 1000 1 //add track not on recording
    //add -t ? 100 1000 1
	//add -t ? null 1000 1  //add track not on recording
    //add user
    //add -u user_id name
    //add -u ajones "Anne Jones"
    //add playlist
    //add -p user_id, playlist_name
    //add -p ajones "Driving Songs"
    //add playlist track
    //add -l user_id playlist_name track_id
    //add -l gjones "mysongs" 6

	     if(cmd.hasToken("-s")) executeAddSong(cmd);
	else if(cmd.hasToken("-r")) executeAddRecording(cmd);
	else if(cmd.hasToken("-t")) executeAddTrack(cmd);
	else if(cmd.hasToken("-u")) executeAddUser(cmd);
	else if(cmd.hasToken("-p")) executeAddPlaylist(cmd);
	else if(cmd.hasToken("-l")) executeAddPlaylistTrack(cmd);
	else view.printOutput("EXECUTING: " + cmd.getCommandString());
}

//Individual Add Commands
void MyTunes::executeAddSong(Command cmd){
    //add song
    //add -s sid title composer //add song
    //add -s 1001 "Misery" "Paul McCartney, John Lennon"
    //add -s ? "Misery" "Paul McCartney, John Lennon"
	enum arguments {ADD, _S, ID, TITLE, COMPOSER};

	if(validateID(cmd, ID)) return;
	int id = -1;
	if(cmd.isTokenAt(ID,"?")) id = nextAvailableSongID++;
    else id = stoi(cmd.getToken(ID));

	if(nextAvailableSongID <= id) nextAvailableSongID = id + 1;

	Song* song = new Song(
	  cmd.getToken(TITLE),
	  cmd.getToken(COMPOSER),
	  id
	);
	if(song == NULL) return;
	songs.add(*song);
	view.printOutput("EXECUTING: ADD SONG " + cmd.getCommandString());
}

void MyTunes::executeAddRecording(Command cmd){
    //add recording
    //add -r id title artist producer year
    //add -r 103 "Beatles For Sale" "Beatles" "George Martin" 1964
    //add -r ? "Beatles For Sale" "Beatles" "George Martin" 1964
	enum arguments {ADD, _R, ID, TITLE, ARTIST, PRODUCER, YEAR};

	if(validateID(cmd, ID)) return;

	int id = -1;
	if(cmd.isTokenAt(ID,"?")) id = nextAvailableRecordingID++;
    else id = stoi(cmd.getToken(ID));
	if(nextAvailableRecordingID <= id) nextAvailableRecordingID = id + 1;

	Recording* recording = new Recording(
	  cmd.getToken(TITLE),
	  cmd.getToken(ARTIST),
	  cmd.getToken(PRODUCER),
	  cmd.getToken(YEAR),
	  id
	);
	if(recording == NULL) return;
	recordings.add(*recording);
	view.printOutput("EXECUTING: ADD RECORDING " + cmd.getCommandString());
}
void MyTunes::executeAddTrack(Command cmd){
    //add track
    //add -t trackID albumID songID track_number
    //add -t 12 100 1000 1
	//add -t 12 null 1000 1 //add track not on recording
    //add -t ? 100 1000 1
	//add -t ? null 1000 1  //add track not on recording

	enum arguments {ADD, _T, ID, RECORDING_ID, SONG_ID, TRACK_NUMBER};

	if(validateID(cmd, ID)) return;
	if(!cmd.isValidIndex(cmd.getToken(SONG_ID))) return;
	if(!cmd.isValidIndex(cmd.getToken(TRACK_NUMBER))) return;

	int id = -1;
	if(cmd.isTokenAt(ID,"?")) id = nextAvailableTrackID++;
    else id = stoi(cmd.getToken(ID));
	if(nextAvailableTrackID <= id) nextAvailableTrackID = id + 1;

	Recording * recording;
	//tracks don't have to be associated with recordings
	if(cmd.getToken(RECORDING_ID).compare("null") == 0) recording = NULL;
	else {
		if(!cmd.isValidIndex(cmd.getToken(RECORDING_ID))) return;
		recording = recordings.findByID(stoi(cmd.getToken(RECORDING_ID)));
	}

	int track_number = stoi(cmd.getToken(TRACK_NUMBER));
	Track* track = new Track(
	  id, songs.findByID(stoi(cmd.getToken(SONG_ID)))
	);
	if(track == NULL) return;
	tracks.add(*track);
	if(recording != NULL) recording->addTrack(*track, track_number);
	view.printOutput("EXECUTING: ADD TRACK " + cmd.getCommandString());
}
void MyTunes::executeAddUser(Command cmd){
    //add user
    //add -u user_id name
    //add -u ajones "Anne Jones"
	enum arguments {ADD, _U, USERID, NAME};

	User* user = new User(
	  cmd.getToken(USERID),
	  cmd.getToken(NAME)
	  );

	if(user == NULL) return;
	users.add(*user);
	view.printOutput("EXECUTING: ADD USER " + cmd.getCommandString());
}
void MyTunes::executeAddPlaylist(Command cmd){
    //add playlist
    //add -p user_id, playlist_name
    //add -p ajones "Driving Songs"

	enum arguments {ADD, _P, USERID, PLAYLIST_NAME};

	User* user = users.findByID(cmd.getToken(USERID));
	if(user == NULL) return;
	Playlist * playlist = new Playlist(cmd.getToken(PLAYLIST_NAME));
	if(playlist == NULL) return;
	user->addPlaylist(*playlist);
	view.printOutput("EXECUTING: ADD PLAYLIST " + cmd.getCommandString());
}
void MyTunes::executeAddPlaylistTrack(Command cmd){
    //add playlist track
    //add -l user_id playlist_name track_id
    //add -l gjones "mysongs" 6

	enum arguments {ADD, _L, USERID, PLAYLIST_NAME, TRACK_ID};

	if(!cmd.isValidIndex(cmd.getToken(TRACK_ID))) return;

	User * user = users.findByID(cmd.getToken(USERID));
	if(user == NULL) return;
	Playlist * playlist = user->findPlaylist(cmd.getToken(PLAYLIST_NAME));
	if(playlist == NULL) return;
	Track * track = tracks.findByID(stoi(cmd.getToken(TRACK_ID)));
	if(track == NULL) return;
	playlist->addTrack(*track);

}

//CMD DELETE COMMANDS
void MyTunes::executeCMDDELETE(Command cmd){
	if(cmd.hasToken("-u") && cmd.hasToken("-p") && cmd.hasToken("-t") && cmd.hasToken("-GLOBAL")){
	    //Cascaded GLOBAL Delete
	    string newCommandString = "delete -t " + cmd.getToken("-t");
	    Command c = Command(newCommandString);
		executeDeleteTrack(c);
	}
	else if(cmd.hasToken("-u") && cmd.hasToken("-p") && cmd.hasToken("-t"))
		executeDeleteUserPlaylistTrack(cmd);
	else if(cmd.hasToken("-u") && cmd.hasToken("-p"))
		executeDeleteUserPlaylist(cmd);
	else if(cmd.hasToken("-u"))
		executeDeleteUser(cmd);
	else if(cmd.hasToken("-r"))
		executeDeleteRecording(cmd);
	else if(cmd.hasToken("-t"))
		executeDeleteTrack(cmd);
    else if(cmd.hasToken("-s"))
		executeDeleteSong(cmd);
	else view.printOutput("EXECUTING: " + cmd.getCommandString());
}
void MyTunes::executeDeleteRecording(Command cmd){
	//delete -r 1000
	enum arguments {DELETE, _R, ID};

	if(validateID(cmd, ID)) return;

	Recording* recording = recordings.findByID(stoi(cmd.getToken(ID)));
	if(recording == NULL) return;
	recordings.remove(*recording);
	view.printOutput("EXECUTING: DELETE RECORDING " + cmd.getCommandString());
}
void MyTunes::executeDeleteUser(Command cmd){
	//delete -u ajones
	enum arguments {DELETE, _U, USER_ID};

	User* user = users.findByID(cmd.getToken(USER_ID));
	if(user == NULL) return;
	users.remove(*user);
	view.printOutput("EXECUTING: DELETE USER " + cmd.getCommandString());
}
void MyTunes::executeDeleteUserPlaylist(Command cmd){
	//delete -u ajones -p favourites
	enum arguments {DELETE, _U, USER_ID, _P, PLAYLIST_NAME};
	string user_id = cmd.getToken("-u");
	string playlistName = cmd.getToken("-p");
	User* user = users.findByID(user_id);
	if(user == NULL) return;
	Playlist * playlist = user->findPlaylist(playlistName);
	if(playlist == NULL) return;
	user->removePlaylist(*playlist);
	view.printOutput("EXECUTING: DELETE USER PLAYLIST " + cmd.getCommandString());
}
void MyTunes::executeDeleteUserPlaylistTrack(Command cmd){
	//delete -u ajones -p favourites -t 70
	//delete -u ajones -p favourites -t 70 -GLOBAL
	enum arguments {DELETE, _U, USER_ID, _P, PLAYLIST_NAME, _T, TRACK_ID};
	string user_id = cmd.getToken("-u");
	string playlistName = cmd.getToken("-p");
	string trackIDstring = cmd.getToken("-t");
    if(!cmd.isValidIndex(trackIDstring)) return;
    int trackIndex = stoi(trackIDstring);
	User* user = users.findByID(user_id);
	if(user == NULL) return;
	Playlist * playlist = user->findPlaylist(playlistName);
	if(playlist == NULL) return;
	Track * track = tracks.findByID(trackIndex);
	if(track == NULL) return;
	playlist->removeTrack(*track);
	view.printOutput("EXECUTING: DELETE USER PLAYLIST TRACK " + cmd.getCommandString());
}
void MyTunes::executeDeleteTrack(Command cmd){
	//delete -t track_id
	enum arguments {DELETE, _T, TRACK_ID};
	string trackIDstring = cmd.getToken("-t");
    if(!cmd.isValidIndex(trackIDstring)) return;
	int trackIndex = stoi(trackIDstring);
	Track * track = tracks.findByID(trackIndex);
	if(track == NULL) return;

	//PERFORM A CASCADED DELETE
	vector<User*> theUsers = users.getCollection();
	for(vector<User*>::iterator itr = theUsers.begin(); itr != theUsers.end(); itr++){
		User* user = *itr;
		user->removeTrack(*track);
	}
	vector<Recording*> theRecordings = recordings.getCollection();
	for(vector<Recording*>::iterator itr = theRecordings.begin(); itr != theRecordings.end(); itr++){
		Recording* recording = *itr;
		recording->removeTrack(*track);
	}

	tracks.remove(*track);

}

void MyTunes::executeDeleteSong(Command cmd){
	//delete -s 1000
	enum arguments {DELETE, _S, ID};

	if(validateID(cmd, ID)) return;

	Song* song = songs.findByID(stoi(cmd.getToken(ID)));
	if(song == NULL) return;

	//Perform Cascaded Delete
	vector<Track*> theTracks = tracks.getCollection();
	for(vector<Track*>::iterator itr = theTracks.begin(); itr != theTracks.end(); itr++){
		Track* track = *itr;
		Song* trackSong = track->getSong();
		if(song == trackSong){
	       //Cascaded GLOBAL Delete
	       string newCommandString = "delete -t " + to_string(track->getID());
	       Command c = Command(newCommandString);
		   executeDeleteTrack(c);
		}
	}
	songs.remove(*song);
	view.printOutput("EXECUTING: DELETE SONG " + cmd.getCommandString());
}

bool MyTunes::validateID(Command cmd, int ID){
	return !cmd.isValidIndex(cmd.getToken(ID));
}
