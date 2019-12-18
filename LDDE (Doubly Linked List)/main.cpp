#include <chrono>
#include <iostream>
#include "LDDE.hpp"

using namespace std;

int main () {
    LDDE<int> l;

    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);

    cout << "Lista 1: " << l << endl;
    cout << "Numero 8 esta na posicao: " << l.busca(8) << endl;
    cout << "O numero que esta na posicao 2 eh: " << l[2] << endl;
    while (l.remove(0));

    cout << "" << endl;
    cout << "Lista: " << l << endl; // Lista vazia (não imprime nada)
    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);
    cout << "lista: " << l << endl;

    cout << "" << endl;

    LDDE<int> ld;
    ld = l;
    ld.insere(20);
    cout << "L: " << l << endl;
    cout << "Ld: " << ld << endl;
    return 0;
}

