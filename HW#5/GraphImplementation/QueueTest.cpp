#include "StringQueue.h"
#include <iostream>

using namespace std;

int main(){
	StringQueue test;
	string val;
	test.Enqueue("A");
	val = test.Dequeue();
	
	cout << val << endl;
	
	test.Enqueue(val);
	test.Enqueue("B");
	
	
	test.Dequeue();
	val = test.Top();
	
	cout << val << endl;
	return 0;
}