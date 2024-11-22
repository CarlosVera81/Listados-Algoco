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

    string linea1;
    string linea2;

    vector<string> matrix(2);

    cin >> linea1;
    cin >> linea2;

    matrix[0]=linea1;
    matrix[1]=linea2;
    
    int contador=0;

    for(int i=0;i<int(linea1.size());i++){

        if( matrix[0][i]=='0' and matrix[0][i+1]=='0' and matrix[1][i]=='0'){
            contador++;
            matrix[0][i]= matrix[0][i+1]= matrix[1][i]='B';
            
        }else if( matrix[0][i]=='0' and matrix[0][i+1]=='0' and matrix[1][i+1]=='0'){
            contador++;
            matrix[0][i]= matrix[0][i+1]= matrix[1][i+1]='B';
            
        }else if( matrix[1][i]=='0' and matrix[1][i+1]=='0' and matrix[0][i]=='0'){
            contador++;
            matrix[1][i]= matrix[1][i+1]= matrix[0][i]='B';
            
        }else if( matrix[1][i+1]=='0' and matrix[1][i]=='0' and matrix[0][i+1]=='0'){
            contador++;
            matrix[1][i+1]= matrix[1][i]= matrix[0][i+1]='B';
        }

    }

    cout << contador << endl;



    return 0;
}