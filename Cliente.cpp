#include "Cliente.h"

Cliente::Cliente(string n, string c) : nome(n), cpf(c) {}

string Cliente::getNome() const { return nome; }

string Cliente::getCPF() const { return cpf; }
