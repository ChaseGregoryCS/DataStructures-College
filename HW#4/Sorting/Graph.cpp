#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include <limits.h>

using namespace std;

class Graph{
  public:
        struct Verticies;
        struct Joint;
        typedef Joint* edge;
        typedef Verticies* link;
        
		
		//Verticy struct
        struct Verticies{
            int id;
            link next;
            link prev;
            edge top;
        };
		
		//Edge struct I used 'Joint' so I can typedef the the edge to the joint pointer (readability)
        struct Joint{
            int vID;
            edge next;
            int weight;
        };

		//Constructor
        Graph():head(NULL), last(NULL), listLength(0){};

		/*
		Narrative: Adds a verticie to the graph
		Pre: Inititalized Graph
		Post: the verticie list has a new verticie
		*/
        void AddVerticie(int id){
            link iter = NULL;
            if(listLength == 0){
                head = new Verticies;
                head->id = id;
                head->next = NULL;
                head->prev = NULL;
                head->top = NULL;
                last = head;
            }else{
                iter = new Verticies;
                iter->id = id;
                iter->next = NULL;
                iter->prev = last;
                iter->top = NULL;
                last->next = iter;
                last = iter;
            }
            listLength++;
            return;
        };

		
		/*
		Narrative: Adds an edge between two Verticies
		Pre: There  must be at least two nodes
		Post: An edge now exists between two verticies
		*/
        bool AddEdge(int src, int dest, int weight){
            link source = FindSource(src);
            link destination = FindSource(dest);
            if(!source or !destination) return false;
            edge newV = NewVerticie(dest);
            newV->next = source->top;
            newV->weight = weight;
            source->top = newV;
            newV = NewVerticie(src);
            newV->next = destination->top;
            destination->top = newV;
            return true;
        };

		/*
		Narrative: Prints the Graph in adjacency list format
		Pre: Inititailized list with edges
		post: Printed Graph	
		*/
        void Print(){
            link iter = head;
            edge edgeIter;
            cout << "Verticie | Edges to " << endl;
            while(iter->next){
                edgeIter = iter->top;
                cout << iter->id << " |";
                while(edgeIter->next){
                    cout << edgeIter->vID << ", ";
                    edgeIter = edgeIter->next;
                }
                cout << edgeIter->vID << endl;
                iter = iter->next;
            }
            edgeIter = iter->top;
            cout << iter->id << " |";
            while(edgeIter->next){
                cout << edgeIter->vID << ", ";
                edgeIter = edgeIter->next;
            }
            cout << edgeIter->vID << endl;
        };

		
		
		void BFS(int s){
			Queue Q;
			int n  = listLength;
			int v, w;
			
			bool* discovered = new bool[n + 1];
			for(int i = 1; i <= n; ++i){
				discovered[i] = false;
			}
			Q.Enqueue(s);
			discovered[s] = true;
			
			while(!Q.IsEmpty()){
				//cout << "tis me?" << endl;
				v = Q.Dequeue();
				//cout <<" Probs" << endl;
                if(v != -1){
                    for(w = 1; w <= n; ++w){
                        if(IsConnected(v, w) and !discovered[w]){
                            cout << "(" << v << ", " << w << ")" << endl;
                            Q.Enqueue(w);
                            //cout << "Ummm" << endl;
                            discovered[w] = true;
                        }
                    }
                }
			}
			delete discovered;
            return;
		};
        
        void DFS(int s){
            Stack sTrack;
            int n  = listLength;
			int k, i;
            bool *visited = new bool[n+1];
            for(i = 0; i <= n; ++i){
                visited[i] = false;
            }
            visited[s] = true;
            sTrack.Push(s);
            while(!sTrack.IsEmpty()){
                k = sTrack.Pop();
                for(i = n; i >= 0; --i){
                    if(IsConnected(k, i) and !visited[i]){
                         cout << "(" << k << ", " << i << ")" << endl;
                        sTrack.Push(i);
                        visited[i] = true;
                    }
                }
            }
            delete visited;
        };
		
		
		void PrintMST(int mst[], int key[]){
			cout << "Vertex | Weight" << endl;
			for (int i = 0; i < listLength; ++i){
				cout << mst[i] << " " << key[i] << endl;
			}
			return;
		}
		
