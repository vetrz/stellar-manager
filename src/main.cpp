#include "../include/constellation.h"
#include "../include//vetor.h"
#include <iostream>

int main()
{
    Vetor vetor;
    Constellation c;
    int quantidade;

    std::cout << "Digite a Quantidade de usuarios que deseja inserir: "; 
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++){
        vetor.push(addConstellation(c,i+1));
    }

    vetor.show();
}