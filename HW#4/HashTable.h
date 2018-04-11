#ifndef _HSBRN_
#define _HSBRN_

#include "Bucket.h"
#include <iostream>

using namespace std;

class HashTable{
	public:
	
		//constructors
		HashTable();
        HashTable(bool sorted);
		
		/*
		narrative: Inserts the data into the Hash
		pre: Initalized Hash Table
		post: data inserted into a bucket after HashBrowns
		*/
		void Insert(int data);
		
		/*
		narrative: Prints the Hash Table
		pre: Initialized HashTable
		post: prints all of the HashBrowns in the bucket
		*/
		void Print();
		
		/*
		narrative: Finds the value passed in at the index passed in
		pre: Initalized HashTable with values
		post: returns the probe length
		*/
		int FindNum(int index, int num);
		
		/*
		narrative: Gets the maxinmum value at the index
		pre: Initialized list 
		post: returns 0 if the index bucket is empty
		*/
		int GetMax(int index);
		
        /*
		narrative: Gets the mininmum value at the index
		pre: Initialized list 
		post: returns 0 if the index bucket is empty
		*/
		int GetMin(int index);
		
	private:
		/*
		narrative: Hashing algorithm method
		pre: you must have potatoes to make hashbrowns
		post: index integer returned after we applied our grittle (hashing algorithm) and spices (because)
		*/
		int HashBrown(int data);
		
		Bucket table[10];
        bool sorted;
};




#endif
