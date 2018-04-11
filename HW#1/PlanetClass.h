#ifndef _PC1_
#define _PC1_

#include <string> 
#include <ostream>

using namespace std;

class PlanetClass{
        public:
                struct Planet;
                typedef Planet* Link;
                struct Planet{
                        int position;
                        string name;
                        float distanceFromSun;
                        float mass;
                        int diameter;
                                    
                        Link nextDistance;
                        Link nextMass;
                        Link nextDiameter;
                        Link reverseDistance;
                };
                
                //Constructors
                /*
                Pre Conditions: Client uses the default constructor
                Post-Conditions: initialized planet class with default values.
                Narrative: initializes a ‘PlanetClass’ (node) with default values
                 */
                PlanetClass();
                
                /*
                Pre Conditions: Client uses a parameterized constructor
                Post-Conditions: initialized a ‘PlanetClass’ with the first node constructed to parameter data
                Narrative: initializes a ‘PlanetClass’ with the first node constructed to parameter data
                 */
                PlanetClass(string n, float dfs, float m, int d);//
                
                /*
                Pre Conditions: Constructed ‘PlanetClass’
                Post-Conditions: Deleted planet Class
                Narrative: breaks node off of the list carefully sets pointers accordingly then deletes the node
                 */
                ~PlanetClass();//
                
                /*
                Pre Conditions: Client needs to deep copy an object to the next object
                Post-Conditions: Deleted planet Class
                Narrative: Copy Constructor
                 */
                PlanetClass(const PlanetClass& copyToMe);//
                
                //List Modifiers
                /*
                Pre Conditions: Adds a planet to the list
                Post-Conditions: Planet added to the list
                Narrative: Adds a planet to the list while letting another method handle the links
                 */
                bool AddPlanetToList(string n, float dfs, float m, int d);//
                
                /*
                Pre Conditions: A list with propagated data exists
                Post-Conditions: Planet Removed and links set accordingly returns true if successfull
                Narrative: sets links for each node pointer in each node
                 */
                bool DeletePlanetFromList(string n); //
                
                //List Accessors
                //Returns useful data about the list...
                //Such as the size, at what position is the iterator is pointing
                //and finally what is the head for distance pointing to
                int Size() const;//
                int GetIterIndex() const;//
                Planet* GetHeadDistance() const;//
                
                //Node Accessors
                //returns the data in th enode that the iterator is currently
                //pointing to
                string GetCurrentName() const;//
                float GetCurrentDistance() const;//
                float GetCurrentMass() const;//
                int GetCurrentDiameter() const;//
				
				//display
				/*
                Pre Conditions: Initialized list object
                Post-Conditions: N/A
                Narrative: Displays each node by distance sorted orde
                 */
				void Display(ostream& out);//
				
				//iterator modifiers
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: Iterator is set to the first node in the distance list
                Narrative: sets the iterator to the first node in distance list
                 */
				void SetHeadDistance();
                
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: Iterator is set to the first node in the diameter list
                Narrative: sets the iterator to the first node in diameter list
                 */
				void SetHeadMass();
                
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: Iterator is set to the first node in the diameter list
                Narrative: sets the iterator to the first node in diameter list
                 */
				void SetHeadDiameter();//
				
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: The iterator steps into the list based on method used
                Narrative: iterator steps into the list if able
                
                All Step methods follow same pattern
                 */
				bool StepIntoDistance();
				bool StepIntoMass();
				bool StepIntoDiameter();
				bool StepBackDistance();
				
                /*
                Pre Conditions: Client uses the = operator
                Post-Conditions: Deep copied object
                Narrative: = operator
                 */
				PlanetClass& operator=(const PlanetClass& otherPlanet);
                
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: Iterator is set to the indexed value list
                Narrative: Sets the iterator from the head to the indexed value
                 */
                void operator[](int i);
				
                //Returns a clone of the list for the handle copy constructor
				PlanetClass * Clone() const;
                
        private:

				//Node Modifiers
                void SetCurrentName(string n);
                void SetCurrentDistance(float d);
                void SetCurrentMass(float m);
                void SetCurrentDiameter(int d);
                
                /*
                Pre Conditions: AddPlanetToList( ) called
                Post-Conditions: Planet added to list in appropriate order
                Narrative: sets links for each node pointer in each node
                 */
                void SetLinkByValue(Link toAdd);
                
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: Iterator is set to the indexed value list
                Narrative: Sets the iterator from the head to the indexed value
                 */
                void SetIndexValues();
				
                /*
                Pre Conditions: A List was constructed
                Post-Conditions: Proper Deletion of List
                Narrative: Properly deletes the list
                 */
                void Clear();//
				
				//metaData
				int size;
				
				//These are the list pointers used to structure the list
				Link headNextMass;
                Link headNextDistance;
                Link headNextDiameter;
                Link iterator;
                
                /*
                Pre Conditions: A deep copy is required
                Post-Conditions: Deep copied object
                Narrative: Properly builds a new list with another list’s data
                 */
				void CopyStuff(const PlanetClass& otherPlanet);//
				
                /*
                Pre Conditions: Initialized list object
                Post-Conditions: value of toNode is initialized to the values passed by parameter
                Narrative: initializes the toNode Planet
                 */
				void InitializePlanet(string n, float dfs, float m, int d, 
							Link nD, Link nM, Link nDia, Link rD, Link toLink);
};

#endif

