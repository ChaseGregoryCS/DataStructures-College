#include "Stack.h"
#include <iostream>

using namespace std;

int main(){
	Stack * stack = new Stack();
	cout << "here" << endl;
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	stack->Push(4);
	stack->Push(5);
	stack->Push(6);
	stack->Push(7);
	stack->Push(8);
	cout << "here?" << endl;
	
	stack->Display(cout);
// 	stack->Push("BOB4");
// 	stack->Push("BOB5");
// 	stack->Push("BOB6");
// 	stack->Push("BOB7");
// 	stack->Push("BOB8");
// 	Stack* otherStack = stack;
// 	cout << "otherStack->Top()" << otherStack->Top() << endl;
// 	while(!otherStack->IsEmpty()){
// 		std::cout << otherStack->Pop() << endl; 
// 		cout << "otherStack->Top()" << otherStack->Top() << endl;
// 	}
	delete stack;
}
