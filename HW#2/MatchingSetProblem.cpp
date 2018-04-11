#include "StringStack.h"
#include "PeopleList.h"
#include "PairList.h"

using namespace std;

void PushPreference(PeopleList * set){
    cout << endl;
	StringStack* pushData = new StringStack();
	string input = "";
	int i = 1;
	cin >> input;
	while (input != "XXXXXX"){ //six X's 
        if(input != "XXXXXX"){
            pushData->Push(input);
            i++;
        }
		cin >> input;
	}
    
    set->PropPrefStack(*pushData);
    return;
}


void MatchSet(PeopleList& M, PeopleList& W){
//     cout << "m->length() " << M.Length() << " w->length() " << W.Length() << endl;
	cout << endl << endl;
	int numberFree = M.Length(); 
	int iter = 1;
	int weight;
	int wLatcheWeight;
	StringStack freeMen;
	StringStack	freeWomen;
	M.SetIterHead();
	W.SetIterHead();
	
	string chosenMan;
	string chosenPreference;
	string ladyPreference;
    string mPrime;
    
	PairList proposed;
	
	PeopleList::Link iterator;
    
    
	//Initially all men and women are free
	M.SetIterHead();
	mPrime = M.GetIterName();
    freeMen.Push(mPrime);
	while(M.StepInto()){
        mPrime = M.GetIterName();
		freeMen.Push(mPrime);
	}
    
	W.SetIterHead();
    mPrime = W.GetIterName();
    freeWomen.Push(mPrime);
	while(W.StepInto()){
        mPrime = W.GetIterName();
        freeWomen.Push(mPrime);
	}
    
	while(!freeMen.IsEmpty() ){ //while there is a man free and hasn't proposed
		cout << "===========================iteration#: " << iter << " ===========================" << endl;
		cout << "//while there is a man free and hasn't proposed" << endl;
		chosenMan = freeMen.Pop();//Choose a man
		cout << "//Choose a man: " << chosenMan <<  endl;
		chosenPreference = M[chosenMan];  //Let w be the highest w on m's preference
		cout << "//Let w be the highest w on m's preference: " << chosenPreference << endl;
		if(freeWomen[chosenPreference]){ // if w is free
			cout << "// if " << chosenPreference << " is free " << "(" << chosenMan << "," << chosenPreference << ") engaged" << endl;
			proposed.Insert(chosenMan, chosenPreference); //(m,w) engaged
			//set the latched weights
			weight = W.GetWeight(chosenPreference, chosenMan);
			W.SetIterLatchedWeight(weight, chosenPreference);
            freeWomen.Remove(chosenPreference);
		}else{ //w is engaged to another man
			cout << chosenPreference << " is engaged to another man" << endl;
            weight = W.GetWeight(chosenPreference, chosenMan);
			wLatcheWeight = W.GetLatchedWeight(chosenPreference);
            if(wLatcheWeight > weight ){ //w prefers m' to m
				cout << chosenPreference << " prefers " << chosenMan << " to m' //m' becomes free " << "(" << chosenMan << "," 
				     << chosenPreference << ") engaged" << endl;
				mPrime = proposed.RemoveW(chosenPreference);
				cout << "mPrime: " << mPrime << " chosenPreference: " << chosenPreference <<endl;
                W.IterRemove(ladyPreference, mPrime);
                freeMen.Push(mPrime); //m' becomes free
                proposed.Insert(chosenMan,chosenPreference); //(m,w) engaged;
				weight = W.GetWeight(chosenPreference, chosenMan);
				W.SetIterLatchedWeight(weight, chosenPreference);
            }else{ //w prefers m to m'
				freeMen.Push(chosenMan); // m remains free
				W.IterRemove(ladyPreference, chosenMan);
				
				cout << chosenPreference << " prefers otherGuy to " << chosenMan << " //m remains free" << endl;
            }

			
        }
		iter++;
	}
	cout << "\n\n\n+++++++++++++++++++++++++Stable matching+++++++++++++++++++++++++" << endl;
	proposed.Display(cout);
	cout << endl << endl;
}



int main(){
	PeopleList * M = new PeopleList();
	PeopleList * W = new PeopleList();
    string testAgain = "";
    
    string input = "";
    int i = 1;
    while (testAgain != "n"){
        input = "";
        while(input != "XXXXXX"){
                cout << "Man " << i << ": ";
                cin >> input;
                cout << endl;
                if (input != "XXXXXX"){
                    //cout << "\tadding " << input << endl;
                    M->Insert(input);
                    i++;
            }
        }
        i = 1;
        input = "";
        
        while(input != "XXXXXX"){
                cout << "Woman " << i << ": ";
                cin  >> input;
                cout << endl;
                if (input != "XXXXXX"){
                    //cout << "\tadding " << input << endl;
                    W->Insert(input);
                    i++;
                }
        }
        
        //cout << "m->length() " << M->Length() << " w->length() " << W->Length() << endl;
		cout << "==========================Gents=========================" << endl;
        PushPreference(M);
        cout << "==========================Ladies========================" << endl; 
		PushPreference(W);
        
        MatchSet(*M, *W);
        delete M;
        delete W; 
        M = new PeopleList();
        W = new PeopleList();
        cout << "Test Again?: " << endl;
        cin >> testAgain;
    }
}
