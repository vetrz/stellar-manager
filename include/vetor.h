#ifndef VETOR_H
#define VETOR_H

#include "constellation.h"

struct Vetor
{
    int _size;
    int _capacity;
    Constellation* _data;
    
    Vetor();

    ~Vetor();

    int size();

    int capacity();

    Constellation& operator[](int index);

    void show();

    void push(Constellation constellation);

    void pop();

    void remove(int index);

    void _reserve(int capacity);

};

#endif // VETOR_H