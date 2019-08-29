#include <iostream>
#include "LDE.cpp"

void mostraMsg(string x){
    cout << "                " << x << endl;
    cout << "" << endl;
}

void escolheTipo(){
    mostraMsg("Lista Dinamica Encadeada (LES)");
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


int main() {
    int op, op1, op2 ,op3;

    while(op != 3) {
        escolheTipo();
        op = opcEscolhida(3);
        system("cls");

        if (op == 1) {
            LDE<string> lde;
            while (op1 != 5) {
                menuLES();
                cin >> op1;
                if (op1 == 1) {
                    lde.insere(digitaString());
                    system("cls");
                    mostraMsg("Armazenado com sucesso!");
                    cout << "==========================================" << endl;
                }
                if (op1 == 2) {
                    system("cls");
                    mostraMsg("Dados na LDE");
                    lde.imprime();
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
                if (op1 == 3) {
                    system("cls");
                    mostraMsg("Busca");
                    int idx = lde.busca(digitaString());
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
                    lde.remove(lde.busca(digitaString()));
                    system("cls");
                    mostraMsg("Dado removido");
                    cout << "==========================================" << endl;
                    cout << "" << endl;
                }
            }
        }
        if(op == 2){
            LDE<int> l;
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
                    mostraMsg("Dados na LDE");
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
                    l.remove(l.busca(digitaInt()));
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
