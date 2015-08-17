#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
typedef vector<vector<int>> matrix;

int dir[8][2] ={ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

int convierte(int numero){
	if(numero == 0) return 1;
	if(numero == 1) return 4;
	if(numero == 2) return 7;
}

bool libre(int i, int j, int numero, const matrix& mapa){
	for(int k = 0; k < 4; k++){
		int sigx = i + dir[k][0];
		int sigy = j + dir[k][1];
		while(sigx >= 0 && sigy >= 0 && sigx < 9 && sigy < 9){
			if(mapa[sigx][sigy] == numero) return false;
			sigx += dir[k][0];
			sigy += dir[k][1];
		}
	}

	int nuevo_x, nuevo_y;

	int n = convierte(i / 3); 
	int m = convierte(j / 3);


	for(int k = 0; k < 8; k++){
		int sigx = n + dir[k][0];
		int sigy = m + dir[k][1];
		if(sigx < 0 || sigy < 0 || sigx >= 9 || sigy >= 9) continue;
		if(mapa[sigx][sigy] == numero) return false;
	}
	return true;
}

void busqueda(int i, int j, matrix mapa){
	int temp_i = i, temp_j = j;
	
	if(j + 1 < 9){
		temp_j = j + 1;
	} else {
		temp_i = i + 1;
		temp_j = 0;
	}

	if(i == 9){
		for(int n = 0; n < 9; n++){
			for(int m = 0; m < 9; m++)
				cout << mapa[n][m] << " ";
			cout << "\n";
		}
		exit(0);
	}

	if(mapa[i][j] > 0){
		busqueda(temp_i,temp_j, mapa);
		return;
	}

	for(int k = 1; k <= 9; k++){
		if(libre(i,j,k,mapa)){
			mapa[i][j] = k;
			busqueda(temp_i, temp_j, mapa);
		}
	}
}

int main(){
	matrix matriz;
	matriz.resize(10);
	for(int i = 0; i < 9; i++) 
		matriz[i].resize(10);

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
 
