#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    map<pair<int,int>,int> vis;
    
    for(int i = 1; i <= 10; i++)
        vis[make_pair(1,i)] = i;
    
    vis[make_pair(2,2)] = 3;
    for(int i = 3; i <= 10; i++)
        vis[make_pair(2,i)] = i + 2;
        
    for(int i = 3; i <= 10; i++)
        vis[make_pair(3,i)] = (3 * i) - i + 1;
    
    vis[make_pair(4,4)] = 11;
    vis[make_pair(4,5)] = 14;
    vis[make_pair(4,6)] = 16;
    vis[make_pair(4,7)] = 19;
    vis[make_pair(4,8)] = 21;
    vis[make_pair(4,9)] = 24;
    vis[make_pair(4,10)] = 26;
    
    n = min(n,m);
    m = max(n,m);
    
    if(n <= 4){
        cout << vis[make_pair(n,m)] << "\n";
        return 0;
    }
    
    int res = (n * 2) + (m * 2) - 4;
    
    n -= 4;
    m -= 4;
    
    if(n <= 4){
        res += vis[make_pair(n,m)];
        cout << res << "\n";
        return 0;
    } else {
        res += (n * 2) + (m * 2) - 4;
        n -= 4;
        m -= 4;
        res += vis[make_pair(n,m)];
        
        cout << res << "\n";
    }
    
    return 0;
}
