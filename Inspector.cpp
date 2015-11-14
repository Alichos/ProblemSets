#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;

struct SegmentTree{
    int tree[MAXN];
    void update(int nodo, int a, int b, int i, int j, int valor){
        if(lazy[node] != 0) { // This node needs to be updated
       		tree[node] += lazy[node]; // Update it
    
    		if(a != b) {
    			lazy[node*2] += lazy[node]; // Mark child as lazy
        			lazy[node*2+1] += lazy[node]; // Mark child as lazy
    		}
    
       		lazy[node] = 0; // Reset it
      	}
      
    	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    		return;
        
      	if(a >= i && b <= j) { // Segment is fully within range
        		tree[node] += value;
    
    		if(a != b) { // Not leaf node
    			lazy[node*2] += value;
    			lazy[node*2+1] += value;
    		}
    
        		return;
    	}
    
        update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
        update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
        
        tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
    }
};

int main(){
  return 0;
}
