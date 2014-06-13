//ArrayList.h


#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList{
public:
	//Constructs an empty list with this initial capacity
	ArrayList(int);

	//Destructs any dynamically allocated memory inside the list
	~ArrayList();

	//Adds an item to the end of the list, doubling the capacity if necessary
	void add(char);

	//Makes a completely separate copy of the list and returns a pointer to it
	ArrayList* clone();
	
	//Retrieves an item at an index currently used by the list
	char get(int);

	//Displays the items that are in the list, all on one line
	void print();

	//Stores an item at an index currently used by the list
	void set (int, char);

	//Reports the list size, which is how many items are currently in it
	int size();
    
    char * data();

	//Overloads to check whether the other list holds the same items in the same places
	bool operator==(ArrayList&);
	
private:
	int cap,max;
	char* A;
};

#endif
