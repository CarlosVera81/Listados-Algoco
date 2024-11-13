#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

int backpack(int capacidad,vector<int> pesos, vector<int> valor,int obj, vector<vector<int>>& matrix ){


}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int capacidad=0;
    int obj=0;
    

    while(cin>>capacidad>>obj){
        
        vector<vector<int>> matriz(obj,vector<int>(capacidad));
        vector <int> valor(obj);
        vector <int> pesos(obj);

        for(int i=0;i<obj;i++){
            cin >> valor[i] >> pesos[i];
        }

        for(int i=0;i<obj;i++){
            for(int j=0;j<capacidad;j++){
                matriz[i][j]=-1;
            }
        }
        

    }


    return 0;
}