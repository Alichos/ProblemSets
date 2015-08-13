#include <bits/stdc++.h>
using namespace std;

const int MAXN = 130002;
const int MAXC = 1000002;

int cubeta[MAXC];
int numeros[MAXN];

int main(){
	int n;
	cin >> n;	
	for(int i = 0; i < n; i++)
		cin >> numeros[i];

	for(int i = 0; i < n; i++)
		cubeta[numeros[i]]++;

	for(long long int i = MAXC - 2; i >= 1; i--){
		queue<int> cola;
		for(long long int j = i; j <= MAXC - 2; j += i){
			if(cubeta[j] >= 2){
				cola.push(j);
				cola.push(j);
			}
			if(cubeta[j] >= 1)
				cola.push(j);
		}
		if(cola.size() <= 1) continue;
		
		long long int x = cola.front();
		cola.pop();
		
		long long int y = cola.front();
		cola.pop();
		
		long long int MCM = (x / i) * y;
		cout << MCM << "\n";
		return 0;
	}
	return 0;
}
