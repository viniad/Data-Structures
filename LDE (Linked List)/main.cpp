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
class LDE;

// Pré-declarações
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
    //Função para limpar toda a LDE
    void limpa () {
        while(this->remove(0));
    }
    //Função para copiar uma LDE para outra
    void copia (const LDE& other) {
    }

public:
    //Construtor
    LDE () {
        this->primeiro = NULL;
        this->n = 0;
    }
    //Construtor da outra LDE que vai receber a cópia
    LDE (const LDE& outra) {
    }

    //Insere o nó na LDE
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

    //Busca o valor na LDE e retorna o índice em qual está, -1 caso não exista
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

    //Remove o valor da LDE recebendo por parametro o índice que está localizado (realizar a busca primeiro)
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

    //Operador [] para ler o índice recebido por parametro (apenas leitura)
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

    //Imprime os valores na LDE
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

int main () {
    LDE<int> l;

    l.insere (2);
    l.insere (9);
    l.insere (1);
    l.insere (4);
    l.insere (8);
    l.imprime();
    l.remove(l.busca(9));
    l.remove(l.busca(1));
    l.imprime();

    try{
        cout << "Tentando acessar o l[0]... " << l[0] << endl;
        cout << "Tentando acessar o l[10]... " << l[10] << endl;
    }catch(char const* msg){
        cout << msg << endl;
    }


    /* {
        LDE<int> l2 = l;
        cout << "===================================" << endl;
        cout << "Lista 2: " << l2 << endl;
        cout << "Removendo indice 3" << endl;
        l2.Remove (3);
        cout << "Lista 2: " << l2 << endl;
        l2.Remove (l2.Busca (9));
        cout << "Removendo numero 9" << endl;
        cout << "Lista 2: " << l2 << endl;

        cout << "Removendo numeros e indices invalidos" << endl;
        l2.Remove (99);
        l2.Remove (l2.Busca (9999));
        cout << "===================================" << endl;
    }

    cout << "Lista 1: " << l << endl;
    cout << "Numero 8 esta na posicao: " << l.Busca (8) << endl;
    cout << "O numero que esta na posicao 2 eh: " << l[2] << endl;*/


    return 0;
}

