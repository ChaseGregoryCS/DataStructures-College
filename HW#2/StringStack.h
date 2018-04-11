#ifndef _SST_
#define _SST_

#include <string>
#include <iostream>

using namespace std;


//This is the preference stack best used when n > 2 where n is the size of the set M & N
class StringStack{
    public:
            struct PPref;
            typedef PPref * pLink; 
            struct PPref{
                pLink next;
                string name;
				int prefNum;
            };
            
            /*
            Narrative: Creates an empty dynamic stack of Strings
            pre: a ListPeople has been initialized and a node has been propagted
            post: an initialized StringStack
             */
            StringStack();
            
            /*
            Narrative: Destructor
            pre: Initalized String Stack
            post: successfully deleted string stack.
             */
            ~StringStack();
            
            /*
            Narrative: Copy constructor needed for person struct so we can use this as a parameter
            pre: Stringstack needed a deep copy
            post: deep copied StringStack
             */
            StringStack(const StringStack& otherStack);
            
            /*
            Narrative: standard stack push operation, pushes an element to the stack
            pre: at least an initalized stack
            post: stack's length += 1 and stack has a new element
             */
            void Push(string preference);
            
            /*
            Narrative: Not a stack property but I needed this method so I could reuse this code
            pre: an initalized stack where length > 0
            post: removed element
             */
            bool Remove(string r);
            
            /*
            Narrative: Pops off the top element of the stack
            pre: initalized stack and length != 0
            post: stack's length -= 1 and stack looses 1 element
             */
            string Pop();
            
            /*
            Narrative: reads the top element of the stack
            pre: the stack is not empty
            post: N/A
             */
            string Top() const;
            
            /*
            Narrative: Checks if the length is == 0
            pre: N/A
            post: returns true if empty
             */
            bool IsEmpty() const;
            
            //Operators
            StringStack& operator=(const StringStack& otherStack);
			bool operator[](string name) const;
            
            //length observer
            int GetLength() const;
            //Display method
            void Display(ostream& out);
			int GetWeight(string n);
            
    private:
            //Destructor Helper
            void Clear();
            //Copy Constructor Helper
            void CopyStuff(const StringStack& otherStack);
            //CopyStuff helper
            pLink GetHeadAddress() const;

            
            //Data members
            int length;
            pLink head;
};

#endif
