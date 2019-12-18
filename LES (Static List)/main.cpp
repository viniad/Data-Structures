#include <iostream>
#include "LES.hpp"
using namespace std;

int main() {

    LES<int> l(100);
    l.insere(10);
    l.insere(1);
    l.insere(5);
    l.insere(3);
    l.imprime();
    l.remove(2);
    l.imprime();


    LES<int> l2 = l;
    l2.insere(7);
    cout << "l: ";
    l.imprime();
    cout << "" << endl;
    cout << "l2: ";
    l2.imprime();
    cout << "" << endl;

    return 0;
}