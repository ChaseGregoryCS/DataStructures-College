#include "PlanetClass.h"
#include <iostream>

using namespace std;

PlanetClass::PlanetClass(){
		size = 1;
        headNextDistance = new PlanetClass::Planet();
        iterator = headNextDistance;
        headNextMass = headNextDistance;
        headNextDiameter = headNextDistance;
        //iterCurrPos = size;
        
        InitializePlanet (" ", 0.0, 0.0, 0, NULL, NULL, NULL, NULL, headNextDistance);
        
}

PlanetClass::PlanetClass(string n, float dfs, float m, int d){
		size = 1;
        headNextDistance = new PlanetClass::Planet();
        iterator = headNextDistance;
        headNextMass = headNextDistance;
        headNextDiameter = headNextDistance;
        //iterCurrPos = size;
        InitializePlanet (n, dfs, m, d, NULL, NULL, NULL, NULL, headNextDistance);

}

PlanetClass::~PlanetClass(){
        PlanetClass::Clear();
}

PlanetClass::PlanetClass(const PlanetClass& otherList){
		PlanetClass::Clear();
		CopyStuff(otherList);
}

void PlanetClass::Clear(){
        iterator = headNextDistance;
        headNextDiameter = NULL;
        headNextMass = NULL;
		while(headNextDistance){
			if (iterator->nextDistance != NULL) headNextDistance = iterator->nextDistance;
            else headNextDistance = NULL;
            if (iterator) {
                iterator->reverseDistance = NULL;
                iterator->nextDistance = NULL;
                iterator->nextDiameter = NULL;
                iterator->nextMass = NULL;
                delete iterator;
            }
			if(headNextDistance) iterator = headNextDistance;
		}

		return;
}

void PlanetClass::InitializePlanet(string n, float dfs, float m, int d, 
						PlanetClass::Link nD, PlanetClass::Link nM, 
						PlanetClass::Link nDia, PlanetClass::Link rD, 
						PlanetClass::Link toLink)
						{
		//data member iniitlization
		toLink->name = n;
		toLink->distanceFromSun = dfs;
		toLink->mass = m;
		toLink->diameter = d;
		
		//Link initialization;
		toLink->nextDistance = nD;
		toLink->nextMass = nM;
		toLink->nextDiameter = nDia;
		toLink->reverseDistance = rD;
		
		return;
}

bool PlanetClass::AddPlanetToList(string n, float dfs, float m, int d){
		bool rValue = false;
		PlanetClass::Link newPlanet;
        if (size == 0){
            //cout << "first if" << endl;
            newPlanet = new PlanetClass::Planet();
			InitializePlanet(n, dfs, m, d, NULL, NULL, NULL, NULL, newPlanet);
            headNextDistance = newPlanet;
            headNextDiameter = newPlanet;
            headNextMass = newPlanet;
			rValue = true;
		}
		if(!rValue){
            //cout << "second if" << endl;
			newPlanet = new PlanetClass::Planet();
			//propagate the data into the new planet
			InitializePlanet(n, dfs, m, d, NULL, NULL, NULL, NULL, newPlanet);
			//cout << "Planet Initialized" << endl;
			PlanetClass::SetLinkByValue(newPlanet);			
			rValue = true;
		}
		//cout << "Successfully added: " << n << "|" << dfs << "|" << m << "|" << d << endl;
		if(rValue) size++;
		return rValue;
		
}

void PlanetClass::SetIndexValues(){
        SetHeadDistance();
        int tempIndex = 1;
        iterator->position = tempIndex;
        while(StepIntoDistance()){
            tempIndex++;    
            iterator->position = tempIndex;
        }
        iterator->position = tempIndex++;
        SetHeadDistance();
        return;
}


