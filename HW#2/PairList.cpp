#include "PairList.h"
#include <iostream>

using namespace std;

PairList::PairList():head(NULL), iter(NULL), length(0){}

PairList::~PairList(){
    if(!IsEmpty()) Clear();
}

PairList::PairList(const PairList& otherList):head(NULL), iter(NULL), length(0){
	if (length != 0){
		Clear();
	}
	CopyStuff(otherList);
}

void PairList::Insert(string m, string w){
	if (IsEmpty()){
		head = new Node;
		head->mName = m;
		head->wName = w;
		head->next = NULL;
		length ++;
	}else{
		Link addMe = new Node;
		iter = head;
		head = addMe;
		head->next = iter;
		head->mName = m;
		head->wName = w;
		addMe = NULL;
		length ++;
	}
	return;
}

string PairList::GetLadyMarrage(string w){
        operator[](w);
        return iter->wName;
}

bool PairList::RemoveM(string m){
//     cout << "Remove(): " << endl;
//     Display(cout);
	bool rValue = operator[](m);
	if(rValue){
		if(head == iter){
			head = iter->next;
			iter->next = NULL;
			delete iter;
			iter = head;
		}else{
			Link previous = head;
			while (previous->next->mName != iter->mName){
				previous = previous-> next;
			}
			previous->next = iter->next;
			iter->next = NULL;
			delete iter;
			iter = previous;
			previous = NULL;
		}
	}
	
    length --;
	return rValue;
}

string PairList::RemoveW(string w){
    bool pass = false;
    string rValue = "";
	iter = head;
    if(length != 1){
        while (iter->next and !pass){
            if(iter->wName == w) pass = true;
            if(!pass)iter = iter->next;
        }    
    }
    if(iter->wName == w) pass = true;
	if(pass){
        rValue = iter->mName;
		if(length == 1){
			cout << "ALMOST" << endl;
			delete head;
			head = NULL;
		}else{
			Link previous = head;
			while (previous->next->wName != iter->wName){
				previous = previous-> next;
			}
			
			previous->next = iter->next;
			iter->next = NULL;
			delete iter;
			iter = previous;
			previous = NULL;
		}
	}else cout << "no one found" << endl;
    length --;
	return rValue;
}

bool PairList::operator[](string m){
	bool rValue = false;
    if(!IsEmpty()){
        iter = head;
        while (iter->next and !rValue){
            if(iter->mName == m or iter->wName == m) rValue = true;
            iter = iter->next;
            
        }
        if(iter->mName == m or iter->wName == m) rValue = true;
        return rValue;
    }
}

bool PairList::IsEmpty() const{
	return (length == 0);
}

void PairList::Clear(){
    iter = head;
    while(head->next){
		head = head->next;
		delete iter;
		iter = head;
    }
	return;
}

PairList::Link PairList::GetHeadAddress() const{
	return head;
}


void PairList::CopyStuff(const PairList& otherList){
	iter = otherList.GetHeadAddress();
	while(iter->next){
		Insert(iter->mName, iter->wName);
		iter = iter->next;
	}
	Insert(iter->mName, iter->wName);
	return;
}

void PairList::Display(ostream& out){
        iter = head;
        while(iter->next){
// 			cout << "loop" << endl;
                out << "\t(" << iter->mName << ", " << iter->wName << ")" << endl; 
                iter = iter->next;
        }
        if(iter) out << "\t(" << iter->mName << ", " << iter->wName << ")" << endl; 
        return;
}
