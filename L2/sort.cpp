#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int casos;
    int first = 0;
    while (cin >> casos) {
        if (casos == 0) break;
        if (first++) cout << endl;

        vector<string> nombres(casos);
        for (int i = 0; i < casos; ++i) {
            cin >> nombres[i];
        }
        stable_sort(nombres.begin(), nombres.end(), [](const string &a, const string &b) {
            return a.substr(0, 2) < b.substr(0, 2); // Compara solo las primeras dos letras
        }); // T=O(nlog(n)) ya que usa merge sort
            // E=O(n) arreglo aux sort()
            // E=O(n*l) almacenamiento de la entrada
        for (const auto &nombre : nombres) {
            cout << nombre << endl;
        }
    }

    return 0;
}
