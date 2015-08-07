#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
typedef vector<vector<int>> matrix;

int dir[8][2] ={ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

bool libre(int i, int j, int numero, const matrix& mapa){
	for(int k = 0; k < 4; k++){
		int sigx = i + dir[i][0];
		int sigy = j + dir[i][1];
		while(sigx >= 0 && sigy >= 0 && sigx < 9 && sigy < 9){
			if(mapa[sigx][sigy] == numero) return false;
			sigx += dir[i][0];
			sigy += dir[i][1];
		}
	}

	for(int k = 4; k < 8; k++)
		if(mapa[i + dir[i][0]][j + dir[i][1]] == numero) return false;
	return true;
}

void busqueda(int i, int j, matrix mapa){
	if(i == 9){
		for(int n = 0; n < 9; n++){
			for(int m = 0; m < 9; m++)
				cout << mapa[n][m] << " ";
			cout << "\n";
		}
		exit(0);
	}
}

int main(){
	matrix matriz;
	for(int i = 0; i < 9; i++) matriz[i].resize(10);

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int numero;
			cin >> numero;
			matriz[i][j] = numero;
		}
	}

	busqueda(0,0,matriz);
	return 0;
}
