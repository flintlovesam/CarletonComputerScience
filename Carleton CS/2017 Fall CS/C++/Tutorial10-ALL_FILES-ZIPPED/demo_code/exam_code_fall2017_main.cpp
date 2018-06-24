#include <iostream>
using namespace std;
/*
The following is code for an OrderedCollection container and its related iterator.
 The container has a capacity determined by a constructor parameter. The container does not grow.
 Code that adds elements to the container ensures that the capacity of the container is never exceeded.
 An attempt to add an item to a full container is ignored by the add() methods.

This code will be used as the basis of the programming part of the final exam.
Do the following exercises to become completely familiar with this c++ code.

1)The Bankaccount class currently only has a "balance" property. Modify the code so that BankAccouts
have a string property "owner" as well.
Modify how BankAccount objects print to, say, "Lou: $100" instead of just "$100".

2)The Bankaccount class currently implement == and != operators that are based on "identity". That
is, the actual addresses of objects are compared. We want to implement
these operators as "equality" rather than "identity" operators.
Modify the operators so that A == B is
true if and only if bankaccounts A and B have equivalent owner strings and have the equal balances.
That is, we aren't seeing if A and B refer to the same object but rather that the objects are "equal"
because their owner strings and balances are equal. (Also modify the != operator).

3)Modify the OrderedCollection class so that it behaves like an OrderedSet. The difference is that
a set would not be allowed to contain duplicates (based on the == operator of items stored in the
set). Here the add methods need to be changed so that items will not be added if
an equivalent item is already in the set. (Note for this exercise you don't actually have to change
the name of the class to OrderedSet, though that would be ideal).

4)Modify the container so that it grows if it gets full. If its internal array gets full a new one should be allocated that is bigger, items copied over, and the old one properly deteted.

Exam Practice: finally the following practice exercise is highly recommended for the final exam:
Take the demo code and remove various method bodies and then re-code them based
on their signatures.
You should be able to remove the code from any method and code it.
(On the exam this kind of activity will be done by offering you five
alternative implementations and asking you to choose the right one.)
*/

template <class T> class OrderedIterator; //forward declaration

template <class T>
class OrderedCollection {
//    =================
  friend class OrderedIterator<T>;
  const int capacity; //maximum size of the container
  int size; //number of actual elements in the container
  T **buffer; //pointer to memory for holding elements

  public:
  OrderedCollection(int aCapacity = 100);
  OrderedCollection(const OrderedCollection<T> & c);
  ~OrderedCollection();

  typedef OrderedIterator<T> iterator;

  int getSize() const {return size;} //answer number of elements
  bool isFull()const {return size == capacity;} //answer if full

  OrderedCollection<T> & addLast( T & element); //add to end
  OrderedCollection<T> & addFirst( T & element); //add to front
  T & removeLast();//remove last element
  T & removeFirst(); //remove first element
  OrderedCollection<T> & remove(const T & element); //remove all items == element
  iterator begin(void); //provide an start iterator
  iterator end(void); //provide an end iterator

  void print(){
	  cout << "Collection\n";
	  cout << "==========\n";
	  for(int i=0; i<size; i++){
    //  cout << owner;
       cout << *buffer[i];
}
  }

};

template <class T>
class OrderedIterator { //The iterator class
//    ===============
	int index;  //location in the container being iterated
	OrderedCollection<T> & s; //container being iterated

	public:
	OrderedIterator(OrderedCollection<T> & set, int position = 0);
	OrderedIterator<T> & operator++(int); //to advance to next element
	T & operator*(); //to get element
	bool operator==(const OrderedIterator<T> & iter);
	bool operator!=(const OrderedIterator<T> & iter);
};


//Constructor Implementations
template <class T>
OrderedCollection<T>::OrderedCollection(int aCapacity)
    : capacity(aCapacity),size(0), buffer(new T*[aCapacity]) {}



