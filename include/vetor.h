#ifndef VETOR_H
#define VETOR_H

#include "constellation.h"

struct Vetor
{
    int _size;
    int _capacity;
    Constellation* _data;
    
    Vetor();

    Vetor(const Vetor& other); 

    ~Vetor();

    Vetor& operator=(const Vetor& other);

    int size();

    int capacity();

    Constellation& operator[](int index);

    void show();

    void push(Constellation constellation);

    void pop();

    void remove(int index);

    void _reserve(int capacity);

    Vetor filter(bool (*rule)(Constellation));
};

#endif // VETOR_H