void PlanetClass::SetLinkByValue(PlanetClass::Planet* toAdd){
                //cout << "SetLinkByValue():  "<< endl;
                //handle the sorted head order
                iterator = headNextDistance;
                //cout << "   setting heads " << endl;
                if(iterator->distanceFromSun > toAdd->distanceFromSun) {
                    headNextDistance = toAdd;
                    iterator->reverseDistance = toAdd;
                    toAdd->nextDistance = iterator;
                }
                iterator = headNextMass;
                if(iterator->mass > toAdd->mass) {
                    headNextMass = toAdd;
                    toAdd->nextMass = iterator;
                }
                iterator = headNextDiameter;
                if(iterator->diameter > toAdd->diameter){
                    headNextDiameter = toAdd;
                    toAdd->nextDiameter = iterator;
                }
                iterator = headNextDistance;
                //cout << "   Setting middle nodes: " << endl;
                while(iterator->nextDistance != NULL){
                        //cout << "       Setting nextDistance: " << 
                        //iterator->name << "|" << iterator->distanceFromSun << " ?= " << toAdd->name << "|" << toAdd->distanceFromSun << endl;
                        if((iterator->distanceFromSun < toAdd->distanceFromSun) &&
                            (iterator->nextDistance->distanceFromSun > toAdd->distanceFromSun)){
                                //cout << "           setting links: " << endl;
                                toAdd->nextDistance = iterator->nextDistance;
                                //cout << "               toAdd->nextDistance Set" << endl;
                                iterator->nextDistance = toAdd;
                                toAdd->reverseDistance = iterator;
                                //cout << "               toAdd->reverseDistance Set" << endl;
                                iterator = toAdd->nextDistance;
                                iterator->reverseDistance = toAdd;
                                //cout << "               nextNode->reverseDistance Set" << endl;
                                iterator = toAdd;
                                while (iterator->nextDistance != NULL) iterator = iterator->nextDistance;
                                //cout << "           iterator = NULL" << endl;
                        }else iterator = iterator->nextDistance;
                        //cout << "       loop" << endl;
                }
                //cout << "endl loop" << endl;
                if(iterator!= NULL && toAdd->distanceFromSun > iterator->distanceFromSun ){
                            toAdd->nextDistance = NULL;
                            iterator->nextDistance = toAdd;
                            toAdd->reverseDistance = iterator;
                }
                iterator = headNextMass;
                while(iterator->nextMass != NULL){
                        //cout << "       Setting nextMass: " << 
                        //iterator->name << "|" << iterator->mass << " ?= " << toAdd->name << "|" << toAdd->mass << endl;
                        if((iterator->mass < toAdd->mass) &&
                            (iterator->nextMass->mass > toAdd->mass)){
                                toAdd->nextMass = iterator->nextMass;
                                iterator->nextMass = toAdd;
                                while(iterator->nextMass != NULL) iterator = iterator->nextMass;
                        }else iterator = iterator->nextMass;
                }
                if(toAdd->mass > iterator->mass ){
                            toAdd->nextMass = NULL;
                            iterator->nextMass = toAdd;
                }
                iterator = headNextDiameter;
                while(iterator->nextDiameter != NULL){
                        if((iterator->diameter < toAdd->diameter) &&
                            (iterator->nextDiameter->diameter > toAdd->diameter)){
                                toAdd->nextDiameter = iterator->nextDiameter;
                                iterator->nextDiameter = toAdd;
                                iterator = toAdd->nextDiameter;
                                while (iterator->nextDiameter != NULL) iterator = iterator->nextDiameter;
                        }else iterator = iterator->nextDiameter;
                }
                if(toAdd->diameter > iterator->diameter ){
                            toAdd->nextDiameter = NULL;
                            iterator->nextDiameter = toAdd;
                }
                SetIndexValues();
                //cout << "Success" << endl;
                return;
}


bool PlanetClass::DeletePlanetFromList(string n){
//            cout << "DeletePlanetFromList(): " << endl;
            bool rValue = true;
            SetHeadDistance();
            PlanetClass::Link deleteMe;
            while(iterator->name != n && iterator->nextDistance != NULL){
                //cout << "loop" << endl;
                iterator = iterator->nextDistance;
            }
            //cout << "end loop" << endl;
            if(iterator->nextDistance == NULL && iterator->name != n) rValue = false;
            deleteMe = iterator;
            //Handle the first element of each list
            //cout << "here" << endl;
            if(deleteMe == headNextDistance) headNextDistance = iterator->nextDistance;
            else if(rValue){
                    //cout << "else" << endl;
                    iterator = iterator->reverseDistance;
                    if(deleteMe->nextDistance) iterator->nextDistance = iterator->nextDistance->nextDistance;
                    else iterator->nextDistance = NULL;
                   // cout << "Here::" << endl;
                    if(iterator->nextDistance){
                        iterator = iterator->nextDistance;
                        iterator->reverseDistance = deleteMe->reverseDistance;
                    }
                    deleteMe->reverseDistance = NULL;
                    deleteMe->nextDistance = NULL;
                    //cout << "else end" << endl;
            }
            if(deleteMe == headNextDiameter){
                iterator = headNextDiameter;
                headNextDiameter = iterator->nextDiameter;
            }else if(rValue){
                    SetHeadDiameter();
                    while(iterator->nextDiameter->name != n) iterator = iterator->nextDiameter;
                    if(deleteMe->nextDiameter) iterator->nextDiameter = deleteMe->nextDiameter;
                    else iterator->nextDiameter = NULL;
                    deleteMe->nextDiameter = NULL;
            }
            if(deleteMe == headNextMass) {
                iterator = headNextMass;
                headNextMass = iterator->nextMass;
            } else if(rValue){
                    SetHeadMass();
                    while(iterator->nextMass->name != n) iterator = iterator->nextMass;
                    if(deleteMe->nextMass) iterator->nextMass = deleteMe->nextMass;
                    else iterator->nextMass = NULL;
                    deleteMe->nextMass = NULL;
            }
 //           cout << "deleted: " << deleteMe->name << " from list" << endl;
            delete deleteMe;
            deleteMe = NULL;
            SetIndexValues();
            return rValue;
            
}

