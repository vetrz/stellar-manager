# Utilizando pra facilitar a compilação do Projeto

#!/bin/bash
g++ src/main.cpp src/constellation.cpp src/vetor.cpp src/dataLoader.cpp src/constellationFilters.cpp -o build/main
./build/main