#ifndef CONSTELLATION_H
#define CONSTELLATION_H
#include <string>

struct Constellation
{
    int _id = 0;
    std::string _nome = "";
    int _anoDescobrimento = 0;
    float _distanciaTerra = 0.0;
    char _hemisferio = 'd';
    std::string _significado = "";


    bool operator==(const Constellation& outro) const 
    {
        /* Define o critério de igualdade */
        return (this->_id == outro._id);
    }

};

std::ostream& operator<<(std::ostream& os, const Constellation& c);

Constellation addConstellation(Constellation constellation, int _id);

#endif // CONSTELLATION_H