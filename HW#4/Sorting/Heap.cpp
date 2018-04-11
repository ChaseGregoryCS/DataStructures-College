#include <iostream>

using namspace std;

class Heap{
	public:
		struct HeapElement{
			int key;
			int data;
			bool infinity;
			bool empty;
		};

		Heap(int size = 10): length(size){
			heap = new HeapElement[size];
			for(int i = 0; i < size; ++i){
				heap[i].infinity = false;
				heap[i].empty = true;
			}	
		};
		
		void SetInfinity(){
			for(int i = 0; i < size; ++i){
				heap[i].infinity = true;
				heap[i].empty = false;
			}
		}
		
		~Heap(){
			delete[] heap;
		}
		
		void ChangeKey(int who, int what){
			for(int i = 0; i < length; ++i){
				if(heap[i].key == who) heap[i].key = what;
			}
		};
		
		void ChangeData(int key, int data){
			for(int i = 0; i < length; ++i){
				if(heap[i].key == key) heap[i].data = data;
			}
		}
		
		
		
		int GetLength() const{
			return length;
		}
		
		int GetKey(int index) const{
			return heap[index].key;
		};
		
		int GetData(int index) const{
			return heap[index].data;
		};
		
		bool IsInfinity(int index) const{
			return heap[index].infinity;
		};
		
		bool IndexEmpty(int index) const{
			return heap[index].empty;
		};
		
        void HeapSort(Heap list[]){
            int i;
            int heapsize = length - 1;
            for(i = (length/2); i >= 0; i--) Sink(list, i, heapsize);
            
            for(i = heapsize; i >=0; i--){
                Swap(list, heapsize, 0);
                heapsize--;
                Sink(list, 0, heapsize);
            }
            return;
        };
	
	private:
		HeapElement* heap;
		int length;
	
		void Sink(Heap list[], int i, int size){
            int middleChild, rightChild, leftChild;
            leftChild = 2*i;
            if (leftChild > size) return;
            rightChild = leftChild + 1;
            middleChild = (rightChild > size) ? leftChild : (list[leftChild].key > list[rightChild].key) ? leftChild : rightChild;
            if (list[i].key >= list[middleChild].key) return;
            Swap(list, i, middleChild);
            Sink (list, middleChild, size);
        };		
		
		void Swap(int list[], int from, int to){
			int temp = list[to];
			list[to] = list[from];
			list[from] = temp;
			return;
		};
		


};
