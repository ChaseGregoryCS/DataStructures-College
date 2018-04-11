#include "List.h"
#include <iostream>

using namespace std;

void DisplayByMass(List SolarSystem){
    SolarSystem.SetHeadMass();
    cout << "Name|Mass " << endl;
    cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentDistance() << endl;
    while(SolarSystem.StepIntoMass())
        cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentMass() << endl;
    return;
}

void DisplayByDistance(List SolarSystem){
    SolarSystem.SetHeadDistance();
    cout << "Name|Distance " << endl;
    cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentDistance() << endl;
    while(SolarSystem.StepIntoDistance())
        cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentDistance() << endl;
    return;
}

void DisplayByDiameter(List SolarSystem){
    SolarSystem.SetHeadDiameter();
    cout << "Name|Diameter " << endl;
    cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentDistance() << endl;
    while(SolarSystem.StepIntoDiameter())
        cout << SolarSystem.GetCurrentName() <<"|" << SolarSystem.GetCurrentDiameter() << endl; 
    return;
}

void Genisis(List& SolarSystem){
    string addName;
    int addDiameter;
    float addMass;
    float addDistance;
    
    cout << "What would you like to call your planet?: ";
    cin >> addName;
    cout << "\nWhat is it's mass?: ";
    cin >> addMass;
    cout << "\nWhat is it's diameter?: ";
    cin >> addDiameter;
    cout << "\nWhat is it's distance?: ";
    cin >> addDistance;
    SolarSystem.AddPlanetToList(addName, addDistance, addMass, addDiameter);
    
    return;
}

void StarDestroyer(List& SolarSystem){
    string destroy;
    SolarSystem.Display(cout);
    cout << "Which Planet would you like to destroy (name)?: ";
    cin >> destroy;
    SolarSystem.DeletePlanetFromList(destroy);
    return;
}

void GodMode(string& selection, List& SolarSystem){
    selection = "";
    while(selection != "0"){
            cout << " Would you like to Add or Delete a planet?\n" 
                 << "           0:Exit\n"
                 << "           1:Add Planet\n"
                 << "           2:Delete Planet\n"
                 << "           3:View Current Solar System by Distance from the sun\n"
                 << "                   Selection: ";
                 cin >> selection;
                 if(selection == "0");
                 else if(selection == "1") Genisis(SolarSystem);
                 else if(selection == "2") StarDestroyer(SolarSystem);
                 else if(selection == "3") SolarSystem.Display(cout);
    }
    return;
}

void TraversePlanets(string& selection, List SolarSystem){
        selection = "";
        SolarSystem.SetHeadDistance();
        List tempSystem;
//        cout << "Line 39" << endl;
        while (selection != "0"){
                 cout << "           What is our destination captian?" << endl;
                 cout << "           ++++++++++++" << SolarSystem.GetCurrentName() << "++++++++++++" << endl;
                 tempSystem = SolarSystem;
                 cout << "0: Exit Traversal Mode" 
                      << "\n===================================================================" << endl;
                 if(tempSystem.StepIntoDistance())  cout << "       Planet|Distance From Sun         \n1:Go to " 
                                                         << tempSystem.GetCurrentName() << "|" << tempSystem.GetCurrentDistance()
                                                         << "\n==================================================================="
                                                         << endl;
                 tempSystem = SolarSystem;
                 if(tempSystem.StepIntoMass()) cout << "       Planet|Mass             \n2:Go to " 
                                                    << tempSystem.GetCurrentName() << "|" << tempSystem.GetCurrentMass() 
                                                    << "\n===================================================================" 
                                                    << endl;
                 tempSystem = SolarSystem;
                 if(tempSystem.StepIntoDiameter()) cout << "       Planet|Diameter         \n3:Go to " 
                                                        << tempSystem.GetCurrentName() << "|" << tempSystem.GetCurrentDiameter()
                                                        << "\n===================================================================" 
                                                        << endl;
                 tempSystem = SolarSystem;
                 if(tempSystem.StepBackDistance()) cout << "       Planet|Distance From Sun         \n4:Go to " 
                                                         << tempSystem.GetCurrentName() << "|" << tempSystem.GetCurrentDistance()
                                                         << "\n===================================================================" 
                                                         << endl;
                 cout << "               selection: ";
                 cin >> selection;
                 if(selection == "1") SolarSystem.StepIntoDistance();
                 else if (selection == "2") SolarSystem.StepIntoMass();
                 else if (selection == "3") SolarSystem.StepIntoDiameter();
                 else if (selection == "4") SolarSystem.StepBackDistance();
                 else if (selection == "0");
                 else cout << "Invalid Selection! Please enter a valid selection:" << endl;
            
        }
        
}

void SpaceShipMode(string& selection, List SolarSystem){
    cout << "SpaceShipMode" << endl;
    while(selection != "0"){
            cout << "How would you like to proceed?: " << endl
                 << "           0:Exit SpaceShipMode " << endl
                 << "           1:See Planets by Distance" << endl
                 << "           2:See Planets by Mass" << endl
                 << "           3:See Planets by Diameter" << endl
                 << "           4:Traverse the planets one by one" << endl;
                 cout << "   selection: ";
                 cin >> selection;
                 if(selection == "1") DisplayByDistance(SolarSystem);
                 else if (selection == "2") DisplayByMass(SolarSystem);
                 else if (selection == "3") DisplayByDiameter(SolarSystem);
                 else if (selection == "4") TraversePlanets(selection, SolarSystem);
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
