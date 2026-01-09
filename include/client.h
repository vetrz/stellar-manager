#ifndef CLIENT_H
#define CLIENT_H
#include <string>

struct Client
{
    int _id = 0;
    int _idade = 0;
    std::string _nome = "";
    bool _isActivate = false;


    bool operator==(const Client& outro) const 
    {
        /* Define o critério de igualdade */
        return (this->_id == outro._id);
    }

};

std::ostream& operator<<(std::ostream& os, const Client& c);

Client adicionarClient(Client client, int _id);

#endif // CLIENT_H