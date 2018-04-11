#ifndef _UFDS_
#define _UFDS_

#include <iostream>

using namespace std;

class UnionFind{
    public:
        UnionFind(int size):n(size){
            parent = new int[n+1];
            rank = new int[n+1];

            //initially all verticies are in different sets and all ranks are 0;
            for(int i = 0; i < n; ++i){
                rank[i] = 0;
                parent[i] = i;
            }
        };
        
        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        };

        //Find method, recursive path compression method
        int Find (int u){
            if( u!= parent[u]) parent[u] = Find(parent[u]);
            return parent[u];
        };

        void Merge(int x, int y){
            x = Find(x);
            y = Find(y);

            if(rank[x] > rank[y]){
                parent[y] = x;
            }else parent[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        };
    private:
        int* parent;
        int* rank;
        int n;

};

#endif
