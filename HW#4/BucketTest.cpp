#include "Bucket.h"
#include <iostream>

using namespace std;

int main(){
	int stuffethsize = 50;
    int stuffeth[50] = {10, 10, 11, 20, 30, 11, 31, 41, 41, 12, 12, 22, 32, 32, 42, 42, 13, 13, 13, 43, 43, 43,
                     14, 14, 14, 24, 44, 15, 15, 15, 15, 15, 45, 35, 46, 46, 46, 46, 17, 17, 27, 37, 37, 37,
                     18, 28, 38, 38, 48, 39};
	Bucket stuff;
	stuff.Insert(1);
	stuff.Insert(7);
	stuff.Insert(2);
	stuff.Insert(4);
	stuff.Insert(3);
	stuff.Insert(5);
	stuff.Insert(6);
	cout << stuff.GetMin() << endl;
	cout << stuff.GetMax() << endl;
	
	Bucket sortedStuff;
    for(int i = 0; i < stuffethsize; ++i){
		cout << stuffeth[i] << endl;
        sortedStuff.SortedInsert(stuffeth[i]);
        
    }
    sortedStuff.PrintBucket();
	cout << endl;
	cout << sortedStuff.GetMin() << endl;
	cout << sortedStuff.GetMax() << endl;	
	
	return 0;
}
