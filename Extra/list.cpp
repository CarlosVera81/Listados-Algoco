#include <iostream>
#include <list>
#include <algorithm> // Para sort

int main() {
    std::list<int> l = {1, 2, 3, 4, 5};

    // Acceso mediante iteradores
    auto it = l.begin();
    std::advance(it, 2); // Avanzar iterador 2 posiciones
    std::cout << "Elemento en la posición 2: " << *it << "\n"; // O(n)

    // Modificación de un elemento
    *it = 10;
    std::cout << "Elemento modificado en la posición 2: " << *it << "\n"; // O(1)

    // Inserción al inicio
    l.push_front(0); // O(1)
    std::cout << "Elemento añadido al inicio: " << l.front() << "\n";

    // Inserción al final
    l.push_back(6); // O(1)
    std::cout << "Elemento añadido al final: " << l.back() << "\n";

    // Eliminación al inicio
    l.pop_front(); // O(1)
    std::cout << "Elemento eliminado del inicio\n";

    // Eliminación al final
    l.pop_back(); // O(1)
    std::cout << "Elemento eliminado del final\n";

    // Inserción en el medio
    it = l.begin();
    std::advance(it, 2);
    l.insert(it, 99); // O(1)
    std::cout << "Elemento insertado en la posición 2\n";

    // Eliminación en el medio
    it = l.begin();
    std::advance(it, 2);
    l.erase(it); // O(1)
    std::cout << "Elemento eliminado de la posición 2\n";

    // Redimensionar
    l.resize(10, 0); // O(n)
    std::cout << "Lista redimensionada a 10 elementos\n";

    // Búsqueda secuencial
    it = std::find(l.begin(), l.end(), 4); // O(n)
    if (it != l.end()) {
        std::cout << "Elemento encontrado: " << *it << "\n";
    }

    // Ordenar
    l.sort(); // O(n log n)
    std::cout << "Lista ordenada\n";
    for (int val : l) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
