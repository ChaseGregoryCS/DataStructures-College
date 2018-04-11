#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "StopWatch.cpp"

using namespace std;

void GenerateNumbers(int size, int list[], int min, int max){
	srand(time(NULL));
	
    for (int n = 0; n < size; n++){
        list[n] = (rand()% (int)(max - min + 1) + min);
    }
	return;
}

int main(){
	
    StopWatch watch;
    int cnt, i, j, k, N;
    
    cout << "Time Data " << endl;
    cin >> N;
	
	int list[N];
 	GenerateNumbers(N, list, -1000000, 1000000);
	
	watch.Start();
	i = 0;
	cnt = 0;
	while ( i < N){
			j = i + 1;
			while ( j < N){
				k = j + 1;
				while ( k < N){
					if ((list[i] + list[j] + list[k]) == 0){
							cnt += 1;
							//cout << watch.Split() << endl;
					}
					k += 1;
				}
				j += 1;
			}
			i += 1;
	}
	cout << watch.Split() << endl;
    cout << cnt << endl;
    return 0;
}
