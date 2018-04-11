#ifndef LLST
#define LLST

class Element{
	public:
		Element(); //an element in the list
		Element(int id); //initializes the element with an id then initializes 'next' to null= 0;p
        static int LastID();
        int ID();
        void DeleteMe();
        
	private:
		int id;
        Element * next;
        
};

class List(){
	public:
		List();
        List(int id);
		~List();
		Element Pop(); //making this into a stack-like data structure
		void Append(Element plusOne);
		Element operator[](int num);
        int Length();

	private:
		Element FindElement(int id);
	
		Element * iterator;
		Element * begining;
		Element * last;
};

#endif
