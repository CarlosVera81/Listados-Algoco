#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;
using ld = long double;

//const ll mod = 1e9 + 7;
//const ll inf = 1e12;
const ld pi = acos(-1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);
    
    int n, r;
    r=0;
    cin >> n;

    vector<int> lista1(n);

    for (int i = 0; i < n; ++i) {
        cin >> lista1[i];
    }

    

    sort(lista1.begin(), lista1.end());


    while(lista1.size()>=3){
        vector <int> aux(3);
        for (int i=0;i<3;i++){
            aux[i]=lista1.back();
            lista1.pop_back();
        }
        r+=aux[2];

    }
    
    cout<<r<<endl;

    return 0;
}