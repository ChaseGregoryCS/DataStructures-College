#include "List.h"

using namespace std;

List::List():p(NULL){}

List::List(string n, float dfs, float m, int d):p(NULL){
        p = new PlanetClass(n, dfs, m, d);
}

List::List(const List& pl){
        CopyStuff(pl);
}

List::List(PlanetClass * ptr): p(ptr){}

List::~List(){ delete p; p =NULL;}

void List::CopyStuff(const List& pl){
        p = NULL;
        if(pl.p){
                p = pl.p->Clone();
        }
        return;
}

bool List::AddPlanetToList(string n, float dfs, float m, int d){
        if(p)
            return p->AddPlanetToList(n, dfs, m, d);
        return false;
}

bool List::DeletePlanetFromList(string n){
        if(p)
                return p->DeletePlanetFromList(n);
        return false;
}

int List::Size() const{
        if(p)
                return p->Size();
        return 0;
}


string List::GetCurrentName() const{
        if(p)
                return p->GetCurrentName();
        return "";
}

float List::GetCurrentDistance() const{
        if(p)
                return p->GetCurrentDistance();
        return 0;
}

int List::GetCurrentDiameter() const{
        if(p)
                return p->GetCurrentDiameter();
        return 0;
}

float List::GetCurrentMass() const{
        if(p)
                return p->GetCurrentMass();
        return 0;
}

void List::Display(ostream& out){
        if(p)
                return p->Display(out);
        return;
}

void List::SetHeadDistance(){
        if(p)
                return p->SetHeadDistance();
        return;
}

void List::SetHeadDiameter(){
        if(p)
                return p->SetHeadDiameter();
        return;
}

void List::SetHeadMass(){
        if(p)
                return p->SetHeadMass();
        return;
}

bool List::StepIntoDistance(){
        if(p)
                return p->StepIntoDistance();
        return false;
}

bool List::StepIntoDiameter(){
        if(p)
                return p->StepIntoDiameter();
        return false;
}

bool List::StepIntoMass(){
        if(p)
                return p->StepIntoMass();
        return false;
}

bool List::StepBackDistance(){
        if(p)
                return p->StepBackDistance();
        return false;
}

List& List::operator=(const List& pl){
        if(this != &pl){
                CopyStuff(pl);
        }
        return *this;
}
