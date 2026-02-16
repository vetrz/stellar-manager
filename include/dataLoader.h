#ifndef DATALOADER_H
#define DATALOADER_H

#include "vetor.h"
#include <string> 

//para carregar os dados do arquivo csv para o vetor no main
void readFromFile(Vetor &vetor, std::string file);

#endif // DATALOADER_H