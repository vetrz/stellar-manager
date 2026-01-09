#include "../include/client.h"
#include "../include//vetor.h"
#include <iostream>

/* Implementação do Construtor */
Vetor::Vetor() 
{
    _size = 0;
    _capacity = 5;
    _data = new Client[_capacity];
}

/* Implementação do Destrutor */
Vetor::~Vetor() 
{
    delete[] _data;
}

/* Implementação do Operador [] */
Client& Vetor::operator[](int index) 
{
    return _data[index];
}

/* Função pra mostrar os elemenetos do Vetor*/
void Vetor::show()
{
    for (int i=0; i < this->_size; i++)
        std::cout << "| " << this->_data[i] << " |" <<  std::endl;
}

void Vetor::push(Client client)
{
    if (_size == _capacity){
        _reserve(_capacity + 5);
    }

    if (_size < _capacity){
        _data[_size] = client;
        _size +=1;
    }
}

void Vetor::pop()
{
    if (_size > 0 ){
        _size -=1;
    }
}

void Vetor::_reserve(int capacity)
{
    Client* temp = new Client[capacity];

    if(capacity < _size){
        _size = capacity;
    }
        
    for (int i = 0; i < _size; i++){
        temp[i] = _data[i];
    }

    delete [] _data;
    _data = temp;
    _capacity = capacity;
}
