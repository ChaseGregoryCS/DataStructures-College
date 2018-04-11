#include "PeopleList.h"
#include <string>
#include <iostream>

int main(){
    PeopleList * ptr = new PeopleList();
    ptr->Insert("Chase");
    ptr->Insert("John");
    ptr->Insert("George");
    ptr->Insert("Aaron");
    ptr->Insert("Tim");
    ptr->SetIterHead();
    cout << ptr->GetIterName() << endl;
    while(ptr->StepInto()){
        cout << ptr->GetIterName() << endl;
    }
    cout <<endl << endl;
    ptr->Remove("Chase");
    ptr->SetIterHead();
    cout << ptr->GetIterName() << endl;
    while(ptr->StepInto()){
        cout << ptr->GetIterName() << endl;
    }
    cout << endl << endl;
    ptr->Insert("Chase");
    
    ptr->SetIterHead();
    cout << ptr->GetIterName() << endl;
    while(ptr->StepInto()){
        cout << ptr->GetIterName() << endl;
    }
    cout << endl << endl;
    ptr->Remove("Chase");
    ptr->SetIterHead();
    cout << ptr->GetIterName() << endl;
    while(ptr->StepInto()){
        cout << ptr->GetIterName() << endl;
    }
    cout << "end test insert, Remove";
    cout << endl << endl;
    
    StringStack pre;
    pre.Push("Sandy");//
    pre.Push("Sydney");
    pre.Push("Mallissa");
    pre.Push("Chel");
    pre.Push("Chel");//
    pre.Push("Sandy");
    pre.Push("Mallissa");
    pre.Push("Sydney");
    pre.Push("Sandy");//
    pre.Push("Chel");
    pre.Push("Sydney");
    pre.Push("Mallissa");
    pre.Push("Mallissa");//
    pre.Push("Chell");
    pre.Push("Sydney");
    pre.Push("Sandy");
    //cout << "here" << endl;
    ptr->PropPrefStack(pre);
    
    ptr->SetIterHead();
    //cout << "here" << endl;
    cout << ptr->GetIterPopPref() << endl;
    while(ptr->StepInto()){
            cout << ptr->GetIterPopPref() << endl;
    }
    return 0;
}
