#ifndef DATALOADER_HPP
#define DATALOADER_HPP

#include "core/vetor.hpp"
#include <string> 

//para carregar os dados do arquivo csv para o vetor no main
namespace stellar 
{
    void readFromFile(Vetor &vetor, std::string file);
}

#endif // DATALOADER_HPP