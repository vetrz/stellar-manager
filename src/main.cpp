#include "../include/constellation.h"
#include "../include//vetor.h"
#include "../include/dataLoader.h"
#include <iostream>

int main()
{
    Vetor vetor;
    Constellation c;
    int quantidade;

    // std::cout << "Digite a Quantidade de usuarios que deseja inserir: "; 
    // std::cin >> quantidade;

    // for (int i = 0; i < quantidade; i++){
    //     vetor.push(addConstellationFromInput(i+1));
    // }

    readFromFile(vetor,"data/constellation.csv");

    vetor.show();
}