#ifndef _P8L_
#define _P8L_

#include <string>
#include <iostream>

using namespace std;

class PairList{
	public:
		struct Node;
		typedef Node * Link;
		struct Node{
			Link next;
			string mName;
			string wName;
		};
		
		/*
		Narrative: constructor for pair list
		pre: N/A
		post: empty list of string pairs constructed
		*/
		PairList();
		
		/*
		Narrative: Destructor
		pre: Initialized pair list
		post: Deleted list
		*/
		~PairList();
		
		/*
		Narrative: Copy Constructor
		pre: N/A
		post: deep copied list
		*/
		PairList(const PairList& otherList);
		
		/*
		Narrative: Insert method for the list
		pre: Initialized List
		post: length + 1
		*/
		void Insert(string m, string w);
		
		/*
		Narrative: Removes element from the list based on index
		pre: initialized List
		post: length - 1
		*/
		bool RemoveM(string m);
        string RemoveW(string w);
        
		//operators 
		//finds the string passed in the list return false if unsuccessful
		bool operator[](string m);
		
		//observers
        string GetLadyMarrage(string w);
		bool IsEmpty() const;
		//display list
		void Display(ostream& out);
	private:
		int length;
		Link head;
		Link iter;
		
		void Clear();
		void CopyStuff(const PairList& otherList);
		Link GetHeadAddress() const;
		
};


#endif
