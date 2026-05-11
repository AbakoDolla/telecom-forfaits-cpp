#include "../include/client.h"
#include <iostream>

Client::Client(std::string nom, std::string prenom, std::string adresse, std::string numeroTelephone)
{
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->numeroTelephone = numeroTelephone;
}

void Client::afficherInfos()
{
    std::cout << "=============================================================" << std::endl;
    std::cout <<"                      CLIENT INFO                             " << std::endl;
    std::cout << "=============================================================" << std::endl;

    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Prenom: " << prenom << std::endl;
    std::cout << "Adresse: " << adresse << std::endl;
    std::cout << "Numero de telephone: " << numeroTelephone << std::endl;

    std::cout << "=============================================================" << std::endl;
}