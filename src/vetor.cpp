#include "../include/constellation.h"
#include "../include//vetor.h"
#include <iostream>

/* Implementação do Construtor */
Vetor::Vetor() 
{
    _size = 0;
    _capacity = 5;
    _data = new Constellation[_capacity];
}

/* Implementação do Destrutor */
Vetor::~Vetor() 
{
    delete[] _data;
}

/* retorna o valor do tamanho do Vetor */
int Vetor::size()
{
    return _size;
} 

/* retorna o valor da capacidade do Vetor */
int Vetor::capacity()
{
    return _capacity;
}

/* Implementação do Operador [] */
Constellation& Vetor::operator[](int index) 
{
    return _data[index];
}

/* Mostra os elemenetos do Vetor */
void Vetor::show()
{
    for (int i=0; i < _size; i++)
        std::cout << "| " << _data[i] << " |" <<  std::endl;
}

/* Adiciona elemenentos ao Vetor sequencialmente */
void Vetor::push(Constellation constellation)
{
    if (_size == _capacity){
        _reserve(_capacity + 5);
    }

    if (_size < _capacity){
        _data[_size] = constellation;
        _size +=1;
    }
}

/* Remover o ultimo item do Vetor */
void Vetor::pop()
{
    if (_size > 0 ){
        _size -=1;
    }
}

/* Remover o item com index desejado */
void Vetor::remove(int index)
{
    if (index < 0 || index >=_size){
        std::cerr << "indice invalido" << std::endl;
        return;
    }
    
    for (int i = index; i < _size - 1; i++){
        _data[i] = _data[i+1];
    }

    _size -=1;

}

/* Muda a capacidade do vetor alocando um novo espaço de memoria para _data*/
void Vetor::_reserve(int capacity)
{
    Constellation* temp = new Constellation[capacity];

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
