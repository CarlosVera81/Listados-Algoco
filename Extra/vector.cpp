#include <iostream>
#include <vector>
#include <algorithm> // Para sort

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Acceso a un elemento
    std::cout << "Elemento en la posición 2: " << v[2] << "\n"; // O(1)

    // Modificación de un elemento
    v[2] = 10;
    std::cout << "Elemento modificado en la posición 2: " << v[2] << "\n"; // O(1)

    // Inserción al final
    v.push_back(6); // O(1) amortizado
    std::cout << "Elemento añadido al final: " << v.back() << "\n";

    // Eliminación al final
    v.pop_back(); // O(1)
    std::cout << "Elemento eliminado del final\n";

    // Inserción en el medio
    v.insert(v.begin() + 2, 99); // O(n)
    std::cout << "Elemento insertado en la posición 2: " << v[2] << "\n";

    // Eliminación en el medio
    v.erase(v.begin() + 2); // O(n)
    std::cout << "Elemento eliminado de la posición 2\n";

    // Redimensionar
    v.resize(10, 0); // O(n)
    std::cout << "Vector redimensionado a 10 elementos\n";

    // Búsqueda secuencial
    auto it = std::find(v.begin(), v.end(), 4); // O(n)
    if (it != v.end()) {
        std::cout << "Elemento encontrado: " << *it << "\n";
    }

    // Ordenar
    std::sort(v.begin(), v.end()); // O(n log n)
    std::cout << "Vector ordenado\n";
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
