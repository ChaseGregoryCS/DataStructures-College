#ifndef _HUP_
#define _HUP_

#include <iostream>

using namespace std;

class Heap{
	public:
        struct element{
                int weight;
                int dest;
                int src;
                int pos;
        };
        
		Heap(int size = 10): length(size){
			heap = new element[size+1];
			position = 0;
		};
		
		~Heap(){
			//delete heap;
		};

		void CreateHeap(element arrA[], int sizeofS){
			if(sizeofS > 0){
				for(int i = 0; i < length+1; ++i){
					Insert(arrA[i].weight, arrA[i].dest, arrA[i].src);
				}
			}
		};
		
		void Insert(int weight, int dest, int src){
			if(position == 0){
                position++;
				heap[position].weight = weight;
                heap[position].dest = dest;
                heap[position].src = src;
			}else{
                position++;
				heap[position].weight = weight;
                heap[position].dest = dest;
                heap[position].src = src;
                HeapifyUp(position);
			}

		};
		
		
        void HeapifyUp(int i){
            int j;
            element temp;
            if( i > 1){
               j = i/2;
               if(heap[i].weight < heap[j].weight){
                   Swap(i, j);
                   heap[j].pos = j;
                   HeapifyUp(j);
               }
            }
        };
        
		element Top(){
			//cout << "topping" << endl;
			element min = heap[1];
			heap[1] = heap[position];
            heap[position].weight = 0;
			position--;
			HeapifyDown(1);
            //Print();
			return min;
		};
		
        void ChangeKey(int who, int weight, int dest){
			//cout << "ChangeKey" << endl;
            //Print();
            int parent, i = 0;
            while(heap[i].src != who and (i < length + 1)) {
				++i;
				//cout << i << endl;
			}
			
			heap[i].weight = weight;
			heap[i].dest = dest;
            parent = i/2;
			//cout << "ChangeKey" << endl;
            if(heap[parent].weight >= heap[i].weight) HeapifyUp(i);
            else HeapifyDown(i);
			//cout << "here " << endl;
			//Print();
        };
        
		void HeapifyDown(int i){
			int left, right, j, n = position;
            if(2*i > n)
                return;
            else if(2*i < n){
                left = 2*i;
                right = 2 * i + 1;
                if(heap[left].weight > heap[right].weight) j = right;
                else j = left;
            }else j = 2 * i;
            
            if(heap[j].weight < heap[i].weight){
                Swap(i, j);
                heap[j].pos = j;
                HeapifyDown(j);
                
            }
		};
		
		bool Empty(){
			return (position == 0);
		};
		
		void Print(){
            cout << "(src - weight - dest)" << endl;
            int i =1;
            cout << "(" << heap[i].src << " - " << heap[i].weight << " - " << heap[i].dest << ")";
			for(i =2; i < position+1; i++){
				cout << " (" << heap[i].src << " - " << heap[i].weight << " - " << heap[i].dest << ")";
			}
			cout << " " << endl;
		};
	
	private:
		element* heap;
		int position;
		int length;
        
		void Swap(int from, int to){
			element temp = heap[to];
			heap[to] = heap[from];
			heap[from] = temp;
			return;
		};
};


#endif
