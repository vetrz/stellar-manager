#ifndef CONSTELLATIONFILTERS_HPP
#define CONSTELLATIONFILTERS_HPP

#include "models/constellation.hpp"

namespace stellar 
{

    bool byHemisferio(Constellation constellation, char hemisphere);

    bool byInterval(Constellation constellation, int start, int end);

    bool byName(Constellation constellation, std::string name);

    bool byId(Constellation constellation, int Id); 

}

#endif // CONSTELLATIONFILTERS_HPP