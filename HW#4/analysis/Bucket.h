#ifndef _BKT_
#define _BKT_

#include <iostream>

using namespace std;

class Bucket{
    public:
            struct node;
            typedef node* Link;
            struct node{
                int data;
                Link next;
                Link prev;
            };
    
            //Constructors
            Bucket(); 
            Bucket(const Bucket& otherBucket); 

            //Destructor
            ~Bucket();

            /*
            narrative: Gets the mazimum number of each node in the list
            pre: Initalized bucket exists
            post: return maximum number
            */
            int GetMax();
            
            /*
            narrative: Gets the minimum number of each node in the list
            pre: Initalized bucket exists
            post: return minimum number
            */
            int GetMin();
			
			/*
			narrative: Gets the length of the List
			pre: Initalized list
			post: Observer
			*/
			int Length() const;
            
            /*
            narrative: inserts data in unsorted order
            pre: Initalized bucket exists
            post: length + 1 and new member exists in the list
            */
            void Insert(int data);
            
            /*
            narrative: inserts data in sorted order
            pre: Initalized bucket exists
            post: length + 1 and new member exists in the list
            */
            void SortedInsert(int data);            
            
            /*
            narrative:deletes the last item in the list
            pre: Initalized bucket exists
            post: length - 1 and last element is deleted
            */
            bool DeleteLast();
            
            //Print Method
            void PrintBucket();
			
			int Find(int what);
    
    protected:
            Link HeadAddress() const;
            
    private:
        
            // Helper Methods
            void DeleteMe();
            void CopyStuff(const Bucket& otherBucket);
        
            //DataMemebers
            Link head;
            Link tail;
            Link iter;
            int length;
};


#endif
