#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> stalagmites, stalactites;
    for (int i = 0; i < N; i++) {
        int size;
        cin >> size;
        if (i % 2 == 0) {
            stalagmites.push_back(size);
        } else {
            stalactites.push_back(size);
        }
    }

    // Ordenar las alturas de los obstáculos
    sort(stalagmites.begin(), stalagmites.end());
    sort(stalactites.begin(), stalactites.end());

    vector<int> obstacles(H + 1, 0);
    int min_obstacles = N, count_levels = 0;

    // Calcular el número de impactos por nivel
    for (int i = 1; i <= H; i++) {
        int from_floor = stalagmites.end() - lower_bound(stalagmites.begin(), stalagmites.end(), i);
        int from_ceiling = stalactites.end() - lower_bound(stalactites.begin(), stalactites.end(), H - i + 1);
        obstacles[i] = from_floor + from_ceiling;

        if (obstacles[i] < min_obstacles) {
            min_obstacles = obstacles[i];
            count_levels = 1;
        } else if (obstacles[i] == min_obstacles) {
            count_levels++;
        }
    }
    cout << min_obstacles << " " << count_levels << endl;
    return 0;

    //O(Nlog N + H Log N)
    // O (N+H)
}
