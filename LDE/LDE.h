#ifndef ESTRUTURAS_DE_DADOS_LDE_H
#define ESTRUTURAS_DE_DADOS_LDE_H
#include "No.h"
#include "ILista.h"

template <class Type>
class LDE : public ILista<Type>{
private:
    No<Type>* primeiro;
    int n;
public:
    LDE();
    bool insere(Type x);
    bool remove(int x);
    int busca(Type x);
    const Type&operator[] (int x);
    void imprime();
    ~LDE();
};


#endif //ESTRUTURAS_DE_DADOS_LDE_H
