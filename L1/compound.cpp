#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    set<string> palabras;

    string input;
    vector<string> lista;
    while(cin >> input){
        lista.push_back(input);
    }
    string resultado;
    for(int i=0;i<int(lista.size());i++){
        for(int j=0;j<int(lista.size());j++){
            if(lista[i]!=lista[j]){
                resultado= lista[i]+lista[j];
                if(palabras.find(resultado)==palabras.end()){
                    palabras.insert(resultado);
                }
            }

        }

    }


    for(auto it=palabras.begin();it!=palabras.end();it++){
        cout << *it << endl;
    }
    return 0;
}