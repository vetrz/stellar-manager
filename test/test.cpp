#include "../include/client.h"
#include "../include//vetor.h"
#include <iostream>


int main(){
    Vetor vetor;
    Client c;
    int quantidade;

    std::cout << "Digite a Quantidade de usuarios que deseja inserir: "; 
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++){
        vetor.push(adicionarClient(c,i+1));
    }

    vetor.show();
}