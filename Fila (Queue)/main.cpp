#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class IFila{
public:
    virtual bool enfileira(T valor) = 0;
    virtual T desenfileira(bool* ok) = 0;
    virtual void imprime() = 0;
    virtual ~IFila(){};
};

template <typename T>
class Fila : public IFila<T>{
private:
    T* v;
    int i;
    int f;
    int max;
public:
    Fila(const Fila& outra){
        v = new T[outra.max];
        i = outra.i;
        f = outra.f;
        max = outra.max;
        //copy(outra )
    }
    Fila(int maximo) {
        v = new T[maximo];
        i=f=0;
        max = maximo + 1;
    }

    ~Fila(){
        delete[] v;
    }

    bool enfileira(T valor){
        if( (f+1) % max == i){
            cout << "Lista cheia" << endl;
            return false;
        }


        v[f] = valor;
        f = (f + 1) % max;
        return true;
    }

    T desenfileira(bool* ok = NULL){
        if( i == f) {
            if(ok){
                *ok = false;
            }
            return v[i];
        }

        T temp = v[i];
        i = (i + 1) % max;
        if(ok)
            *ok = true;
        return temp;

    }

    void imprime(){
        int j;
        for(j=i; j != f; j=(j+1)%max){
            cout << v[j] << " ";
        }
        cout << endl;
    }

};


int main() {

    Fila<float> f(5);
    f.enfileira(10);
    f.enfileira(5);
    f.enfileira(3);
    f.enfileira(8);
    f.enfileira(12);
    f.enfileira(20);
    f.enfileira(22);
    cout << "Fila: ";
    f.imprime();
    cout << endl;

    bool ok;


    do {
        float x = f.desenfileira(&ok);
        if (ok)
            cout << "Desenfileirando.... " << x << endl;
    }while(ok);

    f.imprime();
    f.enfileira(1);
    f.imprime();

    return 0;
}