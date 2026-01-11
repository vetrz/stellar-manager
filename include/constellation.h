#ifndef CONSTELLATION_H
#define CONSTELLATION_H

#include <string>

struct Constellation
{
    int _id;
    std::string _nome;
    int _anoDescobrimento;
    float _distanciaTerra;
    char _hemisferio;
    std::string _significado;

    bool operator==(const Constellation& outro) const 
    {
        /* Define o critério de igualdade */
        return (this->_id == outro._id);
    }

};

std::ostream& operator<<(std::ostream& os, const Constellation& c);

Constellation addConstellationFromInput(int id);

Constellation addConstellation(int id, std::string nome, int anoDescobrimento, float distanciaTerra,
                                 char hemisferio, std::string significado);

#endif // CONSTELLATION_H