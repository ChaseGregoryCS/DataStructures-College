#include "HashTable.h"
#include "Bucket.h"

using namespace std;

HashTable::HashTable(): sorted(false){}
HashTable::HashTable(bool isSorted): sorted(isSorted){}

void HashTable::Insert(int data){
    int hashBrown = HashBrown(data);
    if(sorted){
            table[hashBrown].SortedInsert(data);
    }else table[hashBrown].Insert(data);
    return;
}

void HashTable::Print(){
    for(int i = 0; i < 10; ++i){
            cout << "Bucket " << (i) << ": ";
            table[i].PrintBucket();
            cout << endl;
    }
    return;
}

int HashTable::FindNum(int index, int num){
	return table[index].Find(num);
}

int HashTable::GetMax(int index){
    return table[index].GetMax();
}

int HashTable::GetMin(int index){
    return table[index].GetMin();
}

int HashTable::HashBrown(int data){
    return data % 10;
}

