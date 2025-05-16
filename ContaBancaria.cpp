#include "ContaBancaria.h"
using namespace std;

ContaBancaria::ContaBancaria(int n, Cliente t, double s)
    : numero(n), titular(t), saldo(s) {}

void ContaBancaria::depositar(double valor) {
    saldo += valor;
}

void ContaBancaria::sacar(double valor) {
    if (valor <= saldo) {
        saldo -= valor;
    } else {
        cout << "Saldo insuficiente para saque." << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor <= saldo) {
        saldo -= valor;
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta " << numero
             << " para a conta " << destino.numero << endl;
    } else {
        cout << "Saldo insuficiente para transferência." << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if (valor <= saldo) {
        double metade = valor / 2.0;
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        cout << "Transferido: R$ " << metade << " para cada conta ("
             << destino1.numero << " e " << destino2.numero
             << ") da conta " << numero << endl;
    } else {
        cout << "Saldo insuficiente para transferência dupla." << endl;
    }
}

void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome()
         << ", CPF: " << titular.getCPF() << endl;
    cout << "Número da Conta: " << numero
         << ", Saldo: R$ " << saldo << endl;
}
