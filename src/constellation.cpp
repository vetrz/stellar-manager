#include "../include/constellation.h"
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

/* Adicionar atributos a um objeto Constellatione de acordo com as entradas do Usuário e retorna um novo Constellation */
Constellation addConstellationFromInput(int id)
{
    Constellation constellation;

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

/* Adicionar atributos a um objeto Constellatione e retorna um novo Constellation */
Constellation addConstellation(int id, std::string nome, int anoDescobrimento, 
                                 float distanciaTerra, char hemisferio, std::string significado)
{
    Constellation constellation;
    constellation._id = id;
    constellation._nome = nome;
    constellation._anoDescobrimento = anoDescobrimento;
    constellation._distanciaTerra = distanciaTerra;
    constellation._hemisferio = hemisferio;
    constellation._significado = significado;

    return constellation;

}