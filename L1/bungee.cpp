#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    if (N < 3) {
        cout << 0 << endl;
    } else {
        vector<int> max_left(N, 0);
        vector<int> max_right(N, 0);
        // Calcular el máximo hacia la izquierda
        max_left[0] = H[0];
        cout << max_left[0] << " ";
        for (int i = 1; i < N; ++i) {
            max_left[i] = max(max_left[i - 1], H[i]);
            cout << max_left[i] << " ";
        }
        cout << endl;
        // Calcular el máximo hacia la derecha
        max_right[N - 1] = H[N - 1];
        cout << max_right[N-1] << " ";
        for (int i = N - 2; i >= 0; --i) {
            max_right[i] = max(max_right[i + 1], H[i]);
            cout << max_right[i] << " ";
        }
        cout << endl;
        int max_distance = 0;
        // Calcular la distancia máxima
        for (int i = 1; i < N - 1; ++i) {
            int min_height = min(max_left[i - 1], max_right[i + 1]);
            if (min_height > H[i]) {
                max_distance = max(max_distance, min_height - H[i]);
            }
        }
        cout << max_distance << endl;
    }

    return 0;
}
