#ifndef CLIENT_H
#define CLIENT_H
#include <string>

struct Client{
    int idade;
    std::string nome;
    bool isActivate;

    void log();
    
};

void imprimirArray(int size, Client* array);

Client* novoTamanho(int size_new, int size_old, Client* array);

#endif // CLIENT_H