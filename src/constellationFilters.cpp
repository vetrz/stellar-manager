#include "../include/constellationFilters.h"
#include "../include/constellation.h"
#include <string>


/* Filtros por Hemisferio */
bool isNorth(Constellation constellation)
{
    return constellation._hemisferio == 'N';
}

bool isWest(Constellation constellation)
{
    return constellation._hemisferio == 'O';
}

bool isEast(Constellation constellation)
{
    return constellation._hemisferio == 'L';
}

bool isSouth(Constellation constellation)
{
    return constellation._hemisferio == 'S';
}