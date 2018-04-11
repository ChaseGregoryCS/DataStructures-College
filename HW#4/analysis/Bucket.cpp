#include "Bucket.h"

using namespace std;

Bucket::Bucket(): length(0), head(NULL), 
				  tail(NULL), iter(NULL)
{}

Bucket::~Bucket(){
	DeleteMe();
}

Bucket::Bucket(const Bucket& otherBucket):length(0), head(NULL), 
				                          tail(NULL), iter(NULL)
{
	CopyStuff(otherBucket);
}

int Bucket::GetMax(){
	int rValue = 0;
	if(head){
		iter = head;
		rValue = iter->data;
		while(iter->next){
			if(iter->data > rValue){
				rValue = iter->data;
			}
			iter = iter->next;
		}
	}
	return rValue;
}

int Bucket::GetMin(){
	int rValue = 0;
	if(head){
		iter = head;
		rValue = iter->data;
		while(iter->next){
			if(iter->data < rValue){
				rValue = iter->data;
			}
			iter = iter->next;
		}
	}
	return rValue;
}

int Bucket::Length() const{
	return length;
}

void Bucket::Insert(int data){
	if(!head){
		head = new node;
		tail = head;
		iter = head;
		tail->data = data;
	}else{
		iter = new node;
		tail->next = iter;
		iter->prev = tail;
		iter->next = NULL;
		iter->data = data;
		tail = iter;
	}
	length ++;
	return;
}

void Bucket::SortedInsert(int data){
	if(length == 0){
		head = new node;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		iter = head;
		tail->data = data;
	}else{
		bool found  = false;
		Link temp = new node;
		temp->data = data;
		iter = head;

		while(iter->next and !found){
			if(iter->data <= data) found = true;
			else if(iter->next) iter = iter->next;
		}if(iter == head){
			temp->next = iter;
			temp->prev = NULL;
			iter->prev = temp;
			head = temp;
		}else if(iter == tail){
			tail->next = temp;
			temp->prev = tail;
			temp->next = NULL;
			tail = temp;
		}else{
			iter->prev->next = temp;
			temp->prev = iter->prev;
			iter->prev = temp;
			temp->next = iter;
		}
		
	}
	length++;
	return;
}

void Bucket::PrintBucket(){
	iter = head;
	cout << "|";
	if(head){
		while(iter->next){
			cout << iter->data << "|";
			iter = iter->next;
		}
		cout << iter->data << "|";
	}
}
    
int Bucket::Find(int what){
	bool found = false;
	int i = 1;
	iter = head;
	while(iter->next and !found){
		if (iter->data == what) found = true;
		else {
			++i; 
			iter = iter->next;
		}
	}
	//if (iter->data == what) found = true;
	//if(!found) i = 0;
	return i;
	
}
	
bool Bucket::DeleteLast(){
	bool rValue = false;
	if(tail){
		if(tail == head){
			iter = tail;
			tail = NULL;
			head = NULL;
			delete iter;
			iter= NULL;
		}else{
			iter = tail;
			tail = tail->prev;
			delete iter;
			iter = tail;
		}
		rValue = true;
		length--;
	}
	return rValue;
}

Bucket::Link Bucket::HeadAddress() const{
	return head;
}

void Bucket::DeleteMe(){
	while (DeleteLast());
}

void Bucket::CopyStuff(const Bucket& otherBucket){
	Link temp = otherBucket.HeadAddress();
	if(temp){
		while (temp->next){
			Insert(temp->data);
			temp = temp->next;
		}
		Insert(temp->data);
	}
	return;
}






