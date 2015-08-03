#include <bits/stdc++.h>
#define op_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct nodo{
    map<char,int> enlace;
    int palabra;
};

struct tries{
    vector<nodo> trais;
    int disponible = 1;

    void crea(int tam){
        trais.resize(tam);
    }

    void add(string cadena, int numero){
        int nodo = 0;
        int tam = cadena.size();
        for(int i = 0; i < tam; i++){
            if(trais[nodo].enlace.find(cadena[i]) == trais[nodo].enlace.end()){
                trais[nodo].enlace[cadena[i]] = disponible;
                nodo = disponible;
                disponible++;
            } else{
                nodo = trais[nodo].enlace[cadena[i]];
            }
        }
        trais[nodo].palabra = numero;
    }

    void inorden(int nod){
        if(trais[nod].palabra > 0) cout << "P\n";
        for(auto i = trais[nod].enlace.begin(); i != trais[nod].enlace.end(); i++){
            cout << i -> first << "\n";
            inorden(i -> second);
            cout << "-\n";
        }
    }
};

int main(){
    op_
    int n;
    cin >> n;

    tries tree;
    tree.crea(500000);
    int mayor = -1;
    string cadena_mayor;
    for(int i = 1; i <= n; i++){
        string actual;
        cin >> actual;
        int tam = actual.size();
        if(mayor < tam){
            mayor = tam;
            cadena_mayor = actual;
        }
        tree.add(actual,i);
    }

    int nodo_actual = 0;
    int tam = cadena_mayor.size();

    cout << ((tree.disponible - 1) * 2) + n - tam << "\n";

    for(int i = 0; i < tam; i++){
        int nodo_temporal;
        if(tree.trais[nodo_actual].palabra > 0) cout << "P\n";
        for(auto j = tree.trais[nodo_actual].enlace.begin(); j != tree.trais[nodo_actual].enlace.end(); j++){
            if(j -> first != cadena_mayor[i]){
                cout << j -> first << "\n";
                tree.inorden(j -> second);
                cout << "-\n";
            } else {
                nodo_temporal = j -> second;
            }
        }
        nodo_actual = nodo_temporal;
        cout << cadena_mayor[i] << "\n";
    }
    cout << "P\n";
    return 0;
}
