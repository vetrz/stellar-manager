#ifndef VETOR_HPP
#define VETOR_HPP

#include "models/constellation.hpp"

namespace stellar 
{
    struct Vetor
    {
        private:
            int _size;
            int _capacity;
            Constellation* _data;

            void _reserve(int capacity);
        
        public:
            Vetor();
            Vetor(const Vetor& other); 
            ~Vetor();

            Vetor& operator=(const Vetor& other);

            int size() const;
            int capacity() const;

            Constellation& operator[](int index);

            void show();
            void push(Constellation constellation);
            void pop();
            void remove(int index);

            Vetor filter(bool (*rule)(Constellation));
    };
}



#endif // VETOR_HPP