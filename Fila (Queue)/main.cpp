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



int main (int argc, char* argv[]) {
    FilaCircular<float> f (3);
    f.enfileira (5.2);
    f.enfileira (2.2);
    f.enfileira (3.2);
    f.enfileira (9.2);
    f.enfileira (5.1);

    bool ok = false;
    do {
        float r = f.desenfileira (&ok);
        if (ok)
            cout << r << endl;
    } while (ok); // Deve Imprimir somente 5.2, 2.2 e 3.2

    f.enfileira (3);
    f.enfileira (2);
    f.enfileira (1);


    FilaCircular<float> f2 (10);
    f2 = f;


    cout << f.desenfileira ()  << endl; // Deve Imprimir 3
    cout << f2.desenfileira () << endl; // Deve Imprimir 3
    cout << f2.desenfileira () << endl; // Deve Imprimir 2
    cout << f.desenfileira ()  << endl; // Deve Imprimir 2


    f2 << 10 << 9 << 8 << 7 << 6;
    /*f2.enfileira(10);
    f2.enfileira(9);
    f2.enfileira(8);
    f2.enfileira(7);
    f2.enfileira(6);*/
    f2.imprime();

    return 0;
}
