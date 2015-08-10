#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20002;

int n;

bool vis[MAXN];
stack<int> pila;
vector<int> aristas[MAXN];

vector<int> aristas_invertidas[MAXN];
int componentes[MAXN];

void limpia_vis(){
	fill(vis, vis + n, false);
}

void DFS(int nodo){
	vis[nodo] = true;
	for(int i = 0; i < aristas[nodo].size(); i++)
		if(vis[aristas[nodo][i]] == false) 
			DFS(aristas[nodo][i]);
	pila.push(nodo);
}

void all_nodes(){
	for(int i = 1; i <= n; i++)
		if(vis[i] == false)
			DFS(i);
}

void busca_componentes(int nodo, int color){
	for(int i = 0; i < aristas_invertidas[nodo].size(); i++){
		if(vis[aristas_invertidas[nodo][i]] == false){ 
			componentes[aristas_invertidas[nodo][i]] = color;
			vis[aristas_invertidas[nodo][i]] = true;
			DFS(aristas_invertidas[nodo][i]);
		}
	}
}

void pinta(){
	int color = 1;
	while(!pila.empty()){
		if(vis[pila.top()] == false){
			vis[pila.top()] = true;
			busca_componentes(pila.top(), color);
			color++;
		}
		pila.pop();
	}
}

int main(){
	int m,querys;
	cin >> n >> m >> querys;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		aristas[x].push_back(y);
		aristas_invertidas[y].push_back(x);
	}

	all_nodes();
	limpia_vis();
	pinta();

	for(int i = 1; i <= n; i++)
		cout << componentes[i] << " ";
	return 0;
}
