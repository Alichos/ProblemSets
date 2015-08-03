#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
const int MAXP = 7;

struct check{
    int x, y;
} puntos[MAXP];

struct estado{
    int x, y, ti;
    
    estado()
        : x(0), y(0), ti(0) {}
    estado(int sx, int sy, int sti)
        : x(sx), y(sy), ti(sti) {}
};

int t[MAXP];
queue<estado> cola;
int matriz[MAXN][MAXN];
int visitados[MAXN][MAXN];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };


int n,m;
int limit;
int top = 0;
int resultado = 0;

int man( int x , int y , int a , int b){
    return abs(x - a) + abs(y - b);
}

void amplitud(int x, int y, int tiempo){
    for(int i = 0; i < 4; i++){
        int sig_x = x + dir[i][0];
        int sig_y = y + dir[i][1];
        if( sig_x >= 0 || sig_y >= 0 ){
            if(matriz[sig_x][sig_y] == 0 && visitados[sig_x][sig_y] == -1){
                estado query(sig_x, sig_y, tiempo + 1);
                visitados[sig_x][sig_y] = tiempo + 1;
                cola.push(query);
            }
        }    
    }
}

void busqueda(int x, int y ,int tiempo , int checkpoint){

    //CHECA SI ES EL FIN
    if(tiempo == limit && x == 0 && y == 1){
        resultado++;
        return;
    }
    
    //VISITADO
    if(matriz[x][y] == 1) return;

    //CHECA SI LLEGUE A UN ESCONDITE O NO EN TIEMPO

    if(tiempo == t[checkpoint]){
        if(x == puntos[checkpoint].x && y == puntos[checkpoint].y)
            checkpoint++;
        else return;
    }

    //CHECA SI ESTOY EN UN ESCONDITE QUE NO
    for(int temp = checkpoint; temp < 4; temp++)
        if(puntos[temp].x == x && puntos[temp].y == y)
            return;

    //QUICK MANHATAN
    for(int i = checkpoint; i < 4; i++)
        if(tiempo < t[i] && man(x, y, puntos[i].x , puntos[i].y ) > (t[i] - tiempo) )
            return;
    

    //RELLENAR
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visitados[i][j] = -1;

    //BUSQUEDA DE AMPLITUD

    push(x, y, tiempo);
    visitados[x][y] = tiempo;
    for(int z = 0; z < top; z++)
        amplitud(cola[z].x,cola[z].y,cola[z].ti);

    top = 0;

    //SI ES POSIBLE LLEGAR
    if(visitados[puntos[checkpoint].x][puntos[checkpoint].y] > t[checkpoint]) return;

    //PUNTOS CIEGOS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visitados[i][j] == -1 && matriz[i][j] == 0){
                return;
            }
        }
    }

    matriz[x][y] = 1;

    int u = 0, cx = 0, cy = 0;
    if(x - 1 >= 0 && (x - 1 != 0 || y != 1) && matriz[x - 1][y] == 0){

        int r  = x - 1 , c = y;
        int vecinos = 0;

        if(r - 1 >= 0 && matriz[r - 1][c] == 0) ++vecinos;
        if(r + 1 < n && matriz[r + 1][c] == 0) ++vecinos;
        if(c - 1 >= 0 && matriz[r][c - 1] == 0) ++vecinos;
        if(c + 1 < m && matriz[r][c + 1] == 0) ++vecinos;

        if( vecinos == 0){
            matriz[x][y] = 0;
            return;
        }

        if( vecinos == 1){
            u++;
            cx = -1;
            cy = 0;
        }
    }
    
    if(x + 1 < n && (x + 1 != 0 || y != 1) && matriz[x + 1][y] == 0){


        int r  = x + 1 , c = y;
        int vecinos = 0;

        if(r - 1 >= 0 && matriz[r - 1][c] == 0) ++vecinos;
        if(r + 1 < n && matriz[r + 1][c] == 0) ++vecinos;
        if(c - 1 >= 0 && matriz[r][c - 1] == 0) ++vecinos;
        if(c + 1 < m && matriz[r][c + 1] == 0) ++vecinos;

         if( vecinos == 0){
            matriz[x][y] = 0;
            return;
        }

        if( vecinos == 1){
            u++;
            cx = 1;
            cy = 0;
        }
    }
    
    if(y - 1 >= 0 && (x != 0 || y - 1 != 1) && matriz[x][y - 1] == 0){

        int r  = x , c = y - 1;
        int vecinos = 0;

        if(r - 1 >= 0 && matriz[r - 1][c] == 0) ++vecinos;
        if(r + 1 < n && matriz[r + 1][c] == 0) ++vecinos;
        if(c - 1 >= 0 && matriz[r][c - 1] == 0) ++vecinos;
        if(c + 1 < m && matriz[r][c + 1] == 0) ++vecinos;

        if( vecinos == 0){
            matriz[x][y] = 0;
            return;
        }

        if( vecinos == 1){
            u++;
            cx = 0;
            cy = -1;
        }
    }
    if(y + 1 < m && (x != 0 || y + 1 != 1) && matriz[x][y + 1] == 0){

        int r  = x , c = y + 1;
        int vecinos = 0;

        if(r - 1 >= 0 && matriz[r - 1][c] == 0) ++vecinos;
        if(r + 1 < n && matriz[r + 1][c] == 0) ++vecinos;
        if(c - 1 >= 0 && matriz[r][c - 1] == 0) ++vecinos;
        if(c + 1 < m && matriz[r][c + 1] == 0) ++vecinos;

        if( vecinos == 0){
            matriz[x][y] = 0;
            return;
        }

        if( vecinos == 1){
            u++;
            cx = 0;
            cy = 1;
        }
    }
    
    if(u > 1){
        matriz[x][y] = 0;
        return;
    }
    if(u == 1) {
        busqueda (x + cx , y + cy , tiempo + 1, checkpoint);
        matriz[x][y] = 0;
        return;
    }

    if(y - 1 >= 0){
        busqueda(x , y - 1 , tiempo + 1 , checkpoint);
    }
    if(y + 1 < m){
        busqueda(x, y + 1 , tiempo + 1, checkpoint);
    }
    if(x - 1 >= 0){
        busqueda(x - 1, y, tiempo + 1, checkpoint);
    }
    if(x + 1 < n){
        busqueda(x + 1, y , tiempo + 1, checkpoint);
    }

    matriz[x][y] = 0;
}

int main(){
    cin >> n >> m;
    limit = n * m;

    for(int i = 0; i < 3; i++){
        cin >> puntos[i].x >> puntos[i].y;
    }

    puntos[3].x = 0;
    puntos[3].y = 1;

    int multi = 1;
    for(int i = 0; i < 4; i++){
        t[i] = (multi * limit) / 4;
        multi++;
    }

    busqueda(0,0,1,0);

    cout << resultado << "\n";

    return 0;
}
