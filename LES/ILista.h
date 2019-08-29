#ifndef ILISTA_H
#define ILISTA_H

using namespace std;
template <class Type>

class ILista{
public:
    virtual bool insere(Type) = 0;
    virtual int busca(Type) = 0;
    virtual bool remove(Type) = 0;
    virtual const Type& operator[](int) = 0;
    virtual void imprime() = 0;
    virtual ~ILista(){};
};

#endif //ILISTA_H
