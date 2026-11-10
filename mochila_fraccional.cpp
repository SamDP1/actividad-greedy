// Problema 1: Mochila fraccional
// Estrategia: tomar primero los objetos con mayor razon valor/peso.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// El objeto tiene nombre, valor y peso
struct Objeto {
    string nombre;
    double valor;
    double peso;
};

// Dice si el objeto a tiene mejor razon valor/peso que el objeto b
bool mejorRazon(Objeto a, Objeto b) {
    return a.valor / a.peso > b.valor / b.peso;
}

int main() {
    cout << setprecision(10);  // para que los numeros grandes no salgan en notacion cientifica

    double capacidad;
    int n;

    // 1. Leer los datos
    cout << "Capacidad maxima: ";
    cin >> capacidad;
    cout << "Cantidad de objetos: ";
    cin >> n;

    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {
        cout << "Objeto " << i + 1 << " (nombre valor peso): ";
        cin >> objetos[i].nombre >> objetos[i].valor >> objetos[i].peso;
        if (objetos[i].peso <= 0) {
            cout << "Error: el peso debe ser mayor que 0" << endl;
            return 1;
        }
    }

    // 2. Ordenar de mayor a menor razon valor/peso
    // (stable_sort mantiene el orden original si hay empate)
    stable_sort(objetos.begin(), objetos.end(), mejorRazon);

    // 3. Llenar la mochila
    double restante = capacidad;  // espacio que queda en la mochila
    double total = 0;             // valor total obtenido

    cout << "\nCapacidad maxima: " << capacidad << endl;
    cout << "Objetos seleccionados:" << endl;

    for (int i = 0; i < n && restante > 0; i++) {
        if (objetos[i].peso <= restante) {
            // Cabe completo: se toma entero
            cout << "  " << objetos[i].nombre << " completo" << endl;
            restante -= objetos[i].peso;
            total += objetos[i].valor;
        } else {
            // No cabe completo: se toma solo la fraccion que llena la mochila
            double fraccion = restante / objetos[i].peso;
            cout << "  " << restante << "/" << objetos[i].peso
                 << " Parte del objeto " << objetos[i].nombre << endl;
            total += objetos[i].valor * fraccion;
            restante = 0;
        }
    }

    // 4. Mostrar resultados
    cout << "Peso utilizado: " << capacidad - restante << " de " << capacidad << endl;
    cout << "Valor total obtenido: " << total << endl;

    return 0;
}
