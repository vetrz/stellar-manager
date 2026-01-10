#include "../include/client.h"
#include "../include//vetor.h"
#include <iostream>
#include <string>

/* "Ensinado ao compilador" como enteder a operção de std::cout << Client::client */
std::ostream& operator<<(std::ostream& os, const Client& client) 
{
    os << "Id: "<< client._id << "; Nome: " << client._nome << "; Idade: " << client._idade << "; Conta Ativa: " << client._isActivate;
    return os;
}

/* Função Para Adicionar atributos ao cliente, ou seja suas informações */
Client adicionarClient(Client client, int id)
{
    client._id = id;

    std::cout << "digite o nome do usario: ";
    std::cin >> client._nome;

    std::cout << "digite a idade: ";
    std::cin >> client._idade;

    client._isActivate = true;

    return client;
}