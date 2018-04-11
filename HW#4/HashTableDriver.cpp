#include "HashTable.h"
#include "Bucket.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void GenerateNumbers(int size, int list[], int min, int max){
	srand(time(NULL));
	
    for (int n = 0; n < size; n++){
        list[n] = (rand()% (int)(max - min + 1) + min);
    }
	return;
}

void FindValues(int min, int max, HashTable table, int averages[]){
	int probeLengthSum = 0;
	int j;
	for(int i = 0; i < 10; ++i){
		for(j=min; j <= max; ++j){
			probeLengthSum += table.FindNum(i, j);
		}
		averages[i] = probeLengthSum/(abs(min) + abs(max));
		probeLengthSum = 0;
	}
	return;
}

int main(){
	fstream file()
	int size, min, max;
	HashTable testSort(true);
	cin >> size >> min >> max;
	cout << endl;
	int list[size];
	int averages[10];	
	GenerateNumbers(size, list, min, max);
	for (int i = 0; i < size; ++i){
		testSort.Insert(list[i]);
	}
	
//	testTable.Print();
	testSort.Print();
	
	FindValues(min, max, testSort, averages);
	
	return 0;
}
