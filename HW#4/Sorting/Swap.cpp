#include "StopWatch.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

void GenerateNumbers(int size, int list[], int min, int max){
	srand(time(NULL));
	
    for (int n = 0; n < size; n++){
        list[n] = (rand()% (int)(max - min + 1) + min);
    }
	return;
}

void CopyOver(int list[], int otherList[], int size){
        for(int i = 0; i < size; i++) otherList[i] = list[i];
        return;
}

void Print(int list[], int size){
    for(int i = 0; i < size; i++) cout << list[i] << ", ";
    cout << "\n---------------------------------------------------------------------------" << endl;
    cout << endl;
}

void Swap(int list[], int from, int to){
    int temp = list[to];
    list[to] = list[from];
    list[from] = temp;
    return;
}


//----------------------------------HEAPSORT-----------------------------------------------------------------------

void Sink(int list[], int i, int size){
    int middleChild, rightChild, leftChild;
    leftChild = 2*i;
    if (leftChild > size) return;
    rightChild = leftChild + 1;
    middleChild = (rightChild > size) ? leftChild : (list[leftChild] > list[rightChild]) ? leftChild : rightChild;
    if (list[i] >= list[middleChild]) return;
    Swap(list, i, middleChild);
    Sink (list, middleChild, size);
}

void HeapSort(int size, int list[]){
    int i;
    int heapsize = size - 1;
    for(i = (size/2); i >= 0; i--) Sink(list, i, heapsize);
    
    for(i = heapsize; i >=0; i--){
        Swap(list, heapsize, 0);
        heapsize--;
        Sink(list, 0, heapsize);
    }
    return;
}
//-----------------------------------------------------------------------------------------------------------------


void SelectionSort(int size, int list[]){
    int i, j, k;
    for(i = size - 1; i > 0; i--){
        k = 0;
        for(j = 1; j <= i; j++){
            if(list[j] > list[k]) k = j;
            Swap(list, i, k);
        }
    }
    return;
}


//---------------------------------------------MergeSort----------------------------------------------------------

void CopyArray(int b[], int begin, int end, int a[]){
    for(int i = begin; i < end; i++){
            a[i] = b[i];
    }
    return;
}

void Merge(int a[], int begin, int middle, int end, int b[]){
    int i = begin;
    int j = middle;
    for(int k = begin; k < end; k++){
        if(i < middle && (j >= end || a[i] <= a[j])){
            b[k] = a[i];
            i++;
        }else{
            b[k] = a[j];
            j++;
        }
    }
    return;
}

void Split(int b[], int begin, int end, int a[]){
    int middle;
    if((end - begin) < 2) return;
    middle = (end + begin) / 2;
    Split(a, begin, middle, b);
    Split(a, middle, end, b);
    Merge(b, begin, middle, end, a);
    return;
}


void MergeSort(int list[], int size){
    int * b = new int[size];
    CopyArray(list, 0, size, b);
    Split(b, 0, size, list);
    delete b;
    return;
}

//----------------------------------------------------------------------------------------------------------------

void QuickSort(int list[], int left, int right){
    int i = left, j = right;
    int tmp;
    int pivot = list[(left + right)/ 2];
    
    while(i <= j){
         while(list[i] < pivot) i++;
         while(list[j] > pivot) j--;
         if(i <= j){
            Swap(list, j, i);
            i++;
            j--;
         }
    }
    if(left < j) QuickSort(list, left, j);
    if(i < right) QuickSort(list, i, right);
    return;
}

void BubbleSort(int size, int list[]){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(list[j] < list[i]){
                Swap(list, j, i);
            }
        }
    }
    //Print(list, size);
    return;
}


int main(){
    StopWatch watch;
    long time;
    int size;
    int * tempList;
    cout << "Please enter the list size: ";
    cin >> size;
    cout << endl;
    int * list = new int[size];
    GenerateNumbers(size, list, 1, 100);
    cout << "Original List: " << endl; 
    Print(list, size);
    tempList = new int[size];
    CopyOver(list, tempList, size);
    
    watch.Start();
    BubbleSort(size, tempList);
    time = watch.Split();
    cout << "BubbleSort: " << time << endl;
    Print(tempList, size);
    delete tempList;
    tempList = new int[size];
    CopyOver(list, tempList, size);
    
    watch.Start();
    SelectionSort(size, tempList);
    time = watch.Split();
    cout << "SelectionSort: " << time << endl; 
    Print(tempList, size);
    delete tempList;
    tempList = new int[size];
    CopyOver(list, tempList, size);

    watch.Start();
    HeapSort(size, tempList);
    time = watch.Split();
    cout << "HeapSort: " << time << endl; 
    Print(tempList, size);
    delete tempList;
    tempList = new int[size];
    CopyOver(list, tempList, size);

    watch.Start();
    //Print(tempList, size);
    MergeSort(tempList, size);
    time = watch.Split();
    cout << "MergeSort: " << time << endl;
    Print(tempList, size);
    delete tempList;
    tempList = new int[size];
    CopyOver(list, tempList, size);

    watch.Start();
    QuickSort(tempList, 0, size-1);
    time = watch.Split();
    cout << "QuickSort: " << time << endl; 
    Print(tempList, size);
    delete tempList;
    delete list;
    
    return 0;
}
