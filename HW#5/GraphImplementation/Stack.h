#ifndef _SST_
#define _SST_

#include <string>
#include <iostream>

using namespace std;


//This is the preference stack best used when n > 2 where n is the size of the set M & N
class Stack{
    public:
            struct PPref;
            typedef PPref * pLink; 
            struct PPref{
                pLink next;
                int name;
            };
            
            /*
            Narrative: Creates an empty dynamic stack of Strings
            pre: a ListPeople has been initialized and a node has been propagted
            post: an initialized Stack
             */
            Stack();
            
            /*
            Narrative: Destructor
            pre: Initalized String Stack
            post: successfully deleted string stack.
             */
            ~Stack();
            
            /*
            Narrative: Copy constructor needed for person struct so we can use this as a parameter
            pre: Stack needed a deep copy
            post: deep copied Stack
             */
            Stack(const Stack& otherStack);
            
            /*
            Narrative: standard stack push operation, pushes an element to the stack
            pre: at least an initalized stack
            post: stack's length += 1 and stack has a new element
             */
            void Push(int preference);

            
            /*
            Narrative: Pops off the top element of the stack
            pre: initalized stack and length != 0
            post: stack's length -= 1 and stack looses 1 element
             */
            int Pop();
            
            /*
            Narrative: reads the top element of the stack
            pre: the stack is not empty
            post: N/A
             */
            int Top() const;
            
            /*
            Narrative: Checks if the length is == 0
            pre: N/A
            post: returns true if empty
             */
            bool IsEmpty() const;
            
            //Operators
            Stack& operator=(const Stack& otherStack);

            //length observer
            int GetLength() const;
            //Display method
            void Display(ostream& out);
            
    private:
            //Destructor Helper
            void Clear();
            //Copy Constructor Helper
            void CopyStuff(const Stack& otherStack);
            //CopyStuff helper
            pLink GetHeadAddress() const;

            
            //Data members
            int length;
            pLink head;
};

#endif
