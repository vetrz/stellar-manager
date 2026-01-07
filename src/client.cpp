#include "../include/client.h"
#include <string>
#include <iostream>

void Client::log(){
    std::cout << "idade: " << idade 
              << " Nome: " << nome 
              << " Conta Ativa: " << (isActivate ? "Sim" : "Não") << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Client& client) {
        os << "(Nome: " << client.nome << "; Idade: " << client.idade << ")";
        return os;
    }


void imprimirArray(int size, Client* array){
    for (int i=0; i < size; i++){
        std::cout  << array[i] << std::endl;        
    }
}

Client* novoTamanho(int size_new, int size_old, Client* array){
    Client* temp = new Client[size_new];
    
    for (int i=0; i < size_old; i++){
        temp[i] = array[i];
    }
    for (int i=size_old; i <size_new; i++){
        temp[i] = Client{0,"default",false};
    }

    return temp;
}