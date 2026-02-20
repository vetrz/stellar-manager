#ifndef DATALOADER_HPP
#define DATALOADER_HPP

#include "core/vetor.hpp"
#include <string> 


namespace stellar 
{
    //para carregar os dados do arquivo csv para o vetor no main
    void readFromFile(Vetor &vetor, std::string file);

    // para salvar os dados do vetor pro csv;
    void saveToFile(Vetor &vetor, std::string filename);
}

#endif // DATALOADER_HPP