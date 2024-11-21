#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    istringstream stream(str);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token); 
    }
    return tokens;
}

ll compute(vector<ll> lista, ll players){
    ll resultado=0;
    for(ll j=0;j<ll(lista.size());j++){
        resultado+=lista[j];
    }
    resultado=resultado%players;
    if(resultado<0){
        resultado+=players;
    }
    return resultado;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    string input1;
    string input2;
    cin >> input1;
    cin >> input2;
    cin.ignore();
    string entrada;
    vector<string> lista;
    vector<ll> listasalida;

    getline(cin, entrada);
    lista=splitString(entrada,' ');
    for(ll i=0;i<ll(lista.size());i++){
        if (lista[i]=="undo"){
            ll contador=0;
            while (contador< stoi(lista[i+1])){
                listasalida.pop_back();
                contador++;
            }
            i+=1;
        } else{
            listasalida.push_back(stoi(lista[i]));
        }
    }
    cout << compute(listasalida,stoi(input1)) << endl;
    return 0;
}