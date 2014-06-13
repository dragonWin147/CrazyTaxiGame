//ArrayList.cpp

#include <iostream>
#include <cstdlib>
#include "ArrayList.h"

using namespace std;

//Constructs an empty list with this initial capacity
ArrayList::ArrayList(int cap){
	this->cap = cap;
	A = new char[cap];
	max = 0;
}

//Destructs any dynamically allocated memory inside the list
ArrayList::~ArrayList(){
	delete [] A;
}

//Adds an item to the end of the list, doubling the capacity if necessary
void ArrayList::add(char item){
	if(max<cap){
		A[max] = item;
	}else{	
		cap = cap*2;
		char* ACopy = new char[cap];
		for(int i=0; i<max; i++){
			ACopy[i] = A[i];
		}
		//delete old A (GC)
		delete [] A;
		
		//set A equal to new array (doubled in size)
		A = ACopy;
		
		//add new item now that there is enough room
		A[max] = item;
	}
	
	max++;
}

//Makes a completely separate copy of the list and returns a pointer to it
ArrayList* ArrayList::clone(){
		ArrayList* clone = new ArrayList(cap);
		for(int i=0;i<max; i++)
			clone->add(A[i]);
		return clone;
}
	
//Retrieves an item at an index currently used by the list
char ArrayList::get(int index){
        if(index < max){
		return A[index];
	}else{
		cout << "index out of bounds" << endl;
		exit(0);
	}
}

//Displays the items that are in the list, all on one line
void ArrayList::print(){
	for(int i=0; i<max; i++)
		cout << A[i] << " "; 
	cout << endl;
}

//Stores an item at an index currently used by the list
void ArrayList::set (int index, char item){
        if(index < max){
		A[index] = item;
	}else{
		cout << "index out of bounds" << endl;
		exit(0);
	}
}

//Reports the list size, which is how many items are currently in it
int ArrayList::size(){
	return max;
}
char * ArrayList::data()
{
    return A;
}
//Overloads to check whether the other list holds the same items in the same places
bool ArrayList::operator==(ArrayList& other){
	bool check = false;
	if(max != other.size()){
		return check;
	}else{
		for(int i=0; i<max; i++){
			if(other.get(i) != get(i)){
				return check;
			}
		}
		
		//only can get here if everything is the same
		check = true;
		return check;
	}
}
