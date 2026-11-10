// Problema 2: Cobertura de antenas (algoritmo Greedy)
/* Estrategia: tomar la primera casa sin cobertura y poner la antena
en (posicion de la casa + R), lo mas a la derecha posible. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R, n;

    // 1. Leer los datos
    cout << "Cobertura R: ";
    cin >> R;
    cout << "Cantidad de casas: ";
    cin >> n;

    vector<int> casas(n);

    cout << "Posiciones de las casas (separadas por espacio): ";
    for (int i = 0; i < n; i++) {
        cin >> casas[i];
    }

    // 2. Ordenar las casas de menor a mayor posicion
    sort(casas.begin(), casas.end());

    // 3. Colocar las antenas con la estrategia greedy
    vector<int> antenas;
    int i = 0;

    while (i < n) {

        // casas[i] es la primera casa sin cobertura
        int posicion = casas[i] + R;
        antenas.push_back(posicion);

        int alcance = posicion + R;

        // Saltar todas las casas que ya quedaron cubiertas
        while (i < n && casas[i] <= alcance) {
            i++;
        }
    }

    // 4. Mostrar resultados
    cout << "\nCasas: [";

    for (int j = 0; j < n; j++) {
        cout << casas[j];
        if (j < n - 1) cout << ",";
    }

    cout << "]" << endl;
    cout << "Cobertura: " << R << endl;

    cout << "Antenas colocadas en:" << endl;

    for (int j = 0; j < antenas.size(); j++) {
        int a = antenas[j];

        cout << "  " << a
             << "  (cubre [" << a - R
             << ", " << a + R << "])" << endl;
    }

    cout << "Cantidad total: " << antenas.size() << endl;

    // 5. Verificar que todas las casas quedaron cubiertas
    bool todasCubiertas = true;

    // Recorrer las casas
    for (int j = 0; j < casas.size(); j++) {
        int c = casas[j];
        bool cubierta = false;

        // Recorrer las antenas
        for (int k = 0; k < antenas.size(); k++) {
            int a = antenas[k];

            if (c >= a - R && c <= a + R) {
                cubierta = true;
            }
        }

        if (!cubierta) {
            todasCubiertas = false;
        }
    }

    if (todasCubiertas) {
        cout << "Verificacion: todas las casas estan cubiertas" << endl;
    } else {
        cout << "Verificacion: ERROR, hay casas sin cubrir" << endl;
    }

    return 0;
}

