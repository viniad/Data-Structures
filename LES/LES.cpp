#include "LES.h"
#include <iostream>

using namespace std;


template <class Type>
LES<Type>::LES(int m) {
    this->max = m;
    this->cont = 0;
    this->v = new Type[m];
}

template <class Type>
int LES<Type>::busca(Type dado) {
    int i;
    for(i=0; i<this->cont; i++){
        if(this->v[i] == dado){
            return i;
        }
    }
    return -1;
}

template <class Type>
bool LES<Type>::remove(Type x) {
    int i,j;
        for (int i = 0; i < this->cont ; ++i) {
            if (x == this->v[i]) {
                for(int j = i; j < cont - 1; ++j){
                    this->v[j] = this->v[j + 1];
                }
                this->cont--;
                return true;
            }
        }
    return false;
}

template <class Type>
bool LES<Type>::insere(Type x) {
    int i, j;
    if(cont == max){
        return false;
    }else{
        for(i=0; i < cont && v[i] < x; i++); // acho a posição que deve ser inserido

        for (j = cont; j > i ; --j) { // desloca os numeros maiores
            v[j] = v[j - 1];
        }

        v[i] = x; // insere
        cont++;
    }
    return true;
}

template <class Type>
const Type& LES<Type>::operator[](int idx) {
    if(idx < 0 || idx > cont){
        throw "Indice fora dos limites";
    }else{
        return v[idx];
    }
}

template <class Type>
void LES<Type>::imprime() {
    for ( int i = 0 ; i < cont ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

template <class Type>
LES<Type>::~LES() {
    delete[] this->v;
}