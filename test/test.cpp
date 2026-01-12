#include "../include/constellationFilters.h"
#include "../include/constellation.h"
#include "../include//vetor.h"
#include <iostream>


int main(){
    Vetor vetor;
    int quantidade;

    std::cout << "Digite a Quantidade de usuarios que deseja inserir: "; 
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++){
        vetor.push(addConstellationFromInput(vetor.size()+1));
        std::cout << "size: " << vetor.size() << "  capacity: "<< vetor.capacity() << std::endl;
        std::cout << "endereço" << &vetor[i] << std::endl;
    }

    vetor.show();

    std::cout << std::endl;

    Vetor filtrado = vetor.filter(isNorth);

    filtrado.show();

    std::cout << "size: " << filtrado.size() << "  capacity: "<< filtrado.capacity() << std::endl;

    filtrado.push(addConstellationFromInput(vetor.size()+1));

    std::cout << std::endl;

    filtrado.show();
}