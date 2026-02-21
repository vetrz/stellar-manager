#include "services/constellationFilters.hpp"
#include "models/constellation.hpp"
#include <string>

namespace stellar 
{
    bool byHemisferio(Constellation constellation, char hemisphere){
        return constellation.hemisferio == hemisphere;
    }

    bool byInterval(Constellation constellation, int start, int end){
        return constellation.id >= start && constellation.id <= end;
    }

    bool byName(Constellation constellation, std::string name){
        return constellation.nome == name;
    }

    bool byId(Constellation constellation, int Id){ 
        return constellation.id == Id;
    } 
}