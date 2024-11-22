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


    int n;
    while(cin>>n){
        if (n==0){
            break;
        }
        vector<int> lista1(n);
        vector<int> lista1copia(n);
        vector<int> lista2(n);
        for(int i=0;i<n;i++){
            cin >> lista1[i];
        }

        for(int i=0;i<n;i++){
            cin >> lista2[i];
        }

        lista1copia=lista1;

        sort(lista1.begin(),lista1.end());
        sort(lista2.begin(),lista2.end());
        
        map<int,int> dic;

        for(int i=0;i<n;i++){
            dic[lista1[i]]=lista2[i];
        }

        for(int i=0;i<n;i++){
            cout << dic[lista1copia[i]] << endl;
        }

        cout << endl;

    }

    return 0;
}