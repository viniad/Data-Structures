#include <iostream>
#include "Hash.hpp"

using namespace std;
int main() {
    Hash<int, funcaoHash> h(10);
    h.insere(5);
    h.insere(50);
    h.insere(2);
    h.insere(3);
    h.insere(30);
    h.imprime();
    cout << endl;
    h.insere(7);
    h.insere(4);
    h.insere(8);
    h.insere(90);
    h.insere(100);
    h.insere(12);
    h.insere(1);
    h.imprime();
    cout << endl;
    h.remove(4);
    cout << (h.contem(7) ? "contem 7" : "nao contem 7") << endl;
    h.remove(7);
    cout << (h.contem(7) ? "contem 7" : "nao contem 7") << endl;
    h.imprime();

}