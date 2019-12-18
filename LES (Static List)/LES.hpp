using namespace std;

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

template<typename T>
class LES : public ILista<T>{
private:
    T* v;
    int n;
    int max;
public:
    LES(int n): v(new T[n]), n(0), max(max){
        //cout << "LES(int n)" << endl;
    }

    LES(const LES& outra){
        //cout << "LES(const LES&)" << endl;
        max = outra.max;
        n = outra.n;
        v = new T[max];
        for(int i=0;i<n; i++){
            v[i] = outra.v[i];
        }
    }

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

    int busca(T dado){
        int i;
        for(i=0; i<n; i++){
            if(v[i] == dado){
                return i;
            }
        }
        return -1;
    }

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

    void imprime(){
        for(int i=0;i<n;i++){
            cout << v[i] << "  ";
        }
        cout << endl;
    }

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
