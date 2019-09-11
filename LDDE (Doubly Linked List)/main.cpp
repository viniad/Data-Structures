#include <chrono>
#include <iostream>

using namespace std;

template <typename T>
class ILista {
public:
    virtual bool insere (T) = 0;
    virtual int busca (T) = 0;
    virtual bool remove (int) = 0;
    virtual const T& operator[] (int) = 0;
    virtual void imprime () = 0;
    virtual ~ILista (){};
};

// Pré-declarações
template <typename T>
class LDDE;

// Pré-declarações
template <typename T>
ostream& operator<< (ostream& out, const LDDE<T>& a);

// Implementações
template <typename T>
class No {
private:
    int valor;
    No<T>* prox;
    No<T>* anterior;

public:
    // implementa << no nó
    friend ostream& operator<< (ostream& out, const No& x) {
        out << x.valor;
        return out;
    }

    // LDDE pode ver membros privados da classe No
    template <typename>
    friend class LDDE;

    // Operador << do cout com lde pode ver membros privados da classe No
    friend ostream& operator<<<T> (ostream& out, const LDDE<T>& a);
};

template <typename T>
class LDDE : public ILista<T> {
private:
    No<T>* primeiro;
    No<T>* ultimo;
    int n;
    T sentinela;

public:
    LDDE () {
        this->primeiro = NULL;
        this->ultimo = NULL;
        this->n = 0;
    }

    // Copia uma LDDE para outra
    LDDE (const LDDE& other) {
        /* cout << "operador =()" << endl;
         this->primeiro = NULL;
         this->n = other.n;

         No<T>* atual = other.primeiro;
         No<T>* aux = primeiro;

         while(atual){
             No<T>* novo = new No<T>;
             novo->valor = atual->valor;
             novo->anterior = NULL;
             novo->prox = NULL;

             No<T>* atr = NULL;
             while(aux && aux->valor < novo->valor){
                 atr = aux;
                 aux = aux->prox;
             }

             if(atr){
                 atr->prox = novo;
                 novo->anterior = atr;

             }else{
                 this->primeiro = novo;
             }
             if(atual)
                 atual->anterior = novo;

             novo->prox = atual;
             atual = atual->prox;
         }
 */
    }

    // Este operador faz a cópia da lista em caso de atribuições
    LDDE& operator= (const LDDE& other) {
        /*  cout << "operador =()" << endl;
          this->primeiro = NULL;
          this->n = other.n;

          No<T>* atual = other.primeiro;
          No<T>* aux = primeiro;

          while(atual){
              No<T>* novo = new No<T>;
              novo->valor = atual->valor;
              novo->anterior = NULL;
              novo->prox = NULL;

              No<T>* atr = NULL;
              while(aux && aux->valor < novo->valor){
                  atr = aux;
                  aux = aux->prox;
              }

              if(atr){
                  atr->prox = novo;
                  novo->anterior = atr;

              }else{
                  this->primeiro = novo;
              }
              if(atual)
                  atual->anterior = novo;

              novo->prox = atual;
              atual = atual->prox;
          }*/
    }

    bool insere (T valor){
        No<T>* novo = new No<T>;
        novo->valor = valor;
        novo->anterior = NULL;
        novo->prox = NULL;

        No<T>* atual = this->primeiro;
        No<T>* ptrAnterior = NULL;

        while( atual && atual->valor < valor){
            ptrAnterior = atual;
            atual = atual->prox;
        }

        if(ptrAnterior){
            ptrAnterior->prox = novo;
            novo->anterior = ptrAnterior;

        }else{
            this->primeiro = novo;
        }
        if(atual)
            atual->anterior = novo;
        else
            ultimo = novo;

        novo->prox = atual;
        n++;
        return true;
    };

    int busca (T valor){
        No<T>* atual = primeiro;
        int i = 0;

        while(atual && atual->valor <= valor){
            if(atual->valor == valor){
                return i;
            }
            i++;
            atual = atual->prox;
        }

        return -1;
    };

    bool remove (int idx){
        No<T>* atual = primeiro;
        No<T>* ptrAnterior = NULL;

        if(idx < 0 || idx >= n || atual == NULL){
            return false;
        }

        int i = idx;
        while(atual && i--){
            ptrAnterior  = atual;
            atual = atual->prox;
        }

        if(ptrAnterior){
            ptrAnterior->prox = atual->prox;

        }else{
            primeiro = atual->prox;
        }
        if(atual->prox){
            atual->prox->anterior = ptrAnterior;
        }else{
            ultimo = ptrAnterior;
        }

        delete atual;
        return true;
    };

    const T& operator[] (int idx){
        No<T>* atual = primeiro;
        No<T>* ptrAnterior = NULL;
        int i = idx;

        while(atual && i--){
            atual = atual->prox;
        }

        return atual->valor;

    };

    void imprime (){
        No<T>* aux = primeiro;

        while(aux){
            cout << aux->valor << " ";
            aux = aux->prox;
        }

        cout << "\n";
    };


    ~LDDE (){
        delete this->primeiro;
    };

    friend ostream& operator<<<T> (ostream& out, const LDDE& a);
};


template <typename T>
ostream& operator<< (ostream& out, const LDDE<T>& a) {
    No<T>* atual = a.primeiro;
    while (atual) {
        cout << *atual << " ";
        atual = atual->prox;
    }
    return out;
}

int main () {
    LDDE<int> l;

    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);

    cout << "Lista 1: " << l << endl;
    cout << "Numero 8 esta na posicao: " << l.busca(8) << endl;
    cout << "O numero que esta na posicao 2 eh: " << l[2] << endl;
    while (l.remove(0));

    cout << "" << endl;
    cout << "Lista: " << l << endl; // Lista vazia (não imprime nada)
    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);
    cout << "lista: " << l << endl;

    cout << "" << endl;

    LDDE<int> ld;
    ld = l;
    ld.insere(20);
    cout << "L: " << l << endl;
    cout << "Ld: " << ld << endl;
    return 0;
}

