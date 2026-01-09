# Utilizando pra facilitar a compilação do Projeto Teste

#!/bin/bash
g++ test/test.cpp src/client.cpp src/vetor.cpp -o build/main_test
./build/main_test
