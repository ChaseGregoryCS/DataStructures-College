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

int FindValues(int min, int max, HashTable table){
	int probeLengthSum = 0;
	int j, val, numFound = 0;
	for(int i = 0; i < 10; ++i){
		for(j=min; j <= max; ++j){
            val = table.FindNum(i, j);
            if (val){
                probeLengthSum += val;  
                ++numFound;
            }
		}
	}
	return probeLengthSum/numFound;
}

int SetTestVal(int val){
	int rVal;
	if(val == 0) rVal = 50;
	else if(val == 250) rVal = 20000;
	else rVal = val + 50;
	return rVal;
}

int main(){
	fstream file;
	bool sorted = false;
	int size = 50;
	int tests;
	int min, max, j, i = 0;
	HashTable * hash = new HashTable(sorted);
	min = 1;
	max = 100;
	file.open("OutData.csv", ios::trunc | ios::out);
	file << "sorted, size, avg,\n";
	file.close();
	cout << endl;
	int * list;
	int averages;
	while (i < 2){
		tests = 0;
		size = 0;
        averages = 0;
		while(tests < 6){
			size = SetTestVal(size);
			list = new int[size];
			
			GenerateNumbers(size, list, min, max);
			for(j = 0; j < size; j++){
				hash->Insert(list[j]);
			}
			//hash->Print();
			cout << size;
			averages = FindValues(min, max, *hash);
			
			file.open("OutData.csv", ios::app | ios::out);
			file << sorted << ", " << size << ", " << averages << ",";
			file << "\n";
			file.close();
			cout << "test# " << tests << " completed" << endl;
			
			
			tests++;
			delete list;
		}
		delete hash;
		sorted = true;
		hash = new HashTable(sorted);
		i++;
	}
	return 0;
}
