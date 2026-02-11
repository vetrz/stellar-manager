#include "services/constellationFilters.hpp"
#include "models/constellation.hpp"
#include <string>

/* Filtros por Hemisferio */
bool isNorth(Constellation constellation)
{
    return constellation.hemisferio == 'N';
}

bool isWest(Constellation constellation)
{
    return constellation.hemisferio == 'O';
}

bool isEast(Constellation constellation)
{
    return constellation.hemisferio == 'L';
}

bool isSouth(Constellation constellation)
{
    return constellation.hemisferio == 'S';
}