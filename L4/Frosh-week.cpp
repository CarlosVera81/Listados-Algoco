#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

//const ll mod = 1e9 + 7;
//const ll inf = 1e12;
const ld pi = acos(-1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int n, m;
    int r=0;
    // Leer los valores de n y m desde la primera línea
    std::cin >> n >> m;
    // Crear vectores para almacenar los valores de las dos listas
    std::vector<int> lista1(n);
    std::vector<int> lista2(m);
    priority_queue<int,vector<int>,greater<int>> minheap1;
    priority_queue<int,vector<int>,greater<int>> minheap2;
    // Leer los n valores de la segunda línea
    for (int i = 0; i < n; ++i) {
        std::cin >> lista1[i];
        minheap1.push(lista1[i]);
    }
    // Leer los m valores de la tercera línea
    for (int i = 0; i < m; ++i) {
        std::cin >> lista2[i];
        minheap2.push(lista2[i]);
    }
    while(true){
    if (minheap1.empty() || minheap2.empty()){ // O(1)
        break;
    } else {
        if (minheap1.top()<=minheap2.top()){ // O(1)
        r++;
        minheap1.pop(); // O(log(n))
        minheap2.pop(); // O(log(m))
        }
        else {
            minheap2.pop(); // O(log(m))
        }
    }
    }
    cout << r << endl;
    return 0;
    // O(nlogn + m log m)
    // O(m+n)
}