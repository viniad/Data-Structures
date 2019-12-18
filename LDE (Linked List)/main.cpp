#include <chrono>
#include <iostream>
#include "LDE.hpp"

int main () {
    LDE<int> l;

    l.insere (2);
    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);
    l.imprime();
    l.remove(l.busca(9));
    l.remove(l.busca(1));
    l.imprime();

    try{
        cout << "Tentando acessar o l[0]... " << l[0] << endl;
        cout << "Tentando acessar o l[10]... " << l[10] << endl;
    }catch(char const* msg){
        cout << msg << endl;
    }


    /* {
        LDE<int> l2 = l;
        cout << "===================================" << endl;
        cout << "Lista 2: " << l2 << endl;
        cout << "Removendo indice 3" << endl;
        l2.Remove (3);
        cout << "Lista 2: " << l2 << endl;
        l2.Remove (l2.Busca (9));
        cout << "Removendo numero 9" << endl;
        cout << "Lista 2: " << l2 << endl;

        cout << "Removendo numeros e indices invalidos" << endl;
        l2.Remove (99);
        l2.Remove (l2.Busca (9999));
        cout << "===================================" << endl;
    }

    cout << "Lista 1: " << l << endl;
    cout << "Numero 8 esta na posicao: " << l.Busca (8) << endl;
    cout << "O numero que esta na posicao 2 eh: " << l[2] << endl;*/


    return 0;
}

