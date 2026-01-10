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
        std::cout << "size: " << vetor._size << "  capacity: "<< vetor._capacity << std::endl;
    }

    vetor.show();

    std::cout << std::endl;

    vetor.remove(2);

    std::cout << std::endl;

    vetor.show();
}