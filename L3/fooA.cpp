#include <bits/stdc++.h>
using namespace std;

// Límite de precomputación
const int LIMITE = 100;
vector<int> primos;
vector<bool> es_primo(LIMITE + 1, true);
set<int> posiciones_perdedoras;

// Función para calcular números primos usando la criba de Eratóstenes
void calcular_primos() {
    es_primo[0] = es_primo[1] = false; // 0 y 1 no son primos
    for (int i = 2; i <= LIMITE; ++i) {
        if (es_primo[i]) {
            primos.push_back(i); // Agregar el primo a la lista
            for (int j = 2 * i; j <= LIMITE; j += i) {
                es_primo[j] = false;
            }
        }
    }
}

// Función para calcular las posiciones perdedoras
void calcular_posiciones_perdedoras() {
    vector<bool> dp(LIMITE + 1, false); // dp[i] es true si la posición i es ganadora
    for (int i = 2; i <= LIMITE; ++i) {
        bool es_perdedor = true;
        for (int p : primos) {
            if (p - 1 > i) break; // No se puede quitar más piedras que las disponibles
            if (!dp[i - (p - 1)]) { // Hay al menos un movimiento que deja al oponente en posición perdedora
                es_perdedor = false;
                break;
            }
        }
        dp[i] = !es_perdedor;
        if (es_perdedor) {
            posiciones_perdedoras.insert(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // Precomputar primos y posiciones perdedoras
    calcular_primos();
    calcular_posiciones_perdedoras();

    // Imprimir las posiciones perdedoras
    cout << "precomp = {";
    bool primero = true;
    for (int p : posiciones_perdedoras) {
        if (!primero) cout << ", ";
        cout << p;
        primero = false;
    }
    cout << "};" << endl;

    return 0;
}
