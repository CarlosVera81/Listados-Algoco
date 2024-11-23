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

    int capacidad=0;
    int obj=0;
    

    while(cin>>capacidad>>obj){
        vector<vector<int>> matriz(obj+1, vector<int>(capacidad+1));
        vector <int> valor(obj);
        vector <int> pesos(obj);
        for(int i=0;i<obj;i++){
            cin >> valor[i] >> pesos[i];
        }
        if(obj==1 && pesos[obj-1]<capacidad){
            cout << 1 << endl;
            cout << obj-1 <<endl;
        } else{
            for(int i=1;i<=obj;i++){
                for(int j=1;j<=capacidad;j++){

                    if(pesos[i-1]<=j){
                        int opt=max(matriz[i-1][j],matriz[i-1][j-pesos[i-1]]+valor[i-1]);
                        matriz[i][j]=opt;
                    
                    } else {
                        matriz[i][j]=matriz[i-1][j];
                    }
                }
            }
        }

        list<int> salida;
        auto w=capacidad;
        for(int i=obj;i>0;i--){
            //cout<< matriz[i][w] << endl;
            if(matriz[i][w]==matriz[i-1][w-pesos[i-1]]+valor[i-1]){
                salida.push_back(i-1);
                w-=pesos[i-1];
            }
        }
        
        cout << salida.size()<<endl;

        for(int i:salida){
            cout<< i << " ";
        }

        cout << endl;

      //  cout << matriz[obj][capacidad]<<endl;
    }
     return 0;
     // O(obj x capacidad)
     // O(obj x capacidad)
}