template <class T>
OrderedCollection<T>::OrderedCollection(const OrderedCollection<T> & c)
  : capacity(c.capacity), size(c.size), buffer(new T*[c.capacity]) {
	  for(int i=0; i< capacity; i++) buffer[i] = c.buffer[i];
  }

template <class T>
OrderedCollection<T>::~OrderedCollection() {delete [] buffer; }
//Method Implementations

template <class T>
OrderedCollection<T> &  OrderedCollection<T>::addLast(T & element){

  for(OrderedCollection<T>::iterator itr = buffer.begin(); itr != buffer.end(); itr++){

if(*itr == element){
  cout >> *this;
  return *this;}

  }

   if(size < capacity) buffer[size++] = &element;

    return *this;

}    //element ! == buffer[i]

template <class T>
OrderedCollection<T> & OrderedCollection<T>::addFirst(T & element){

	if(size < capacity){     // element ! == buffer[i]
        size++;
	    for(int i=size-1; i>0; i--) buffer[i] = buffer[i-1];
      // if(element ! == buffer[i]){buffer[0] = &element;}
		buffer[0] = &element;
	}
	return *this;
}

template <class T>
T & OrderedCollection<T>::removeLast(){
  return * buffer[size--];
}

template <class T>
T & OrderedCollection<T>::removeFirst(){
	T* temp;
	size--;
	temp = buffer[0];
	for(int i=0; i<size; i++)	buffer[i] = buffer[i+1];
	return *temp;
}

template <class T>
OrderedCollection<T> &  OrderedCollection<T>::remove(const T & item){

//remove all elements which are  == item (assume T implements == oper)
	  int newIndex = 0;
	  for(int i=0; i<size; i++){
		  if(*buffer[i] != item)  buffer[newIndex++] = buffer[i];
	  }
	  size = newIndex;
      return *this;
}


template <class T>
typename OrderedCollection<T>::iterator OrderedCollection<T>::begin(void) { //provide an start iterator
	return OrderedIterator<T>(*this);
}

template <class T>
typename OrderedCollection<T>::iterator OrderedCollection<T>::end(void)   {   //provide an end iterator
	return OrderedIterator<T>(*this, size);
}



template <class T>
OrderedIterator<T>::OrderedIterator(OrderedCollection<T> & set, int position)
	: index(position), s(set) {}

template <class T>
OrderedIterator<T> & OrderedIterator<T>::operator++(int) {
     index++; return *this;
}

template <class T>
T & OrderedIterator<T>::operator*() {
		return *(s.buffer[index]);

}

template <class T>
bool OrderedIterator<T>::operator==(const OrderedIterator<T> & iter) {
         return (&s == &(iter.s)) && (index == iter.index);
}

template <class T>
bool OrderedIterator<T>::operator!=(const OrderedIterator<T> & iter) {
     return !(*this == iter);
}


class BankAccount{
    double balance;

public:
  string owner = "Lou";
    BankAccount(double anAmount):balance(anAmount) {}

  bool operator== (const BankAccount & b) {

  //  return &b == this;
    //name is the same
  return  (b.owner == this->owner &&  b.balance == this->balance);
    //balance is the same

  }

	bool operator!= (const BankAccount & b) {
    //return !(&b != this);
return !(&b == this);
  }



	void printOn(ostream & o) const { o << owner << ": $" << balance << "\n"; }
};
ostream & operator<<(ostream & o, const BankAccount & b){
	b.printOn(o);
	return o;
}

//Example of how the collection and iterator could be used
int main() {
BankAccount b1(100.0), b2(50.0), b3(200.0), b4(150.0);
OrderedCollection<BankAccount> accounts;
accounts.addLast(b1).addLast(b2).addLast(b3).addLast(b4).addLast(b2);

for(OrderedCollection<BankAccount>::iterator itr = accounts.begin();
			    itr != accounts.end(); itr++)

	 cout << *itr;
accounts.print();
accounts.remove(b2);
accounts.print();
return 0;
}//end main