int PlanetClass::Size() const{
		return size;
}

PlanetClass::Planet* PlanetClass::GetHeadDistance() const{
        return headNextDistance;
}

string PlanetClass::GetCurrentName() const{
		return iterator->name;
}

float PlanetClass::GetCurrentDistance() const{
		return iterator->distanceFromSun;
}

float PlanetClass::GetCurrentMass() const{
		return iterator->mass;
}

int PlanetClass::GetCurrentDiameter() const{
		return iterator->diameter;
}

void PlanetClass::SetCurrentName(string n){
		iterator->name = n;
		return;
}

void PlanetClass::SetCurrentDistance(float d){
		iterator->distanceFromSun = d;
		return;
}

void PlanetClass::SetCurrentMass(float m){
		iterator->mass = m;
		return;
}

void PlanetClass::SetCurrentDiameter(int d){
		iterator->diameter = d;
		return;
}

void PlanetClass::Display(ostream& out){
		cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		iterator = headNextDistance;
		while (iterator->nextDistance != NULL){
			out << GetCurrentName() << "|" << GetCurrentMass() << "|" << GetCurrentDiameter() <<
			"|" << GetCurrentDistance() << endl;
			iterator = iterator->nextDistance;
		}
        out << GetCurrentName() << "|" << GetCurrentMass() << "|" << GetCurrentDiameter() <<
		"|" << GetCurrentDistance() << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
		return;
}

void PlanetClass::SetHeadDistance(){
		iterator = headNextDistance;
		return;
}

void PlanetClass::SetHeadMass(){
		iterator = headNextMass;
		return;
}

void PlanetClass::SetHeadDiameter(){
		iterator = headNextDiameter;
		return;
}

bool PlanetClass::StepIntoDistance(){
		bool rValue = true;
		if(iterator->nextDistance == NULL) rValue = false;
		if (rValue) iterator = iterator->nextDistance;
		return rValue;
}

bool PlanetClass::StepIntoMass(){
		bool rValue = true;
		if(iterator->nextMass == NULL) rValue = false;
		if (rValue) iterator = iterator->nextMass;
		return rValue;
}

bool PlanetClass::StepIntoDiameter(){
		bool rValue = true;
		if(iterator->nextDiameter == NULL) rValue = false;
		if (rValue) iterator = iterator->nextDiameter;
		return rValue;
}			

bool PlanetClass::StepBackDistance(){
		bool rValue = true;
		if(iterator->reverseDistance == NULL) rValue = false;
		if (rValue) iterator = iterator->reverseDistance;
		return rValue;
}			


PlanetClass& PlanetClass::operator=(const PlanetClass& otherPlanet){
		if(this != &otherPlanet){
                //Clear();
				CopyStuff(otherPlanet);
		}
		return *this;
}

void PlanetClass::operator[](int i){
        int tempPos = 1;
        
        SetHeadDistance();
        
        if (i > size) throw 1;
        while (tempPos != i){
            StepIntoDistance();
            tempPos++;
        }
        return;
}

int PlanetClass::GetIterIndex() const{
        return iterator->position;
}

void PlanetClass::CopyStuff(const PlanetClass& otherList){
 //      cout << "CopyStuff(): " << endl;
       //otherList.Display(cout);
       Planet* fromLink = otherList.GetHeadDistance(); 
   //    cout << "otherlist.head = " << fromLink->name << endl;
       headNextDistance = new Planet();
       headNextDiameter = headNextDistance;
       headNextMass = headNextDistance;
       iterator = headNextDistance;
       AddPlanetToList(fromLink->name, fromLink->distanceFromSun, fromLink->mass, fromLink->diameter);
    //   cout << "added " << fromLink->name << endl;
       fromLink = fromLink->nextDistance;
       while(fromLink->nextDistance){
                AddPlanetToList(fromLink->name, fromLink->distanceFromSun, fromLink->mass, fromLink->diameter);
    //            cout << "added " << fromLink->name << endl;
                fromLink = fromLink->nextDistance;
       }
       AddPlanetToList(fromLink->name, fromLink->distanceFromSun, fromLink->mass, fromLink->diameter);
     //  cout << "added " << fromLink->name << endl;
       fromLink = NULL;
       operator[](otherList.GetIterIndex());
      //InitializePlanet(otherList.Get
       return;
}



PlanetClass * PlanetClass::Clone() const{
        return new PlanetClass(*this);
}
