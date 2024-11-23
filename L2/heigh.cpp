#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int ncasos;
    cin >> ncasos;

    while (ncasos--) {
        int ndataset;
        cin >> ndataset;

        vector<int> entrada(20);
        for (int i = 0; i < 20; i++) {
            cin >> entrada[i];
        }

        int contador = 0;
        vector<int> linea;

        for (int i = 0; i < 20; i++) {
            auto it = lower_bound(linea.begin(), linea.end(), entrada[i]);
            // lower or upper O(logn) espacio O(1)
            // Finding the lower bound of value 30 in the
             // first three elements of the vector v
            // *lower_bound(v.begin(), v.begin() + 3, 30)
            contador += linea.end() - it; // Pasos hacia atrás son los elementos desplazados
            linea.insert(it, entrada[i]); // Inserta en la posición correcta
            // O (n)
        }

        cout << ndataset << " " << contador << endl;
    }

    return 0;

    //Complejidad Temporal O(ncasos)
    // Complejidad espacial O (1)
}
