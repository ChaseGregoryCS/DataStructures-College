#include "List.h"
#include <iostream>

using namespace std;

void DisplayByMass(List SolarSystem){
    SolarSystem.SetHeadMass();
    while(SolarSystem.StepIntoMass())
        cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentMass();
    cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentMass(); 
    return;
}

void DisplayByDistance(List SolarSystem){
    
}

void DisplayByDiameter(List SolarSystem){
    
}

void Genisis(List SolarSystem){
    
}

void StarDestroyer(List SolarSystem){
    
}

void GodMode(string& selection, List SolarSystem){
    
}

void SpaceShipMode(string& selection, List SolarSystem){
    cout << "SpaceShipMode" << endl;
    while(selection != "0"){
            cout << "How would you like to proceed?: " << endl
                 << "           0:Exit SpaceShipMode " << endl
                 << "           1:See Planets by Distance" << endl
                 << "           2:See Planets by Mass" << endl
                 << "           3:See Planets by Distance" << endl
                 << "           4:Traverse the planets one by one" << endl;
                 cout << "   selection: ";
                 cin >> selection;
                 if(selection == "1") DisplayByDistance(SolarSystem);
                 else if (selection == "2") DisplayByMass(SolarSystem);
                 else if (selection == "3") DisplayByDistance(SolarSystem);
                 else if (selection == "0");
                 else cout << "Invalid Selection! Please enter a valid selection:" << endl;
    }
    
}

List PropagateSolarSystem(){
        List rValue("Venus", 67.2, 5.37, 7521);
        rValue.AddPlanetToList("Mercury", 36.0, 0.364, 3032);
        rValue.AddPlanetToList("Earth", 93.0, 6.58, 7926);
        rValue.AddPlanetToList("Mars", 141.6, 0.708, 4221);
        rValue.AddPlanetToList("Jupiter", 483.8, 2093, 88846);
        rValue.AddPlanetToList("Saturn", 890.8, 627, 74897);
        rValue.AddPlanetToList("Uranus", 1784.4, 95.7, 31763);
        rValue.AddPlanetToList("Neptune", 2793.1, 113, 30775);
        rValue.AddPlanetToList("Pluto", 3670.0, 0.0161, 1464);
        return rValue;
}

int main(){
        cout << "Propagate data with our SolarSystem data? (y/n) "; 
        string propagate;
        cin >> propagate;
        cout << endl;
        List SolarSystem;
        while (propagate != "y" && propagate != "n"){
            cout << "Invalid! " << endl;
            cout << "Propagate data with our SolarSystem? (y/n) "; 
            cin >> propagate;
        }
        if (propagate == "y") SolarSystem = PropagateSolarSystem(); 
        
        
        cout    << "Please enter the corresponding number: \n" 
                << "       0:Exit " << endl 
                << "       1:God Mode " << endl
                << "       2:Space Ship Mode " << endl;
        string selection;
        cout << "   selection: ";
        cin >> selection;
        while(selection != "0"){
            if(selection == "1") GodMode(selection, SolarSystem);
            else if(selection == "2") SpaceShipMode(selection, SolarSystem);
            else cout << "Invalid Selection! Please enter a valid selection: " << endl; 
            cout << "Please enter the corresponding number: \n" 
                 << "       0:Exit " << endl 
                 << "       1:God Mode " << endl
                 << "       2:Space Ship Mode " << endl;
            cout << "          selection: ";
            cin >> selection;
        }
                            
    
        return 0;
}
