#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string nameLogin;
string passLogin;
string nameRegis;
string passRegis;

int saldo;
int saldoLevantar;
int saldoDepositar;

int depositar();
int levantar();
void verificar();
void painel();
void inicial();
void login();
int main();

int depositar(int valor) {
    saldoDepositar = valor;
    saldo = saldo + saldoDepositar;

    return saldo;
}

int levantar(int valor) {
    if (valor > saldo) {
        saldoLevantar = valor;
        saldo = saldo - saldoLevantar;
        return saldo;
    } 
    else {
        cout << "Saldo insuficiente!" << endl;
    }
}

void verificar() {
    cout << saldo;
}

void criar() {
 
    int opcao = 1;

    cout << "-------------------------------------" << endl;
    cout << "---------- CRIAR CONTA --------------" << endl;
    cout << "-------------------------------------" << endl;

    cout << "Digite o nome de Usuario: ";
    cin >> nameRegis;
    cout << endl;

    cout << "Digite a senha: ";
    cin >> passRegis;
    cout << endl;

   while (passRegis.length() < 8) {
        cout << "Numero de caracteres invalido!" << endl;
        cout << "Digite novamente: ";
        cin >> passRegis;
        cout << endl;
    }

   cout << "Retornar ao Ecra incial ou logar? " << endl;
   cout << "[1] - Inicial" << endl;
   cout << "[2] - Logar" << endl;
   cout << "Opcao: ";
   cin >> opcao;
   cout << endl;

   switch (opcao) {
   case 1: {
       system("cls");
       inicial();

       break;
   }
   case 2: {
       system("cls");
       login();

       break;
   }
   default:
       cout << "Opcao Invalida" << endl;
       system("cls");
       inicial();

   }
}

void login() {
    int verificar = 0;
    while (verificar < 1) {
        cout << "---------------------------------------" << endl;
        cout << "----------- Logar na Conta ------------" << endl;
        cout << "---------------------------------------" << endl;

        cout << "Digite o nome do Usuario: ";
        cin >> nameLogin;
        cout << endl;

        cout << "Digite a Senha: ";
        cin >> passLogin;
        cout << endl;

        if (nameLogin == nameRegis && passRegis == passLogin) {
            verificar = 1;
            system("cls");
            painel();
        }
        system("cls");
    }

}

void inicial() {
    int opcao;
    
    cout << "-------------------------------------" << endl;
    cout << "-------------- BANCO ----------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "[1] - Criar conta" << endl;
    cout << "[2] - Logar na conta" << endl;
    cout << "Digite a sua opcao: ";
    cin >> opcao;
    cout << endl;
    
    switch (opcao) {
        case 1: {
            system("cls");
            criar();

            break;
        }
        case 2: {
            system("cls");
            login();

            break;
        }
        default:
            cout << "Opcao Invalida" << endl;
            system("cls");
            inicial();
            
    }

    system("cls");
    login();

}

void painel() {
    int opcao,valor,enter = 0;
    int rep = 0;

    while (rep <= 1) {

        cout << "-------------------------------------" << endl;
        cout << "-------------- PAINEL ---------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Bom dia, " << nameLogin << endl;
        cout << "Como posso ajudar?" << endl;
        cout << "[1] - Levantar" << endl;
        cout << "[2] - Depositar" << endl;
        cout << "[3] - Verificar saldo" << endl;
        cout << "[4] - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            cout << "Quantidade que deseja levantar: ";
            cin >> valor;
            cout << "Saldo atual: " << levantar(valor);
            valor = 0;
            break;
        }
        case 2: {
            cout << "Quantidade que deseja depositar: ";
            cin >> valor;
            cout << endl;
            cout << "Saldo atual: " << depositar(valor);
            cin >> enter;
            valor = 0;
            break;
        }
        case 3: {
            cout << saldo << " EUR" << endl;
            cin >> enter;
            break;
        }
        case 4: {
            rep = 1;
            break;
        }
        default:
            cout << "Opcao Invalida" << endl;
            system("cls");
            painel();
        }
        system("cls");
    }
}

int main()
{
    inicial();

    system("pause");
    return 0;
}
