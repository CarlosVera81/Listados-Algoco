#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(9);

    int n, y;
    cin >> n >> y;
    vector<int> lista(y);
    
    for( int i=0; i<y ; i++){
        cin >> lista[i];
    }
    sort(lista.begin(),lista.end());
    queue<int> cola;

    for(int i=0;i<y;i++){
        if(cola.empty() || lista[i]!=cola.back()){
            cola.push(lista[i]);
            
        }
    }
    ll contador=0;
    for(int i=0;i<n;i++){
        if(i!=cola.front() || cola.empty()){
            cout << i << endl;
            
        } else {
            contador++;
            cola.pop();
        }
    }
    cout << "Mario got " << contador << " of the dangerous obstacles."<< endl;
    return 0;
    // Complejidad temporal: O( y log(y) + n)
    // Complejidad espacial: O(y)

}