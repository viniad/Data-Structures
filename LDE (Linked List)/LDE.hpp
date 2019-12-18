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
class LDE;

template <typename T>
ostream& operator<< (ostream& out, const LDE<T>& a);


template <typename T>
class No {
private:
    T valor;
    No<T>* prox;
public:
    // implementa << no nó
    friend ostream& operator<< (ostream& out, const No& x) {
        out << x.valor;
        return out;
    }

    // LDE pode ver membros privados da classe No
    template <typename>
    friend class LDE;

    // Operador << do cout com LDE pode ver membros privados
    friend ostream& operator<<<T> (ostream& out, const LDE<T>& a);
};

template <typename T>
class LDE : public ILista<T> {
private:
    No<T>* primeiro;
    int n;
    T sentinela;

    void limpa () {
        while(this->remove(0));
    }

public:
    LDE () {
        this->primeiro = NULL;
        this->n = 0;
    }
    //Construtor da outra LDE que vai receber a cópia
    LDE (const LDE& outra) {
    }

    bool insere (T valor){
        No<T>* novo = new No<T>;
        novo->valor = valor;
        novo->prox = NULL;

        No<T>* atual = this->primeiro;
        No<T>* anterior = NULL;

        while( atual != NULL && valor > atual->valor){
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
    };

    int busca (T valor){
        No<T>* atual = primeiro;

        int i = 0;
        while(atual && atual->valor <= valor){
            if(atual->valor == valor){
                return i;
            }
            atual=atual->prox;
            i++;
        }
        return -1;
    };

    bool remove (int idx){
        No<T>* anterior = NULL;
        No<T>* atual = primeiro;

        int i = 0;
        if(idx < 0 || idx >= n || atual == NULL){
            return false;
        }

        while(atual && i < idx){
            anterior = atual;
            atual = atual->prox;
            i++;
        }

        if(anterior != NULL){
            anterior->prox = atual->prox;
        }else{
            primeiro = atual->prox;
        }

        delete atual;
        n--;
        return true;
    };

    const T& operator[] (int idx){
        No<T>* atual = primeiro;
        int i = 0;
        if(idx >= n || idx < 0){
            throw "Indice fora dos limites";
        }

        while(atual){
            if(i == idx){
                return atual->valor;
            }
            atual = atual->prox;
            i++;
        }

    };

    void imprime (){
        No<T>* atual = primeiro;

        while(atual){
            cout << atual->valor << " ";
            atual = atual->prox;
        }
        cout << "\n";

    };

    ~LDE () {
        limpa();
    };

    friend ostream& operator<<<T> (ostream& out, const LDE& a);
};

template <typename T>
ostream& operator<< (ostream& out, const LDE<T>& a) {
    No<T>* atual = a.primeiro;
    while (atual) {
        out << *atual << " ";
        atual = atual->prox;
    }
    return out;
}