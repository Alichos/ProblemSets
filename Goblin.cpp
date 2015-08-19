#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 502;
 
int vis[MAXN][MAXN];
char mapa[MAXN][MAXN];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
 
int main(){
	int casos;
	cin >> casos;
	for(int ind = 0; ind < casos; ind++){
		int n,m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> mapa[i];
 
		queue< pair< pair<char, int> , pair<int,int> > > cola;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				vis[i][j] = -1;
				if(mapa[i][j] >= 'a' && mapa[i][j] <= 'z'){
					vis[i][j] = 0;
					cola.push(make_pair(make_pair(mapa[i][j],0) , make_pair(i,j)));
				}
			}
		}
		
		while(!cola.empty()){
			int tiempo = cola.front().first.second;
			char ciudad = cola.front().first.first;
			int x = cola.front().second.first;
			int y = cola.front().second.second;
			cola.pop();
 
			if(mapa[x][y] == '*') continue;
 
			for(int i = 0; i < 4; i++){
				int sx = x + dir[i][0];	
				int sy = y + dir[i][1];
 
				if(sx < 0 || sy < 0 || sx == n || sy == m) continue;
				if(mapa[sx][sy] == '#' || mapa[sx][sy] == '*') continue;
 
				if(vis[sx][sy] == -1){ 
					vis[sx][sy] = tiempo + 1;
					mapa[sx][sy] = ciudad;
					cola.push(make_pair(make_pair(ciudad,tiempo + 1), make_pair(sx,sy)));
				} else {
					if(mapa[sx][sy] != ciudad && tiempo < vis[sx][sy]){
						vis[sx][sy] = tiempo + 1;
					 	mapa[sx][sy] = '*';
					}
				}
			}
		}
 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << mapa[i][j];
				vis[i][j] =  0;
			}
			cout << "\n";
		}
		cout<<"\n";
	}
	return 0;
} 
