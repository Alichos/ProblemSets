#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30); 
const int MAXN = 100002;

int n;
struct SegmentTree{
    int lazy[MAXN * 4];
    int tree[MAXN * 4];
    
    void propaga(int nodo){
        lazy[nodo * 2] = lazy[nodo];
        lazy[(nodo * 2) + 1] = lazy[nodo];
    }
    
    void construye(int nodo, int izq, int der){
        if(izq > der)
            return;
            
        if(izq == der){
            tree[nodo] = INF;
            return;
        }
        
        int mitad = (izq + der) / 2;
        construye(nodo * 2, izq, mitad);
        construye((nodo * 2) + 1, mitad + 1, der);
    }
    
    void update(int nodo, int izq, int der, int i, int j, int valor){
        if(lazy[nodo] > 0){
            tree[nodo] += lazy[nodo];
            if(a != b)
                propraga(nodo);
            lazy[nodo] = 0;
        }
        
        if(izq > der || izq > j || der < i) 
            return;
        
        if(i <= izq && der <= j){
            tree[nodo] += valor;
            if(a != b)
                propaga(nodo);
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
    
    int query(int nodo, int izq, int der, int i, int j){
        if(izq > der || j < izq || i > der)
            return -inf;
        
        if(lazy[nodo] != 0){
            tree[nodo] += lazy[nodo];
            if(a != b)
                propaga(nodo);
            lazy[nodo] = 0;
        }
        
        if(izq >= i && der <= j)
            return tree[nodo];
        
        int mitad = (izq + der) / 2;
        int hijoIzq = query(nodo * 2, izq, mitad, i, j);
        int hijoDer = query((nodo * 2) + 1, mitad + 1, der, i, j);
        
        return max(hijoIzq, hijoDer);
    }
    
    int query_(int i, int j){
        query(1, 1, n - 1, i, j);
    }
};

int main(){
  return 0;
}
