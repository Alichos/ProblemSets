#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;

int n;
struct SegmentTree{
    int lazy[MAXN];
    int tree[MAXN];
    void update(int nodo, int izq, int der, int i, int j, int valor){
        if(lazy[nodo] > 0){
            tree[nodo] += lazy[nodo];
            if(a != b){
                lazy[nodo * 2] = lazy[nodo];
                lazy[(nodo * 2) + 1] = lazy[nodo];
            }
            lazy[nodo] = 0;
        }
        
        
    }
    
    void update_(int i, int j, int valor){
        update(1, 1, n - 1, i, j, valor);
    }
};

int main(){
  return 0;
}
