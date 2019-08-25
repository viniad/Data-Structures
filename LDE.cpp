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
}

template <class Type>
bool LDE<Type>::remove(Type x) {

}

template <class Type>
int LDE<Type>::busca(Type x) {
    No<Type>* atual = primeiro;

    int i = 0;
    while(x != atual->valor){
        atual=atual->prox;
        i++;
    }
    return i;
}

template <class Type>
const Type & LDE<Type>::operator[](int x) {}

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
