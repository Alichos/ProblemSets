#include <bits/stdc++.h>
using namespace std;

const int MAXN = 9;
const int INF = (1 << 30);

int ope = 0;
int n,m,k;
int mayor = INF;
char mapa[MAXN * MAXN];
int dir[4] = { 1 , -1 };

char convierte(int numero){
     if(numero == 0) return 'A';
     if(numero == 1) return 'B';
     if(numero == 2) return 'C';
     if(numero == 3) return 'D';
     if(numero == 4) return 'E';
     if(numero == -1) return '#';
     return 'S';
}

int CoordALineal(int x, int y){
    return (x * m) + y;
}

int cuenta_torres(const string& lineal){
    int res = 0;
    for(int i = 0; i < (n * m); i++)
        if(lineal[i] == 'T') res++;
    return res;
}

int adyacentes(const string& lineal, const int& posicion){
    int res = 0;
    for(int j = 0; j < 4; j++){
        int sig_pos = posicion + dir[j];
        if(posicion % m == 0 && dir[j] == -1) continue;
        if(posicion % m == m - 1 && dir[j] == 1) continue;
        
        if(lineal[sig_pos] == 'T')
            res++;
    }
    return res;
}

int completo(string lineal,int posicion){
    int ocupadas = k;
    for(int i = 0; i < n * m; i++){
        if(lineal[i] == '#' || 
           lineal[i] == '.' || 
           lineal[i] == 'S') 
            continue;

        if(lineal[i] == 'T'){
            ocupadas++;
            for(int j = 0; j < 4; j++){
                int sig_pos = i + dir[j];
                while(sig_pos >= 0 && sig_pos < n * m){
                    if(dir[j] == 1 && sig_pos % m == m - 1) break;
                    if(dir[j] == -1 && sig_pos % m == 0) break;

                    if(lineal[sig_pos] == 'T') return -1;

                    if(lineal[sig_pos] == 'S'){
                        sig_pos += dir[j];
                        continue;
                    }

                    if(lineal[sig_pos] != '.') break;

                    lineal[sig_pos] = 'S';
                    sig_pos += dir[j];
                    ocupadas++;
                }
            }
        }

        if(lineal[i] - 'A' >= 0 && lineal[i] - 'A' <= 4){
            int adyacen = adyacentes(lineal, i);
            if(adyacen > lineal[i] - 'A') return -1;
            if(adyacen < lineal[i] - 'A') return 0;
        }
    }
    if(ocupadas == n * m) return 1;
    return 0;
}

void busqueda(string lineal, int x){
    if(x >= n * m) return;

    int query = completo(lineal,x);
    if(query == -1) return;
    
    if(query == 1){
        mayor = min(mayor, cuenta_torres(lineal));
        return;
    }

    bool flag = false;
    if(x - m >= 0 && lineal[x - m] >= 'A' && lineal[x - m] <= 'E'){
        int adyacen = adyacentes(lineal, x - m);

        if(adyacen == lineal[x - m] - 'A')
            busqueda(lineal, x + 1);

        if(lineal[x] == '.' && adyacen + 1 == lineal[x - m] - 'A'){
            lineal[x] = 'T';
            busqueda(lineal, x + 1);
        }
        flag = true;
    }

    if(flag) return;

    busqueda(lineal, x + 1);

    if(lineal[x] == '.'){
        lineal[x] = 'T';
        busqueda(lineal, x + 1);
    }
}

int main(){
    cin >> n >> m >> k;

    dir[2] = m;
    dir[3] = -m;

    for(int i = 0; i < n * m; i++)
        mapa[i] = '.';

    for(int i = 0; i < k; i++){
        int x,y,torres_requeridas;
        cin >> x >> y >> torres_requeridas;
        char query = convierte(torres_requeridas);
        int linea = CoordALineal(x - 1, y - 1);
        mapa[linea] = query;
    }

    string raiz(mapa);
    busqueda(raiz,0);

    cout << mayor << "\n";
    return 0;
}
