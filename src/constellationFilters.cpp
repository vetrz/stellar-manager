#include "../include/constellationFilters.h"
#include "../include/constellation.h"
#include <string>


/* Filtros por Hemisferio */
bool isNorth(Constellation constellation)
{
    if (constellation._hemisferio == 'N'){
        return true;
    }
    return false;
}

bool isWest(Constellation constellation)
{
    if (constellation._hemisferio == 'O'){
        return true;
    }
    return false;
}

bool isEast(Constellation constellation)
{
    if (constellation._hemisferio == 'L'){
        return true;
    }
    return false;
}

bool isSouth(Constellation constellation)
{
    if (constellation._hemisferio == 'S'){
        return true;
    }
    return false;
}