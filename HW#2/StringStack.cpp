#include "StringStack.h"
#include <iostream>

using namespace std;

StringStack::StringStack():head(NULL), length(0){}

StringStack::~StringStack(){
    Clear();
}

StringStack::StringStack(const StringStack& otherStack):head(NULL), length(0){
    if(!IsEmpty()) Clear();
	CopyStuff(otherStack);
}

void StringStack::Push(string preference){
	int stuff;
    if(IsEmpty()){
        head = new PPref;
        head->name = preference;
		head->prefNum = 1;
        length++;
    }else{
        pLink insert = new PPref;
        insert->name = preference;
        insert->next = head;
		
        head = insert;
        length++;
		insert->prefNum = length;
		head = insert;
    }
	//cout << head->prefNum << endl;
    return;
}

bool StringStack::Remove(string r){
    bool pass = false;
	pLink iter = GetHeadAddress();
	while(iter->next and !pass){
		if(iter->name == r){
            pass = true;
        }else iter = iter->next;
	}
	if(iter->name == r) pass = true;
 //   cout << "iter->name: " << iter->name << " ?= " << r  << endl;
    if(pass){
        if(iter == head){
            head = head->next;
            iter->next = NULL;

            delete iter;
			iter = NULL;
        }else{
            pLink temp = head;
            while (temp->next != iter) temp = temp->next;
            temp->next = iter->next;
            iter->next = NULL;
            delete iter;
			iter = NULL;
        }
		//Display(cout);
        length--;
    }
    return pass;
}

string StringStack::Pop(){
//	cout << "POP() " << endl;
    string rValue;
    if(length == 1){
		rValue = head->name;
//         cout << "length == 1: " << rValue << " length: " << length << endl;
        delete head;
		head = NULL;
        length--;
    }else{
        rValue = head->name;
 //        cout << "length > 1 " << rValue << " length: " << length << endl; 
        pLink removeMe = head;
        head = head->next;
//		cout << "head->name: " << head->name << endl;
        delete removeMe;
        removeMe = NULL;
        length--;
    }
//	Display(cout << "++++++++++++++++++" << endl);
    return rValue;
}

string StringStack::Top() const{
    if (!IsEmpty()) {
		return head->name;
	}
	return "";
}

bool StringStack::IsEmpty() const{
    return (length == 0);
}

int StringStack::GetWeight(string n){
	bool rValue = false;
	pLink iter = GetHeadAddress();
	while(iter->next and !rValue){
		if(iter->name == n){
            rValue = true;
        }
		if(!rValue) {
			iter = iter->next;
		}
	}
	if(iter->name == n) rValue = true;
	if(rValue)
		return iter->prefNum;
	else return 0;
}

bool StringStack::operator[](string name) const{
//	cout << "def me" << endl;
	bool rValue = false;
	pLink iter = GetHeadAddress();
	while(iter->next and !rValue){
//		cout << "loop" << endl;
		if(iter->name == name){
            rValue = true;
        }
		if(!rValue) {
//			cout << "yup" << endl;
			//cout << iter->name << endl;
			iter = iter->next;
//			cout << "ohh shit" << endl;
		}
	}
//	cout << "blah" << endl;
	if(iter){// cout << "passed" << endl;
		if(iter->name == name) rValue = true;
//		cout << "ohhh shit!!" << endl;
	}
	return rValue;
}

StringStack& StringStack::operator=(const StringStack& otherStack){
	if(this != &otherStack){
		CopyStuff(otherStack);
	}
}

void StringStack::Clear(){
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

void StringStack::CopyStuff(const StringStack& otherStack){
	pLink iter = otherStack.GetHeadAddress();
	StringStack temp;
	while(iter != NULL){
		temp.Push(iter->name);
		iter = iter->next;
	}
	while(!temp.IsEmpty()){
		Push(temp.Pop());
	}
	return;
}
    

int StringStack::GetLength() const{
    return length;
}

StringStack::pLink StringStack::GetHeadAddress() const{
    return head;
}


void StringStack::Display(ostream& out){
        pLink iter = GetHeadAddress();
        while (iter->next){
            out << iter->name << "    " << iter->prefNum << endl;
            iter = iter->next;
        }
        if(iter) out << iter->name << endl;
        return;
}
