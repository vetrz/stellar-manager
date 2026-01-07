#include <iostream>
#include "../include/client.h"

int main(){
    int len = 2;

    Client* df = new Client [len] {
        {29,"jorge",true},
        {16,"laura",false},
    };
    
    imprimirArray(len, df);

    std::cout << std::endl;

    int len_new = 4;
    
    Client* temp = novoTamanho(len_new, len, df);
    delete[] df;
    df = temp;

    imprimirArray(len_new, df);

    return 0;
}