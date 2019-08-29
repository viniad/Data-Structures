#ifndef LES_H_
#define LES_H_

#include "ILista.h"

template <class Type>
class LES : public ILista<Type>{
private:
    int max;
    int cont;
    Type *v;
public:
    LES(int m);
    bool insere(Type x);
    int busca(Type dado);
    bool remove(Type x);
    void imprime();
    const Type&operator[](int idx);
    ~LES();
};


#endif //LES_H_
