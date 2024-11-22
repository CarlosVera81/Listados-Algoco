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
            contador += linea.end() - it; // Pasos hacia atrás son los elementos desplazados
            linea.insert(it, entrada[i]); // Inserta en la posición correcta
        }

        cout << ndataset << " " << contador << endl;
    }

    return 0;
}
