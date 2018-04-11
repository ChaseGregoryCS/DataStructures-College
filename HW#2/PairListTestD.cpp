#include "PairList.h"
#include <iostream>

using namespace std;

int main(){
    PairList stuff;
    stuff.Insert("m", "w");
    cout << stuff["m"] << endl;
    stuff.Remove("m");
    cout << stuff["m"] << endl;
}
