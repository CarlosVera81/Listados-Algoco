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

    int n,m;
    cin >> n >> m;

    vector<int> tamanios(n);
    vector<int> lista(n);
    for(int i=0;i<n;i++){
        cin >> tamanios[i];

    }

    for(int i=0;i<m;i++){
        cin >> lista[i];
    }

    sort(tamanios.begin(),tamanios.end());
    ll litros=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tamanios[j]>=lista[i]){
                litros+=tamanios[j]-lista[i];
                break;
            }
        }
    }
    cout << litros << endl;

    return 0;
    // O(nlog + m x n)
    // O(n+m)
}