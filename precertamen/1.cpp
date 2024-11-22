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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
      //  cout << "hola" << endl;
        vector<string> cadenas(n);
        for(int i=0;i<n;i++){
            cin >> cadenas[i];
            sort(cadenas[i].begin(),cadenas[i].end());
        }
     //   cout << "hola" << endl;
        string flag="YES";
        for(int i=0;i<n;i++){
            string comparador;
            for(int j=0;j<n;j++){
                comparador+=cadenas[j][i];
                
            }
            string copia=comparador;
            sort(copia.begin(),copia.end());

            if(copia.compare(comparador)!=0){
                flag="NO";
            }
        }
        cout << flag << endl;


    }


    return 0;
}