#include<iostream>
#include "GestionForfait/include/client.h"

int main()
{
    std::cout <<"=============================================================" << std::endl;
    std::cout <<"           SYTEME DE FORFAITS TELEPHONIQUES                  " << std::endl;
    std::cout <<"=============================================================" << std::endl;

    Client client1("Evans", "abah", "mbankomo", "690 00 00 00");
    client1.afficherInfos();

    return 0;
}