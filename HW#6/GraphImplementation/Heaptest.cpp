#include "Heap.cpp"
#include <iostream>

using namespace std;

int main(){
    int src, dest, weight;
    Heap::element temp;
    Heap stuff(8);
    cin >> src >> dest >> weight;
    while(src != -1 and dest != -1){
        stuff.Insert(weight, dest, src);
      //  cout << "Enter another Edge: ";
        cin >> src >> dest >> weight;
		cout << endl;
    }
    stuff.Print();
    stuff.ChangeKey(1, 100, 3);
    stuff.Print();
    stuff.ChangeKey(4, 1, 3);
    stuff.Print();
    while(!stuff.Empty()){
        temp = stuff.Top();
        //cout << "topped: (" << temp.src <<" - " << temp.weight << " - " << temp.dest << ")" << endl;
        //cout << "proof: ";
        //stuff.Print();
    }
    
	return 0;
}
