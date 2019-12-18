#include <iostream>
using namespace std;

template <typename T>
class IFila {
public:
    virtual bool enfileira (T valor) = 0;
    virtual T desenfileira (bool* ok) = 0;
    virtual void imprime () = 0;
    virtual ~IFila () {
    }
};

template <typename T>
class FilaCircular : IFila<T> {
private:
    T* v;
    int max;
    int i;
    int f;

public:
    explicit FilaCircular (int Max){
        v = new T[Max];
        i=f=0;
        max = Max + 1;
    }

    virtual ~FilaCircular (){
        delete[] v;
    }

    bool enfileira (T valor){
        if((f+1)% max == i){
            cout << "Lista cheia" << endl;
            return false;
        }

        v[f] = valor;
        f = (f+1) % max;
        return true;

    }

    void imprime(){
        int j;
        for(j = i; j != f; j=(j+1) % max){
            cout << v[j] << " ";
        }
        cout << endl;
    }

    T desenfileira(bool* ok = NULL){
        if(i == f){
            if(ok){
                *ok = false;
            }
            return v[i];
        }

        T temp = v[i];
        i = (i+1) % max;
        if(ok)
            *ok = true;
        return temp;
    }

    FilaCircular (const FilaCircular& outra){
        max = outra.max;
        i = outra.i;
        f = outra.f;
        v = new T[max];

        int j;
        for(j = i; j != f; j = (j+1)%max){
            v[j] = outra.v[j];
        }
    }

    FilaCircular& operator= (const FilaCircular& outra){
        cout << "operator=()" << endl;
        delete[] v;
        i = outra.i;
        f = outra.f;
        max = outra.max;
        v = new T[max];

        int j;
        for(j = i; j != f; j = (j+1)%outra.max){
            v[j] = outra.v[j];
        }
    }

    FilaCircular& operator<< (T valor){
        enfileira(valor);
        return *this;
    }

};