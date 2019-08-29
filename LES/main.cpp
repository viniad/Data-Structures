#include <iostream>
#include "LES.cpp"

void mostraMsg(string x){
    cout << "                " << x << endl;
    cout << "" << endl;
}
void escolheTipo(){
    mostraMsg("Lista Estatica Sequencial");
    cout << "(1) Strings" << endl;
    cout << "(2) Numeros" << endl;
    cout << "(3) Sair" << endl;
    cout << "" << endl;
}

string digitaString(){
    system("cls");
    cout << "Digite a string" << endl;
    string x;
    cin >> x;
    return x;
}

int digitaInt(){
    system("cls");
    cout << "Digite o numero" << endl;
    int x;
    cin >> x;
    return x;
}
void menuLES(){
    mostraMsg("LES");
    cout << "(1) Armazenar" << endl;
    cout << "(2) Ver dados armazenados" << endl;
    cout << "(3) Buscar" << endl;
    cout << "(4) Remover" << endl;
    cout << "(5) Voltar p/ tipos " << endl;
}

int opcEscolhida(int max){
    int x;
    do{
        cin >> x;
    }while(x > max || x < 0);

    return x;
}

using namespace std;
int main() {
    int op, op1, op2;

    while(op != 3) {
        escolheTipo();
        op = opcEscolhida(3);
        system("cls");

        if (op == 1) {
            LES<string> les(15);
            while (op1 != 5) {
                menuLES();
                cin >> op1;
                if (op1 == 1) {
                    les.insere(digitaString());
                    system("cls");
                    mostraMsg("Armazenado com sucesso!");
                    cout << "==========================================" << endl;
                }
                if (op1 == 2) {
                    system("cls");
                    mostraMsg("Dados na LES");
                    les.imprime();
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
                if (op1 == 3) {
                    system("cls");
                    mostraMsg("Busca");
                    int idx = les.busca(digitaString());
                    if (idx != -1) {
                        cout << "Dado localizado no indice " << idx << endl;
                    } else {
                        cout << "Nao foi possivel localizar" << endl;
                    }
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
                if (op1 == 4) {
                    system("cls");
                    mostraMsg("Remocao");
                    les.remove(digitaString());
                    system("cls");
                    mostraMsg("Dado removido");
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
            }
        }
        if(op == 2){
            LES<int> l(15);
            while (op1 != 5) {
                menuLES();
                cin >> op1;
                if (op1 == 1) {
                    l.insere(digitaInt());
                    system("cls");
                    mostraMsg("Armazenado com sucesso!");
                    cout << "==========================================" << endl;
                }
                if (op1 == 2) {
                    system("cls");
                    mostraMsg("Dados na LES");
                    l.imprime();
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
                if (op1 == 3) {
                    system("cls");
                    mostraMsg("Busca");
                    int idx = l.busca(digitaInt());
                    if (idx != -1) {
                        cout << "Dado localizado no indice " << idx << endl;
                    } else {
                        cout << "Nao foi possivel localizar" << endl;
                    }
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
                if (op1 == 4) {
                    system("cls");
                    mostraMsg("Remocao");
                    l.remove(digitaInt());
                    system("cls");
                    mostraMsg("Dado removido");
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
            }
        }
    }
    return 0;
}