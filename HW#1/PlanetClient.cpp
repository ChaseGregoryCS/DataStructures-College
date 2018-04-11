#include <string>
#include "PlanetClass.h"
#include <iostream>

using namespace std;

void TestAdding(PlanetClass* hasElement){
	hasElement->AddPlanetToList("Mercury", 36.0, 0.364, 3032);
    hasElement->AddPlanetToList("Earth", 93.0, 6.58, 7926);
    hasElement->AddPlanetToList("Mars", 141.6, 0.708, 4221);
    hasElement->AddPlanetToList("Jupiter", 483.8, 2093, 88846);
	hasElement->AddPlanetToList("Saturn", 890.8, 627, 74897);
    hasElement->AddPlanetToList("Uranus", 1784.4, 95.7, 31763);
    hasElement->AddPlanetToList("Neptune", 2793.1, 113, 30775);
    hasElement->AddPlanetToList("Pluto", 3670.0, 0.0161, 1464);
	hasElement->Display(cout);
	//cout << hasElement->Size() << endl;
    cout << endl;
}

void TestLinkMass(PlanetClass * hasElement){
    hasElement->SetHeadMass();
    
    cout << "Sorted on Mass" << endl;
    cout << hasElement->GetCurrentName() << endl; 
    while(hasElement->StepIntoMass()){
            cout << hasElement->GetCurrentName() << endl;
    }
    cout << endl;
    return;
}

void TestLinkDiameter(PlanetClass * hasElement){
    hasElement->SetHeadDiameter();
    cout << "Sorted on Diameter" << endl;
    cout << hasElement->GetCurrentName() << endl; 
    while(hasElement->StepIntoDiameter()){
            cout << hasElement->GetCurrentName() << endl;
    }
    cout << endl;
}

void TestLinkDistance(PlanetClass * hasElement){
    cout << "Sorted on Distance ->" << endl;
    hasElement->SetHeadDistance();
    cout << hasElement->GetCurrentName() << endl; 
    while(hasElement->StepIntoDistance()){
            cout << hasElement->GetCurrentName() << endl;
    }
    cout << endl;
    cout << "Sorted on Distance <-" << endl;
    cout << hasElement->GetCurrentName() << endl; 
    while(hasElement->StepBackDistance()){
            cout << hasElement->GetCurrentName() << endl;
    }
    cout << endl;
}

void TestDeleteNode(PlanetClass * hasElement){
    cout << "TestDeleteNode" << endl;
    hasElement->DeletePlanetFromList("Pluto");
    //hasElement->Display(cout);
    hasElement->DeletePlanetFromList("Earth");
    //hasElement->Display(cout);
    return;
}

int main(){
	PlanetClass * SolarSystemTwo = new PlanetClass("Venus", 67.2, 5.37, 7521);
	//cout << SolarSystemTwo->GetCurrentName() << "|" << SolarSystemTwo->GetCurrentDistance() << 
			//"|" << SolarSystemTwo->GetCurrentMass() << "|" << SolarSystemTwo->GetCurrentDiameter() << endl;
	TestAdding(SolarSystemTwo);
    TestLinkMass(SolarSystemTwo);
    TestLinkDiameter(SolarSystemTwo);
    TestLinkDistance(SolarSystemTwo);
    PlanetClass * SolarSystem = new PlanetClass(*SolarSystemTwo);
    SolarSystem->Display(cout);
//     TestLinkMass(SolarSystem);
//     TestLinkDiameter(SolarSystem);
//     TestLinkDistance(SolarSystem);
    TestDeleteNode(SolarSystemTwo);
    SolarSystemTwo->Display(cout);
    cout <<"++++++++++++++++++++++++++++++++++++++++++++" << endl;
    TestLinkMass(SolarSystemTwo);
    TestLinkDiameter(SolarSystemTwo);
    TestLinkDistance(SolarSystemTwo);
    delete SolarSystem;
    delete SolarSystemTwo;
	return 0;
}

