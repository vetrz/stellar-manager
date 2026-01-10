# Utilizando pra facilitar a compilação do Projeto Teste

#!/bin/bash
g++ test/test.cpp src/constellation.cpp src/vetor.cpp src/dataLoader.cpp -o build/main_test
./build/main_test
