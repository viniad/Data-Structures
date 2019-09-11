#include <iostream>

using namespace std;

//Interface Lista
template<typename T>
class ILista{
public:
    virtual bool insere(T x) = 0;
    virtual int busca(T dado) = 0;
    virtual bool remove(int) = 0;
    virtual const T& operator[](int) = 0;
    virtual void imprime() = 0;
    virtual ~ILista(){
    };
};

//Classe LES implementa a interface Lista
template<typename T>
class LES : public ILista<T>{
private:
    T* v;
    int n;
    int max;
public:
    //Construtor da classe
    LES(int n): v(new T[n]), n(0), max(max){
        //cout << "LES(int n)" << endl;
    }

    //Copia os números de uma LES para outra LES
    LES(const LES& outra){
        //cout << "LES(const LES&)" << endl;
        max = outra.max;
        n = outra.n;
        v = new T[max];
        for(int i=0;i<n; i++){
            v[i] = outra.v[i];
        }
    }

    //Insere o valor de forma ordenada
    bool insere(T valor){
        if(n >= max)
            return false;

        int i;
        for(i=0;i<n && v[i] < valor; i++);

        for(int j=n;j>i; j--){
            v[j] = v[j-1];
        }
        v[i] = valor;
        n++;
        return true;
    }

    //Busca certo tipo de dado na LES e retorna o índice, caso não seja encontrado retorna -1
    int busca(T dado){
        int i;
        for(i=0; i<n; i++){
            if(v[i] == dado){
                return i;
            }
        }
        return -1;
    }

    //Remove tal dado de acordo com o índice recebido por parametro, retorna true se remover e false caso não remova.
    bool remove(int idx){
        int i,j;
        if(idx != -1){
            for (int i = 0; i < n ; ++i){
                if( i == idx){
                    for (int j = i; j < n - 1; ++j) {
                        v[j] = v[j+1];
                    }
                    n--;
                    return true;
                }
            }
        }
        return false;
    }

    //Imprime todos os dados armazenados na LES
    void imprime(){
        for(int i=0;i<n;i++){
            cout << v[i] << "  ";
        }
        cout << endl;
    }

    //Operador de igualdade de uma LES para outra
    void operator=(const LES& outra){
        cout << "operator=()" << endl;
        delete[] v;
        v = new T[outra.max];
        n = outra.n;
        max = outra.max;
        for(int i=0;i<outra.n; i++){
            v[i] = outra.v[i];
        }
    }

    //Operador [] para ler a LES em certo índice (apenas leitura)
    const T&operator[](int idx){
        if(idx < 0 || idx > n){
            throw "Indice fora dos limites";
        }else{
            return v[idx];
        }
    }

    ~LES(){
        delete[] v;
    }
};


int main() {

    LES<int> l(100);
    l.insere(10);
    l.insere(1);
    l.insere(5);
    l.insere(3);
    l.imprime();
    l.remove(2);
    l.imprime();


    LES<int> l2 = l;
    l2.insere(7);
    cout << "l: ";
    l.imprime();
    cout << "" << endl;
    cout << "l2: ";
    l2.imprime();
    cout << "" << endl;

    return 0;
}