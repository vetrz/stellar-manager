#include "../include/constellationFilters.h"
#include "../include/constellation.h"
#include "../include/vetor.h"
#include <iostream>
#include <string>

int subChoice()
{
    int sub_choice;
    std::cout << "\n1 - salvar e continuar, 2 - descartar e voltar: ";
    std::cin >> sub_choice;

    return sub_choice;
}

void inicio(Vetor& data) 
{
    bool running = true;
    int total_size = data._size;

    while (running) 
    {
        int choice;
        std::cout << "\n1: filtro, 2: adicionar, 3: remover, 4: mostrar, 0: sair: ";
        std::cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                Vetor filtered = data.filter(isNorth);
                filtered.show();

                if (subChoice() == 1) {
                    data = filtered;
                }
                break;
            }
            case 2: 
            {
                total_size +=1;
                data.push(addConstellationFromInput(total_size));
                data.show();

                if (subChoice() == 2) {
                    data.pop();
                    total_size -=1;
                }
                break;
            }
            case 3: 
            {
                int id;
                std::cout << "digite o numero de id que deseja remover: " << std::endl;
                std::cin >> id;

                Vetor removed = data;
                removed.remove(id-1);

                removed.show();

                if (subChoice() == 1) {
                    data = removed;
                }
                break;
            }
            case 4: 
            {
                data.show();
                break;
            }

            default:
                running = false;
                break;
        }
    }
}

int main()
{
    Vetor df;
    Constellation c1,c2,c3,c4,c5;
    c1 = addConstellation(1,"Cruzeiro do Sul",1589,321.0,'S',"Guia de navegantes");
    c2 = addConstellation(2,"Ursa Maior",150,80.0,'N',"Ninfa Calisto transformada");
    c3 = addConstellation(3,"Orion",150,773.0,'O',"Gigante Cacador");
    c4 = addConstellation(4,"Centauro",150,4.37,'S',"Quiron o mestre sabio");
    c5 = addConstellation(5,"Cassiopeia",150,54.0,'N',"Rainha vaidosa punida");

    df.push(c1);
    df.push(c2);
    df.push(c3);
    df.push(c4);
    df.push(c5);

    df.show();

    inicio(df);

    std::cout << "TERMINOU" << std::endl;

    df.show();

    return 0;
}