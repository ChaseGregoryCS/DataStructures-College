//#ifndef _GPH_
//#define _GPH_

#include <iostream>
#include <string>
#include "Heap.cpp"
#include "UnionFind.cpp"
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
			int src;
            int dest;
            edge next;
            int weight;
        };

		//Constructor
        Graph():head(NULL), last(NULL), listLength(0), edgeWeights(NULL), edgeIndex(0){};

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
            if (!edgeIndex){
                edgeWeights = NewVerticie(dest, src, weight);
                edgeTail = edgeWeights;
            }else{
                edge temp = NewVerticie(dest, src, weight);
                edgeTail->next = temp;
                edgeTail = temp;
                temp = NULL;
            }
            link source = FindSource(src);
            link destination = FindSource(dest);
            if(!source or !destination) return false;
            edge newV = NewVerticie(dest, src, weight);
            newV->next = source->top;
            source->top = newV;
            newV = NewVerticie(src, dest, weight);
            newV->next = destination->top;
            destination->top = newV;
			edgeIndex++;
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
            cout << "Verticie | (Edges to, Weight) " << endl;
            while(iter->next){
                edgeIter = iter->top;
                cout << iter->id << " |";
                while(edgeIter->next){
                    cout <<  " ("<< edgeIter->dest << ", "<< edgeIter->weight << "), " ;
                    edgeIter = edgeIter->next;
                }
                cout <<  " ("<< edgeIter->dest << ", " << edgeIter->weight << "), " << endl;
                iter = iter->next;
            }
            edgeIter = iter->top;
            cout << iter->id << " |";
            while(edgeIter->next){
                cout <<  " ("<< edgeIter->dest << ", "<< edgeIter->weight << "), " ;
                edgeIter = edgeIter->next;
            }
            cout <<  " ("<< edgeIter->dest << ", "<< edgeIter->weight << "), "  << endl;
        };

		void Prims(){
                int wlength = 0;
                int n = listLength;
                bool newTree = false;
                edge iter;
                link traverse = head;
                
                bool verticies[n];
                int weights[n];
                int positions[n];
                
                Heap pQ(n);
                Heap::element mst[n];
                Heap::element temp;
                
                for(int i = 0; i < n + 1; ++i){
                    weights[i] = INT_MAX;
                    verticies[i] = false;
                }
                int start = 0;
                weights[start] = 0;
                verticies[start] = true;
                
                while(traverse->next){
                    pQ.Insert(INT_MAX, 0, traverse->id);
                    traverse = traverse->next;
                }pQ.Insert(INT_MAX, 0 ,traverse->id);
                pQ.ChangeKey(0, 0, 0);
				
				temp = pQ.Top();
				verticies[temp.dest] = true;
				mst[wlength] = temp;
				iter = FindSource(temp.src)->top;
				while(iter->next){
					if(iter->weight < weights[iter->dest] and !verticies[iter->dest]){
						pQ.ChangeKey(iter->dest, iter->weight, iter->src);
						weights[iter->dest] = iter->weight;
					}
					iter = iter->next;
				}if(iter->weight < weights[iter->dest] and !verticies[iter->dest]){
						pQ.ChangeKey(iter->dest, iter->weight, iter->src);
						weights[iter->dest] = iter->weight;
                }
				wlength++;
				
                while(!pQ.Empty()){
                    temp = pQ.Top();
                    verticies[temp.dest] = true;
                    if(temp.src < edgeIndex){
                    mst[wlength] = temp;
                    iter = FindSource(temp.src)->top;
                    while(iter->next){
                        if(iter->weight < weights[iter->dest] and !verticies[iter->dest]){
                            pQ.ChangeKey(iter->dest, iter->weight, iter->src);
                            weights[iter->dest] = iter->weight;
                        }
                        iter = iter->next;
                    }
                    if(iter->weight < weights[iter->dest] and !verticies[iter->dest]){
                        pQ.ChangeKey(iter->dest, iter->weight, iter->src);
                        weights[iter->dest] = iter->weight;
                    }
					wlength++;
                    }
                }
                int ttlW = 0;
                int i = 1;
                cout << "(src - weight - dest)" << endl;
                cout << "(" << mst[i].src << " - " << mst[i].weight << " - " << mst[i].dest << ")";
                ttlW += mst[i].weight;
                for (i = 2; i < n; ++i){
					cout << ", (" << mst[i].src << " - " << mst[i].weight << " - " << mst[i].dest << ")";
                    ttlW += mst[i].weight;
				}
				cout << endl;
                cout << "Total Weight: " << ttlW << endl;
            };
		
        void Kruskals(){
            Joint temp;
            int insertIndex = 0;
            int x,y;
            edge weights = new Joint[edgeIndex];
            edge iter = edgeWeights;
            
            while(iter->next){
                weights[insertIndex] = *iter;
                insertIndex++;
                iter= iter-> next;
            }
            weights[insertIndex] = *iter;
            insertIndex++;
            
            QuickSort(weights, 0, insertIndex-1);
            
            insertIndex = 0;
            Joint mst[listLength];
            UnionFind forest(listLength);
            
            for(int i = 0; i < edgeIndex -1; ++i){
                    temp =  weights[i];
                    x = forest.Find(temp.src);
                    y = forest.Find(temp.dest);
                    if(x != y){
                        mst[insertIndex] = temp;
                        insertIndex++;
                        forest.Merge(x, y);
                    }
            }
            int ttlW = 0;
            int k = 0;
            cout << "(src - weight - dest)" << endl;
            cout << "(" << mst[k].src << " - " << mst[k].weight << " - " << mst[k].dest << ")";
            ttlW += mst[k].weight;
            for (k = 1; k < insertIndex; ++k){
                cout << ", (" << mst[k].src << " - " << mst[k].weight << " - " << mst[k].dest << ")";
                ttlW += mst[k].weight;
            }
            cout << endl;
            cout << "Total Weight: " << ttlW << endl;
        };
		
  private:  
        link head;
        link last;
        int listLength;
		edge edgeWeights;
        edge edgeTail;
		int edgeIndex;
		
        Joint GetWeight(int u, int v){
            int i = 0;
            Joint rVal;
            rVal.weight = -1;
            rVal.src = -1;
            rVal.dest = -1;
            
            edge iter;
            //cout << u << endl;
            link find = FindSource(u);
            if(find) iter = find->top;
            else return rVal;
            while(iter->next and i != v){
                i++;
                iter = iter->next;
            }
            if(iter->next == NULL) rVal = *iter;
            return rVal;
        };
		
		bool IsConnected(int u, int v){
			bool rVal = false;
			link find = FindSource(v);
			if(find){
				edge vFind = find->top;
				
				while(!rVal and vFind->next){
					if(vFind->src == u) rVal = true;
					vFind = vFind-> next;
				}
				if(vFind->src == u) rVal = true;
			}
			return rVal;
		};
		
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

        edge NewVerticie(int dest, int src, int weight){
            edge newV = new Joint;
            newV->dest = dest;
			newV->src = src;
			newV->weight = weight;
            newV->next = NULL;
            return newV;
        };

        void QuickSort(edge list, int left, int right){
            int i = left, j = right;
            int tmp;
            int pivot = list[(left + right)/ 2].weight;
            
            while(i <= j){
                while(list[i].weight < pivot) i++;
                while(list[j].weight > pivot) j--;
                if(i <= j){
                    Swap(list, j, i);
                    i++;
                    j--;
                }
            }
            if(left < j) QuickSort(list, left, j);
            if(i < right) QuickSort(list, i, right);
            return;
        };
        
        void Swap(edge list, int from, int to){
            Joint temp = list[to];
            list[to] = list[from];
            list[from] = temp;
            return;
        };

        
};
//#endif

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
    cout << "----------------------------Prim's---------------------" << endl;
	stuff.Prims();
    cout << "----------------------------Kruskal's---------------------" << endl;
    stuff.Kruskals();
	
    return 0;
}

