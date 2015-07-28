#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7;
const int MAXC = MAXN * MAXN;
const int INF = (1 << 30);

string mapa[MAXN];
map<string, int> vis;
char mapa_lineal[MAXC];

int n;
int dir[4] = { -1 , 1 , 5, -5 };

int DFS(string& lineal, int posicion){
	int res = 1;
	lineal[posicion] = '.';
	for(int i = 0; i < 4; i++){
		if(0 <= posicion + dir[i] && 
		   posicion + dir[i] < 25 &&
		   lineal[posicion + dir[i]] == '*')
			res += DFS(lineal, posicion + dir[i]);
	}
	return res;
}

bool checa(string lineal){
	for(int i = 0; i < 25; i++){
		if(lineal[i] == '*'){
			if(DFS(lineal, i) == n)
				return true;	
			return false;
		}
	}
}

int main(){

	for(int i = 0; i < 5; i++)
		 cin >> mapa[i];

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(mapa[i][j] == '*'){
				mapa_lineal[(i * 5) + j] = '*';
				n++;
			} else {
				mapa_lineal[(i * 5) + j] = '.';
			}
		}
	}

	string query(mapa_lineal);
	
	int minimo = INF;
	queue<string> cola;
	cola.push(query);
	vis[query] = 0;

	while(!cola.empty()) {
		string clave = cola.front();
		cola.pop();

		if(checa(clave)){
			minimo = min(minimo,vis[clave]);
			continue;
		}

		for(int i = 0; i < 25; i++){
			if(clave[i] == '*'){
				for(int j = 0; j < 4; j++){
					string nuevo = clave;

					int sig_pos = i + dir[j];
					if(sig_pos < 0 || sig_pos >= 25 || nuevo[sig_pos] == '*') continue;

					nuevo[i] = '.';
					nuevo[sig_pos] = '*';

					if(vis.find(nuevo) == vis.end()){
						vis[nuevo] = vis[clave] + 1;
						cola.push(nuevo);
					}
				}
			}
		}
	}
	cout << minimo << "\n";
	return 0;
}
