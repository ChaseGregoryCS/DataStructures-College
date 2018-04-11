#include "PeopleList.h"

using namespace std;

PeopleList::PeopleList(): iter(NULL), last(NULL), head(NULL), length(0) {}

PeopleList::~PeopleList(){
	Clear();
}

PeopleList::PeopleList(const PeopleList& otherList): iter(NULL), last(NULL), head(NULL), length(0) {
	Clear();
	CopyStuff(otherList);
}

void PeopleList::Insert(string person) {
	if(length == 0){
		head = new Person;
		head->prefStack = new StringStack();
		last = head;
		head->name = person;
		head->next = NULL;
		head->back = NULL;
        length++;
	}else{
		iter = new Person;
		iter->prefStack = new StringStack();
		iter->name = person;
		iter->back = last;
		iter->next = NULL;
		last->next = iter;
		last = iter;
        length++;
	}
	return;
}

void PeopleList::PropPrefStack(StringStack& propagate) {
	int stack = propagate.GetLength();
	int reqStackNum = length * length;
	string addMe;
	iter = head;
	int i;		
	if(!(stack % reqStackNum)){
		SetIterHead();
		while (iter->next){
				cout << "+++++++++++++++ " << iter->name << "'s preferences +++++++++++++++" << endl;
//             cout << "loop" << endl;
			for(i = 1; i < length+1; i++){
//                 cout << "forLoop" << endl;
				addMe = propagate.Pop();
                cout << "\t" << addMe;
				iter->prefStack->Push(addMe);
			}
		//	iter->prefStack.Display(cout);
//             cout << "next iter" << endl;
            iter = iter->next;
			cout << endl;
//             cout << iter->name << " We make it this far" << endl;
		}
		cout << "+++++++++++++++ " << iter->name << "'s preferences +++++++++++++++" << endl;
		for(i = 1; i < length+1; i++){
//                 cout << "forLoop" << endl;
				addMe = propagate.Pop();
				cout << "\t" << addMe;
                iter->prefStack->Push(addMe);
		}
		
	}else cout << "Invalid DATA" << endl;
    cout << endl;
    return;
}

bool PeopleList::Remove(string name) {
	bool rValue = true; //return value doubles as a flag
	iter = head;
	if(iter){
		while (iter->name != name && StepInto());
		if(iter->name != name) rValue = false;
		if (rValue){
			Link temp = iter->back;
			//hande last element senario
			if (iter->next){
				temp->next = iter->next;
				iter->next->back = temp;
			}else {
				last = temp;
				temp->next = NULL;
			}
			//and chop off the element...
			iter->next = NULL;
			iter->back = NULL;
			//CRUSH
			delete iter;
			iter = head;
			//Ruthless...
            length--;
		}
	}else rValue = false;
	return rValue; //return success/failure
}

string PeopleList::GetIterName() const {
	if(iter)
		return iter->name;
	return "";
}

int PeopleList::GetWeight(string findMe, string whosNum) {
		bool pass = false;
		iter = head;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		while (iter->next and !pass){
			if(iter->name == findMe) pass = true;
			else iter = iter->next;
		}
		if(iter->name == findMe) pass = true;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		if(pass) return iter->prefStack->GetWeight(whosNum);
}

int PeopleList::GetLatchedWeight(string findMe){
		bool pass = false;
		iter = head;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		while (iter->next and !pass){
			if(iter->name == findMe) pass = true;
			else iter = iter->next;
		}
		if(iter->name == findMe) pass = true;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		if(pass) return iter->latchedWeight;
		else return 0;

}

string PeopleList::GetIterPopPref(){
	if(iter)
		return iter->prefStack->Pop();
	return "";
}

void PeopleList::SetIterHead(){
    iter = head;
    return;
}

bool PeopleList::StepBack() {
	bool rValue = false;
	if(iter->back){
		iter = iter->back;
        rValue = true;
	}
	return rValue;
}

bool PeopleList::StepInto() {
	bool rValue = false;
	if(iter->next){
		iter = iter->next;
        rValue = true;
	}
	return rValue;
}

void PeopleList::SetIterLatchedWeight(int l, string findMe){
		bool pass = false;
		iter = head;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		while (iter->next and !pass){
			if(iter->name == findMe) pass = true;
			else iter = iter->next;
		}
		if(iter->name == findMe) pass = true;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		if(pass) iter->latchedWeight = l;
		return;

}

void PeopleList::IterPush(string p){
	iter->prefStack->Push(p);
	return;
}

string PeopleList::IterRemove(string findMe, string r){
	bool pass = false;
	iter = head;
//	cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
	while (iter->next and !pass){
		if(iter->name == findMe) pass = true;
		else iter = iter->next;
	}
	if(iter->name == findMe) pass = true;
//	cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
	if(pass){
		if(iter->prefStack->Remove(r)) 
			return r;
	}
	return "";
}

int PeopleList::Length() const {
	return length;
}

PeopleList& PeopleList::operator=(const PeopleList& otherList) {
	if(this != &otherList){
		Clear();
		CopyStuff(otherList);
	}
}

string PeopleList::operator[](string findMe){
		bool pass = false;
		iter = head;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		while (iter->next and !pass){
			if(iter->name == findMe) pass = true;
			else iter = iter->next;
		}
		if(iter->name == findMe) pass = true;
//		cout << iter->name << " prefers " << iter->prefStack->Top() << endl;
		if(pass) return GetIterPopPref();
		return "No One Found";
}

void PeopleList::Clear() {
	iter = head;
	head = iter->next;
	delete iter;
    last = NULL;
    iter = head;
	while(StepInto()){
		head = iter->next;
		delete iter;
		iter = head;
	}
	return;
}

void PeopleList::CopyStuff(const PeopleList& otherList) {
	if(otherList.Length() != 0){
		Link temp = otherList.GetHeadAddr();
		Insert(temp->name);
		while (temp->next){
			temp = temp->next;
			Insert(temp->name);
		}
	}
	return;
}

PeopleList::Link PeopleList::GetHeadAddr() const{
	return head;
}




