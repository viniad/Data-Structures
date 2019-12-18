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


template <typename T>
class LDDE;
template <typename T>
ostream& operator<< (ostream& out, const LDDE<T>& a);

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

    static void copia (LDDE& dest, const LDDE& orig) {
        while (dest.Remove (0));

        No<T>* atual = orig.primeiro;
        No<T>* ultimo_inserido = NULL;
        No<T>* novo;

        while (atual) {
            novo = new No<T>;
            if (ultimo_inserido)
                ultimo_inserido->prox = novo;
            else
                dest.primeiro = novo;

            novo->anterior = ultimo_inserido;
            ultimo_inserido = novo;
            dest.n++;
            atual = atual->prox;
        }
        dest.ultimo = novo;
    }

public:
    LDDE () {
        this->primeiro = NULL;
        this->ultimo = NULL;
        this->n = 0;
    }

    // Copia uma LDDE para outra
    LDDE (const LDDE& other) {
        this->primeiro = NULL;
        this->ultimo = NULL;
        this->n = other.n;
    }

    // Este operador faz a cópia da lista em caso de atribuições
    LDDE& operator= (const LDDE& other) {
        copia (*this, outra);
        return *this;
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
        while(remove(0));
    }

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