#include <iostream>
#include "LDDE.hpp"

using namespace std;

template<typename T>
class IHash{
public:
    virtual bool insere(T chave) = 0;
    virtual bool remove(T chave) = 0;
    virtual bool contem(T chave) = 0;
    virtual void imprime() = 0;
    virtual ~IHash(){ }
};

template<typename T, unsigned int (*F)(T, int tamanho) >
class Hash: public IHash<T>{
private:
    LDDE<T> *hashTable;
    int tamanho;
    int n;
    unsigned int funcaoHash(T chave){
        return F(chave, tamanho);
    }
public:
    Hash(int tamanho):
            hashTable(new LDDE<T>[tamanho]),
            tamanho(tamanho),
            n(0){}

    ~Hash(){
        delete[] hashTable;
    }

    bool contem(T valor)  {
        return hashTable[funcaoHash(valor)].busca(valor) != -1;
    }

    bool insere(T valor)  {
        if(contem(valor) || n >= tamanho)
            return false;
        n++;
        return hashTable[funcaoHash(valor)].insere(valor);
    }

    bool remove(T valor)  {
        int idx = hashTable[funcaoHash(valor)].busca(valor);
        if(idx != -1) {
            n--;
            return hashTable[funcaoHash(valor)].remove(idx);
        }
        return -1;
    }

    void imprime(){
        int i;
        for(i = 0; i<tamanho; i++){
            hashTable[i].imprime();
        }
    }

};

unsigned int funcaoHash(int x, int tamanho){
    return x % tamanho;
}

