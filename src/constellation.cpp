#include "../include/constellation.h"
#include <iostream>
#include <string>

/* "Ensinado ao compilador" como enteder a operção de std::cout << Constellation::Constellation */
std::ostream& operator<<(std::ostream& os, const Constellation& constellation) 
{
    os << "Id: "<< constellation.id << "; Nome: " << constellation.nome << 
    "; Ano de Descobrimento: " << constellation.anoDescobrimento << 
    "; Distancia da Terra: " << constellation.distanciaTerra <<
    "; Hemisferio: " << constellation.hemisferio <<
    "; Significado mitologico: " << constellation.significado;

    return os;
}

/* Adicionar atributos a um objeto Constellatione de acordo com as entradas do Usuário e retorna um novo Constellation */
Constellation addConstellationFromInput(int id)
{
    Constellation constellation;

    constellation.id = id;

    std::cout << "digite o nome da constelação: ";
    std::getline(std::cin.ignore(), constellation.nome);

    std::cout << "digite o ano de descobrimento: ";
    std::cin >> constellation.anoDescobrimento;

    std::cout << "digite a distancia da Terra: ";
    std::cin >> constellation.distanciaTerra;

    std::cout << "digite o hemisferio: ";
    std::cin >> constellation.hemisferio;

    std::cout << "digite o significado mitologico: ";
    std::getline(std::cin.ignore(), constellation.significado);

    return constellation;
}

/* Adicionar atributos a um objeto Constellatione e retorna um novo Constellation */
Constellation addConstellation(int id, std::string nome, u_short anoDescobrimento, 
                                 float distanciaTerra, char hemisferio, std::string significado)
{
    Constellation constellation;
    constellation.id = id;
    constellation.nome = nome;
    constellation.anoDescobrimento = anoDescobrimento;
    constellation.distanciaTerra = distanciaTerra;
    constellation.hemisferio = hemisferio;
    constellation.significado = significado;

    return constellation;

}