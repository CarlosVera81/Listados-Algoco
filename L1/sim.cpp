#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int n;
    cin >> n;
    string input;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,input);
        list<char> copia;
        list<char>::iterator contador=copia.begin();
        for(int j=0; j<int(input.length()); j++){
            if(input[j]==']'){
                contador=copia.end();
        
            } else if(input[j]=='['){
                contador=copia.begin();
               
            } else if (input[j]=='<'){
                if(contador!=copia.begin()){
                    contador= copia.erase(--contador);
                }
            } else{
                contador=copia.insert(contador, input[j]);
                contador++;
            }
        }
        for(auto i:copia){
            cout << i;
        };
        cout<<endl;
    }
    return 0;
}