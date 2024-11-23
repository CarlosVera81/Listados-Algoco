#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);


vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    istringstream stream(str);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token); 
    }
    return tokens;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    string input;
    
    getline(cin,input);

    vector<string> categorias;
    categorias=splitString(input,' ');
    int ncanciones;
    cin >> ncanciones;
    cin.ignore();
    //cout << ncanciones << endl;

    vector<string> canciones1(ncanciones);
    vector<vector<string>> canciones2(ncanciones);
    for(int i=0;i<ncanciones;i++){
        string cancion;
        getline(cin,cancion);
        //  cout << cancion << endl;
        canciones2[i]=splitString(cancion,' ');  
    }

    int filtro;
    cin >> filtro;
    cin.ignore();
    string filtros;
    
    for(int i=0;i<filtro;i++){
        cin >> filtros;
        
        int indice;
        for(int k=0;k<int(categorias.size());k++){
            if(categorias[k]==filtros){
                indice=k;
            }
        }

        stable_sort(canciones2.begin(),canciones2.end(),[indice](const vector<string>& a,const vector<string>& b){
            return a[indice] < b [indice];
        });

        for(int i=0;i<int(categorias.size());i++){
            cout << categorias[i] << " ";

        }
        cout << endl;
        for(int i=0;i<ncanciones;i++){
            for(int j=0;j<int(categorias.size());j++){
                cout << canciones2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    return 0;

    // O(f * nlogn)
    // O(n*x)
}

