#include <bits/stdc++.h>
typedef long long lli;
using namespace std;

pair<lli,lli> simplifica(lli numerador, lli denominador){
     long long MCD = __gcd(numerador,denominador);
     return make_pair(numerador / MCD, denominador / MCD);
}

pair<lli, lli> suma_fraccion(lli x1, lli y1, lli x2, lli y2){
    long long denominador = y1 * y2;
    long long numerador = (y1 * x2) + (y2 * x1);
    pair<lli,lli> simp = simplifica(numerador,denominador);
    return simp;
}

int main(){
    for(int i = 1; true; i++){
        long long v1, v2;
        long long d1, d2;
        cin >> v1 >> d1 >> v2 >> d2;
        if(v1 == 0 && v2 == 0 &&
            d1 == 0 && d2 == 0)
                return 0;
                
        double capitan = double(d1) / double(v1);
        double copiloto = double(d2) / double(v2);
        
        cout << "Case #" << i << ": "; 
        if(capitan < copiloto)
            cout << "You owe me a beer!\n";
        else
            cout << "No beer for the captain.\n";
        cout << "Avg. arrival time: ";
        
        pair<lli,lli> suma = suma_fraccion(d1,v1,d2,v2);
        pair<lli,lli> fraccion_resultante = simplifica(suma.first, 
                                                        suma.second * 2);
        
        if(fraccion_resultante.second == 1)
            cout << fraccion_resultante.first << "\n";
        else 
            cout << fraccion_resultante.first << "/" << fraccion_resultante.second << "\n";
    }
    return 0;
}
