#include "../include/constellation.h"
#include "../include//vetor.h"
#include <iostream>


int main(){
    Vetor vetor;
    int quantidade;

    std::cout << "Digite a Quantidade de usuarios que deseja inserir: "; 
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++){
        vetor.push(addConstellationFromInput(i+1));
        std::cout << "size: " << vetor.size() << "  capacity: "<< vetor.capacity() << std::endl;
        std::cout << "endereço" << &vetor[i] << std::endl;
    }

    vetor.show();

    std::cout << std::endl;

    vetor.remove(2);

    std::cout << std::endl;

    vetor.show();
}