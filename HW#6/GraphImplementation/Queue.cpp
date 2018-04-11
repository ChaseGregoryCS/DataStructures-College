#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue():head(NULL), length(0){}

Queue::~Queue(){
    Clear();
}

Queue::Queue(const Queue& otherQueue):head(NULL), length(0){
    if(!IsEmpty()) Clear();
	CopyStuff(otherQueue);
}

void Queue::Enqueue(int preference){
        pLink temp = new PPref;
        temp->name = preference;
        temp->next = NULL;
        if (!head) head = temp;
        else tail->next = temp;
        tail = temp;
        length++;
        return;
}
	//cout << head->prefNum << endl;

int Queue::Dequeue(){
	int rVal = -1;
    if(head){
        pLink temp = head;
        head = head->next;
        rVal = temp->name;
        delete temp;
    }
    length--;
	return rVal;
}

int Queue::Top() const{
    if (!IsEmpty()) {
		return head->name;
	}
	return -1;
}

bool Queue::IsEmpty() const{
    return (length == 0);
}

Queue& Queue::operator=(const Queue& otherQueue){
	if(this != &otherQueue){
		CopyStuff(otherQueue);
	}
}

void Queue::Clear(){
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

void Queue::CopyStuff(const Queue& otherQueue){
	pLink iter = otherQueue.GetHeadAddress();
	Queue temp;
	while(iter != NULL){
		temp.Enqueue(iter->name);
		iter = iter->next;
	}
	return;
}
    

int Queue::GetLength() const{
    return length;
}

Queue::pLink Queue::GetHeadAddress() const{
    return head;
}


void Queue::Display(ostream& out){
        pLink iter = GetHeadAddress();
        while (iter->next){
            out << iter->name << endl;
            iter = iter->next;
        }
        if(iter) out << iter->name << endl;
        return;
}
