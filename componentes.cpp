#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAXN = 20002;
const int MAXQ = 100002;

int n;

bool vis[MAXN];
stack<int> pila;
vector<int> aristas[MAXN];

vector<int> aristas_invertidas[MAXN];
int componentes[MAXN]; 

pair< pair<int,int> ,int > querys[MAXQ];

bool buscados[MAXN];
string respuestas[MAXQ];

void limpia_vis(){
	fill(vis, vis + n + 1, false);
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
	vis[nodo] = true;
	componentes[nodo] = color;
	for(int i = 0; i < aristas_invertidas[nodo].size(); i++)
		if(vis[aristas_invertidas[nodo][i]] == false)
			busca_componentes(aristas_invertidas[nodo][i], color);
}

void pinta(){
	int color = 1;
	while(!pila.empty()){
		int nodo = pila.top();
		pila.pop();

		if(vis[nodo] == false){
			vis[nodo] = true;
			busca_componentes(nodo, color);
			color++;
		}
	}
}

void FuncionField(int nodo){
	buscados[nodo] = true;
	for(int i = 0; i < aristas[nodo].size(); i++)
		if(buscados[aristas[nodo][i]] == false)
			FuncionField(aristas[nodo][i]);
}

void FlodField(int nodo){
	vis[nodo] = true;
	for(int i = 0; i < aristas[nodo].size(); i++){
		if(componentes[nodo] == componentes[aristas[nodo][i]])
			continue;
		FuncionField(aristas[nodo][i]);
	}
}

int main(){
	optimizar_io

	int m,q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		aristas[x].push_back(y);
		aristas_invertidas[y].push_back(x);
	}

	all_nodes();
	limpia_vis();
	pinta();

	for(int i = 0; i < q; i++){
		cin >> querys[i].first.first >> querys[i].first.second;
		querys[i].second = i;
	}

	sort(querys, querys + q);

	limpia_vis();

	for(int i = 0; i < q; i++){
		if(vis[querys[i].first.first] == false){
			FlodField(querys[i].first.first);
			for(int j = i; j < q; j++){
				if(querys[j].first.first != querys[i].first.first) break;
				if(buscados[querys[j].first.second])
					respuestas[querys[j].second] = "YES";
				else
					respuestas[querys[j].second] = "NO";
			}
			fill(buscados, buscados + n + 1, false);
		} 
	}

	for(int i = 0; i < q; i++)
		cout << respuestas[i] << "\n";	
	return 0;
}
