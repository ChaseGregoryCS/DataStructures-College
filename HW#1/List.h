#ifndef _LH1_
#define _LH1_

#include "PlanetClass.h"
#include <iostream>
#include <string>

using namespace std;

class List{
    public:
                struct Planet;
                typedef Planet* Link;

                //Constructors
                List();
                List(string n, float dfs, float m, int d);
                ~List();
                List(const List& copyToMe);
                List(PlanetClass * ptr);
                
                //List Modifiers
                bool AddPlanetToList(string n, float dfs, float m, int d);
                bool DeletePlanetFromList(string n);
                
                //List Accessors
                int Size() const;
                
                //Node Accessors
                string GetCurrentName() const;
                float GetCurrentDistance() const;
                float GetCurrentMass() const;
                int GetCurrentDiameter() const;
				
				//display
				void Display(ostream& out);
				
				//iterator modifiers
				void SetHeadDistance();
				void SetHeadMass();
				void SetHeadDiameter();
				
				bool StepIntoDistance();
				bool StepIntoMass();
				bool StepIntoDiameter();
				bool StepBackDistance();
				
				List& operator=(const List& pl);
        private:
                PlanetClass * p; 
                void CopyStuff(const List& copyToMe);
    
};

#endif
