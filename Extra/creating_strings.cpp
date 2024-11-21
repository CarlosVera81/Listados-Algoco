#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

set <string> salida;

void recursion(string actual,string restantes,int n){
    if(restantes.length()==0){
        salida.insert(actual);
        return;
    }


    for(int i=0;i<int(size(restantes));i++){
        recursion(actual+restantes[i],restantes.substr(0,i)+restantes.substr(i+1),n); 
    }
   
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    string input;
    cin >> input;
    list <string> lista;

    int n=size(input);
    string vacio="";
    recursion(vacio,input,n);
    
    cout << salida.size() << endl;
    for(auto o :salida){

        cout << o << endl;
    }


    return 0;
}