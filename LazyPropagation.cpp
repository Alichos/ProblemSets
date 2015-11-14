#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;

int n;
struct SegmentTree{
    int lazy[MAXN * 4];
    int tree[MAXN * 4];
    void update(int nodo, int izq, int der, int i, int j, int valor){
        if(lazy[nodo] > 0){
            tree[nodo] += lazy[nodo];
            if(a != b){
                lazy[nodo * 2] = lazy[nodo];
                lazy[(nodo * 2) + 1] = lazy[nodo];
            }
            lazy[nodo] = 0;
        }
        
        if(izq > der || izq > j || der < i) 
            return;
        
        if(i <= izq && der <= j){
            tree[nodo] += valor;
            if(a != b){
                lazy[node * 2] = valor;
                lazy[(node * 2) + 1] = valor;
            }
            return;
        }
        
        int mitad = (izq + der) / 2;
        update(nodo * 2, izq, mitad, i, j, valor);
        update((nodo * 2) + 1, mitad + 1, der, i, j, valor);
        
        tree[nodo] = max(tree[nodo * 2] ,
                          tree[(nodo * 2) + 1]);
    }
    
    void update_(int i, int j, int valor){
        update(1, 1, n - 1, i, j, valor);
    }
};

int main(){
  return 0;
}
