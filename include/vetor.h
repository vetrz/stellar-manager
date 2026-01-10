#ifndef VETOR_H
#define VETOR_H

#include "client.h"

struct Vetor
{
    int _size;
    int _capacity;
    Client* _data;
    
    Vetor();

    ~Vetor();

    int size();

    int capacity();

    Client& operator[](int index);

    void show();

    void push(Client client);

    void pop();

    void remove(int index);

    void _reserve(int capacity);

};

#endif // VETOR_H