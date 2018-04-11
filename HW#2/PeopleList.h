#ifndef _PL1_
#define _PL1_

#include "StringStack.h"
#include <string>
#include <iostream>

using namespace std;

class PeopleList{
	public:
		struct Person;
		typedef Person* Link;
		struct Person{
			Link next;
			Link back;
			string name;
			int latchedWeight;
			StringStack* prefStack;
		};
	
		/*
		Narrative: Doubly Linked List constructor
		pre: Client creates a list
		post:Initialized list of size 0
		*/
		PeopleList();
		
		/*
		Narrative: Destructor for PeopleList{
		pre: initialized list
		post: deleted PeopleList
		*/
		~PeopleList();
		
		/*
		Narrative: For people list
		pre: client uses a copy constructor
		post: deep copied PeopleList
		*/
		PeopleList(const PeopleList& otherList);
		
		/*
		Narrative: Inserts a Person 
		pre: initialized PeopleList
		post: list length +1
		*/
		void Insert(string person);
		
		/*
		Narrative: Breaks the parameter into sub divisons of length, then fills data accordingly
		pre: A list with people elements
		post: propagated people stacks
		*/
		void PropPrefStack(StringStack& preferences);
		
		/*
		Narrative: Removes element in list by name then maintains the links
		pre: Initialized list
		post: length -1 and element removed
		*/
		bool Remove(string name);
		
		//iterator observers
		//gets the name of the person iter is pointing to
		string GetIterName() const;
		//gets the top preference of the person iter is pointing to
		string GetIterPopPref();
		//gets the "weight" of the preference
		int GetWeight(string findMe, string whosNum) ;
		//gets the weight of the marriage
		int GetLatchedWeight(string name);
		
		//iterator transformers
        //Sets the iterator to the first element of the list
        void SetIterHead();
		//moves the iterator back one element if possible
		bool StepBack();
		//moves the iterator forward if possible
		bool StepInto();
		//pushes an element back onto the prefstack
		void IterPush(string p);
		//Sets the iterator's value
		void SetIterLatchedWeight(int l, string findMe);
		//removes a preference from the iter's pref stack
		string IterRemove(string who, string r);
		//PeopleList Observer
		int Length() const;
		
		//operator
		PeopleList& operator=(const PeopleList& otherList);
        
        /*
        Narrative: This is the accessor operator. where index is self explainitory and prefQ is a bool that asks if you
                   want the preference or not.
        Pre: initialized list
        post: if prefQ == true pop the preference off of the pref stack
         */
		string operator[](string findMe);
        
        Link GetHeadAddr() const;
	private:
	
		//helper for the destructor
		void Clear();
		//helper for copy constructor and operator=
		void CopyStuff(const PeopleList& otherList);
		//gets the head for the People List used in copy constructor
		
		
		Link iter;
		Link head;
		Link last;
		int length;
};

#endif
