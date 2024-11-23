#include <iostream>
#include <algorithm> // Para next_permutation
#include <vector>

int main() {
    // Definir los números (puedes cambiarlos por cualquier conjunto de 3 números)
    std::vector<int> numbers = {1, 2, 3};

    // Ordenar inicialmente el vector
    std::sort(numbers.begin(), numbers.end());

    // Generar todas las permutaciones
    do {
        // Imprimir la permutación actual
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    return 0;
}