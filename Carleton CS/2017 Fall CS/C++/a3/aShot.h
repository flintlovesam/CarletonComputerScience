
#include <ostream>
#include <vector>
#include <string>
using namespace std;

	template <typename Temp>


class Vector {
	/*
	Vector represents a collection of Recording objects
	A Vector container OWNS the Recording objects within it.
	If the container is destroyed it deletes the Recording objects it contains
	If a Recording is removed from the container the Recording object is deleted from heap space.
	*/

	public:
	Vector(); 
	~Vector(void){
			for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Vector in this container

	}
	Temp * findByID(int anID){
	for (typename vector<Temp*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
	}
	typename vector<Temp*> getCollection(){
	for (typename vector<Temp*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aTemp) return it;
	return collection.end();

	}



	void add(Temp & aTemp){
			collection.push_back(&aTemp);
	}
	void remove(Temp & aTemp){
			typename vector<Temp*>::iterator index = findPosition(aTemp);
	if(index != collection.end()) { 
		Temp * theTemp = *index;
		collection.erase(index);
		delete theTemp; //free the memory of theRecording
	}
	}
	void showOn(UI & aView){
		  view.printOutput("Vector:");
  for(int i=0; i<collection.size(); i++){	   
       view.printOutput((*collection[i]).toString());
  }	
	}
	void showOn(UI & aView, int memberID){
		  view.printOutput("Temp:");
  Temp * temp = findByID(memberID);
  if( temp != NULL)
       view.printOutput(temp->toString());	  
	}
	
	private:
	typename vector<Temp*> collection;
	typename vector<Temp*>::iterator findPosition(Temp & aTemp);

	vector<Song*>::iterator findPosition(Song & aSong){
	for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
	if(*it == &aSong) return it;
	return collection.end();
	}



	vector<Track*>::iterator findPosition(Track & aTrack){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
	if(*it == &aTrack) return it;
	return collection.end();
}
	





};

#endif





















