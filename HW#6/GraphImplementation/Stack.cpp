#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack():head(NULL), length(0){}

Stack::~Stack(){
    Clear();
}

Stack::Stack(const Stack& otherStack):head(NULL), length(0){
    if(!IsEmpty()) Clear();
	CopyStuff(otherStack);
}

void Stack::Push(int preference){
	pLink temp = new PPref;
    temp->name = preference;
    temp->next = head;
    if(!head) temp->next = head;
    head = temp;
    length++;
    return;
}


int Stack::Pop(){
    int rValue;
    if(head){
        pLink temp = head;
        head = head->next;
        rValue = temp->name;
        delete temp;
        length--;
    }
    return rValue;
}

int Stack::Top() const{
    if (!IsEmpty()) {
		return head->name;
	}
	return -1;
}

bool Stack::IsEmpty() const{
    return (length == 0);
}

Stack& Stack::operator=(const Stack& otherStack){
	if(this != &otherStack){
		CopyStuff(otherStack);
	}
}

void Stack::Clear(){
    if(!IsEmpty()){
        pLink iterator = head;
        while(head->next){
            head = head->next;
            delete iterator;
            iterator = head;
        }
    }
    return;
}

void Stack::CopyStuff(const Stack& otherStack){
	pLink iter = otherStack.GetHeadAddress();
	Stack temp;
	while(iter != NULL){
		temp.Push(iter->name);
		iter = iter->next;
	}
	while(!temp.IsEmpty()){
		Push(temp.Pop());
	}
	return;
}
    

int Stack::GetLength() const{
    return length;
}

Stack::pLink Stack::GetHeadAddress() const{
    return head;
}


void Stack::Display(ostream& out){
        pLink iter = GetHeadAddress();
        while (iter->next){
            out << iter->name << endl;
            iter = iter->next;
        }
        if(iter) out << iter->name << endl;
        return;
}