		void Prims(){
			int u, v;
			int mst[listLength];
			int key[listLength];
			bool explored[listLength];
			
			for(int i = 0; i < listLength; ++i){
				explored[i] = false;
				key[i] = INT_MAX;
			}
			
			key[0] = 0;
			mst[0] = -1;
			
			for(int count = 0; count < listLength - 1; ++count){
				u = minKey(key, explored);
				explored[u] = true;
				for (v = 0; v < listLength; ++v){
					if(IsConnected(u, v) && explored == false && getWeight(u,v) < key[v]){
						mst[v] = u;
						key[v] = getWeight(u,v);
					}
				}
			}
			PrintMST(mst, key);
			return;
		}
		
		void Kruskal(){
			int i = 0;
			Graph T;
			int 
			lint temp = head;
			
			while(temp->next){
				T.AddVerticie(temp->id);
				i++;
			}
			
			
		}
		
  private:  
        link head;
        link last;
        int listLength;

		
		int minKey(int key[], bool mstSet[]){
		   // Initialize min value
			int min = INT_MAX, min_index;
		 
			for (int v = 0; v < listLength; v++){
				if (mstSet[v] == false && key[v] < min){
					min = key[v];
					min_index = v;
				}
		    }
		    return min_index;
		}
		
		int getWeight(int u, int v){
			int rVal = -1;
			bool found = false;
			link find = FindSource(v);
			if(find){
				edge vFind = find->top;
				
				while(!found and vFind->next){
					if(vFind->vID == u) {
						found = true;
						rVal = vFind->weight;
					}
					vFind = vFind->next;
				}
				if(vFind->vID == u) rVal = vFind->weight;
			}
			return rVal;
		}
		
		bool IsConnected(int u, int v){
			bool rVal = false;
			link find = FindSource(v);
			if(find){
				edge vFind = find->top;
				
				while(!rVal and vFind->next){
					if(vFind->vID == u) rVal = true;
					vFind = vFind-> next;
				}
				if(vFind->vID == u) rVal = true;
			}
			return rVal;
		}
		
		/*
		Narrative: finds the element inside of the Verticie list
		Pre: Inititailized  List
		Post: Link to the hunted verticie returned
		*/
        link FindSource(int id){
            link iter = head;
            while(iter->next){
                if(iter->id == id)
                    return iter;
                iter = iter->next;
            }
            if(iter->id == id)
                return iter;
            return NULL;
        };

        edge NewVerticie(int dest){
            edge newV = new Joint;
            newV->vID = dest;
            newV->next = NULL;
            return newV;
        };

};

int main(){
    Graph stuff;
    int verticie, src, dest, weight;

    cout << "Enter '-1' when you are finished" << endl;
    //cout << "Please enter a verticie: ";
    cin >> verticie;
    while(verticie != -1){
			stuff.AddVerticie(verticie);
            //cout << "Please enter a verticie: ";
            cin >> verticie;

    }
    cout << "Enter '-1' when you are finished" << endl;
    //cout << "Now lets add some edges: ";
    cin >> src >> dest >> weight;
    while(src != -1 and dest != -1){
        if (!stuff.AddEdge(src, dest, weight))cout << "This is not a valid edge" << endl;
      //  cout << "Enter another Edge: ";
        cin >> src >> dest >> weight;
		cout << endl;
    }
    stuff.Print();
    
	cout << "Enter a Vertex to find using BFS (enter '-1' when finished): ";
	cin >> verticie;
    cout << endl;
	while (verticie != -1){
		stuff.BFS(verticie);
        cout << "Enter a Vertex to find using BFS (enter '-1' when finished): ";
		cin >> verticie;
	}
	cout << endl;
	
	cout << "Enter a Vertex to find using DFS (enter '-1' when finished): ";
	cin >> verticie;
    cout << endl;
	while (verticie != -1){
		stuff.DFS(verticie);
        cout << "Enter a Vertex to find using DFS (enter '-1' when finished): ";
		cin >> verticie;
	}
	cout << endl;
	
	stuff.Prims();
	
    return 0;
}
