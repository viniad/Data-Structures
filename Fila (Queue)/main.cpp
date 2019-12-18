#include <iostream>
#include "Fila.hpp"

using namespace std;

int main (int argc, char* argv[]) {
    FilaCircular<float> f (3);
    f.enfileira (5.2);
    f.enfileira (2.2);
    f.enfileira (3.2);
    f.enfileira (9.2);
    f.enfileira (5.1);

    bool ok = false;
    do {
        float r = f.desenfileira (&ok);
        if (ok)
            cout << r << endl;
    } while (ok); // Deve Imprimir somente 5.2, 2.2 e 3.2

    f.enfileira (3);
    f.enfileira (2);
    f.enfileira (1);


    FilaCircular<float> f2 (10);
    f2 = f;


    cout << f.desenfileira ()  << endl; // Deve Imprimir 3
    cout << f2.desenfileira () << endl; // Deve Imprimir 3
    cout << f2.desenfileira () << endl; // Deve Imprimir 2
    cout << f.desenfileira ()  << endl; // Deve Imprimir 2


    f2 << 10 << 9 << 8 << 7 << 6;
    /*f2.enfileira(10);
    f2.enfileira(9);
    f2.enfileira(8);
    f2.enfileira(7);
    f2.enfileira(6);*/
    f2.imprime();

    return 0;
}
