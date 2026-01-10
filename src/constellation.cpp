#include "../include/constellation.h"
#include "../include//vetor.h"
#include <iostream>
#include <string>

/* "Ensinado ao compilador" como enteder a operção de std::cout << Constellation::Constellation */
std::ostream& operator<<(std::ostream& os, const Constellation& constellation) 
{
    os << "Id: "<< constellation._id << "; Nome: " << constellation._nome << 
    "; Ano de Descobrimento: " << constellation._anoDescobrimento << 
    "; Distancia da Terra: " << constellation._distanciaTerra <<
    "; Hemisferio: " << constellation._hemisferio <<
    "; Significado mitologico: " << constellation._significado;

    return os;
}

/* Função Para Adicionar atributos ao Constellatione, ou seja suas informações */
Constellation addConstellation(Constellation constellation, int id)
{
    constellation._id = id;

    std::cout << "digite o nome da constelação: ";
    std::getline(std::cin.ignore(), constellation._nome);

    std::cout << "digite o ano de descobrimento: ";
    std::cin >> constellation._anoDescobrimento;

    std::cout << "digite a distancia da Terra: ";
    std::cin >> constellation._distanciaTerra;

    std::cout << "digite o hemisferio: ";
    std::cin >> constellation._hemisferio;

    std::cout << "digite o significado mitologico: ";
    std::getline(std::cin.ignore(), constellation._significado);

    return constellation;
}