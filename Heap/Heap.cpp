#include <iostream>
#include <stdlib.h>
#include <time.

class HeapItem{
    public:
        HeapItem();
        HeapItem(int key, int data);
        int getKey();
        void setKey();
        int getData();
        void setData(int otherData);

    private:
        int mKey;
        int mData;
};

class Heap{
    public:
        HeapItem * arrPointer;
        int numEle;
        int length;
    private:
        Heap(int size = 10);
        ~Heap();
        void HeapifyUp(int root, int bottom);
        void HeapifyDown(int root, int bottom);
        bool Enqueue(HeapItem *item);
        bool Enqueue(int key, int data);
        HeapItem *Dequeue();
        int getNumElements();
        void Print();
    
};

HeapItem::HeapItem(): mKey(0), mData(0){}
HeapItem::HeapItem(int key, int data): mKey(key), mData(data){}

int HeapItem::getKey(){return mKey;}
void HeapItem::setKey(int key){mKey = key; return;}
int HeapItem::getData(){return data;}
void HeapItem::setData(int data){mData = data; return;}

Heap::Heap(int size):numEle(0), length(size){arrPointer = new HeapItem[size];}
Heap::~Heap(){delete[] arrPointer;}

void Heap::HeapifyDown(int root, int bottom){
        int maxChild, rightIndex, leftIndex;
        heapItem temp;

        leftIndex = root*2+1;
        rightIndex = root*2+2;
        
        if(leftIndex <= bottom){
            if(leftIndex == bottom) maxChild = leftIndex;
            else{
                if(arrPointer[leftIndex].getKey() <= arrPointer[rightIndex]) maxChild = rightIndex;
                else maxChild = leftIndex;
            }
        }
        if(arrPointer[root].getKey() < arrPointer[maxChild].getKey()){
            temp = arrPointer[root];
            arrPointer[root] = arrPointer[maxChild];
            arrPointer[maxChild] = temp;
            HeapifyDown(maxChild, bottom);
        }
    return;
}

void Heap::HeapifyUp(int root, int bottom){
    int parent;
    HeapItem temp;

    if(bottom > root){
        parent = (bottom - 1)/2;
        if(arrPointer[parent].getKey() < arrPointer[bottom].getKey()){
            temp = arrPointer[parent];
            arrPointer[parent] = arrPointer[bottom];
            arrPointer[bottom] = temp;
            HeapifyUp(root, parent);
        }
    }
    return;
}

bool Heap::Enqueue(HeapItem* item){
        if(numEle < length){
                arrPointer[numEle] = *item;
                HeapifyUp(0, numEle);
                numEle ++;
                return true;
        }else return false;
}


bool Heap::Enqueue(int key, int data){
        bool rValue;
        heapItem *temp = new HeapItem(key, data);
        rValue = Enqueue(temp);
        delete temp;
        return rValue;
}

HeapItem* Heap::Dequeue(){
        heapItem* temp = new HeapItem(arrPointer[0].getKey(), arrPointer[0].getData());
        numEle --;
        arrPointer[0] = arrPointer[numEle];
        HeapifyDown(0, numEle - 1);
        if(numEle == 0) return NULL;
        else return temp;
}



int Heap::getNumElements(){return numEle;}

void Heap::Print()
{
     for(int i=0; i<numEle; i++)
     {
          cout << "Heap element " << i << ". key=" << arrPointer[i].getKey() << "  data=" <<
               arrPointer[i].getData() << endl;
     }
     return;
}






