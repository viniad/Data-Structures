#include <iostream>
#include "LES.cpp"
#include "LDE.cpp"

using namespace std;
int main() {
    LES <int> l(7);
    l.insere(5);
    l.insere(10);
    l.insere(15);
    l.insere(20);
    l.insere(12);
    l.insere(1);
    l.insere(30);
    l.imprime();
    l.remove(5);
    l.imprime();

    LDE<int> lde;
    lde.insere(1);
    lde.insere(3);
    lde.insere(5);
    lde.insere(2);
    lde.insere(9);
    lde.imprime();

    LDE<string> ld;
    ld.insere("Vinicius");
    ld.insere("Felipe");
    ld.insere("Giovanni");
    ld.insere("Bruna");
    ld.insere("Pedro");
    ld.imprime();
    return 0;
}