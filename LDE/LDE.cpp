#include "LDE.h"
#include "No.h"

template <class Type>
LDE<Type>::LDE() {
    this->primeiro = NULL;
    this->n = 0;
}

template <class Type>
bool LDE<Type>::insere(Type dado) {
    No<Type>* novo = new No<Type>;
    novo->valor = dado;
    novo->prox = NULL;

    No<Type>* atual = this->primeiro;
    No<Type>* anterior = NULL;

    while( atual != NULL && dado > atual->valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        this->primeiro = novo;
    }
    else{
        anterior->prox = novo;
    }

    novo->prox = atual;
    n++;
    return true;
}

template <class Type>
bool LDE<Type>::remove(int idx) {
    No<Type>* anterior = NULL;
    No<Type>* atual = primeiro;

    int i = 0;
    if(idx < 0 || idx > n){
        return false;
    }

    while(atual && i < idx){
        anterior = atual;
        atual = atual->prox;
        i++;
    }

    if(anterior != NULL){
        anterior->prox = atual->prox;
    }else{
        primeiro = atual->prox;
    }

    delete atual;
    n--;
}

template <class Type>
int LDE<Type>::busca(Type x) {
    No<Type>* atual = primeiro;

    int i = 0;
    while(atual && atual->valor <= x){
        if(atual->valor == x){
            return i;
        }
        atual=atual->prox;
        i++;
    }
    return -1;
}

template <class Type>
const Type & LDE<Type>::operator[](int idx) {
    No<Type>* atual = primeiro;
    int i = 0;
    if(idx > n || idx < 0){
        throw "Indice fora dos limites";
    }else{
        while(atual){
            if(i == idx){
                return atual->valor;
            }
            atual = atual->prox;
            i++;
        }
    }
}

template <class Type>
void LDE<Type>::imprime() {
    No<Type>* atual = primeiro;

    while(atual){
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "\n";
}
template <class Type>
LDE<Type>::~LDE() {
    delete this->primeiro;
}
