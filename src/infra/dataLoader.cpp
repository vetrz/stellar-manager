#include "infra/dataLoader.hpp"
#include "core/vetor.hpp"
#include "models/constellation.hpp"
#include <string>
#include <fstream>
#include <iostream>

namespace stellar 
{
    void readFromFile(Vetor &vetor, std::string filename){
    
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Erro ao abrir o arquivo [" << filename << "]" << std::endl;
        return;
    }

    // "pula" o cabeçalho do csv
    std::string lixo;
    std::getline(file,lixo);

    std::string aux;

    //o loop vai ler do arquivo até não conseguir mais colocar dados na variável aux (até o fim do arquivo):
        while(std::getline(file,aux,',')){
        //id recebe a primeira string lida e guardada na variável auxiliar
            int id =  std::stoi(aux);

        //lê o nome da constelação, guarda em uma váriável nome e descarta a vírgula
            std::string nome;
            std::getline(file,nome,',');

        //lê a próxima string e guarda na variável auxiliar
            std::getline(file,aux,',');
            u_short descobrimento = std::stoi(aux); //descobrimento recebe a string lida transformada em u_short

            std::getline(file,aux,',');
            float distancia = std::stof(aux); //distancia recebe a string lida transformada em float

        //lê  o hemisfério 
            char hemisferio;
            file >> hemisferio; 
            file.ignore(); //descarta a virgula;

            std::string significado;
            std::getline(file,significado);

            Constellation c = addConstellation(id,nome,descobrimento,distancia,hemisferio,significado);
            vetor.push(c);

        }

    }
}