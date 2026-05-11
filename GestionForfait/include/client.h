#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
    private:
        std::string nom;
        std::string prenom;
        std::string adresse;
        std::string numeroTelephone;

    public:
        Client(std::string nom, std::string prenom, std::string adresse, std::string numeroTelephone);
        std::string getNom();
        std::string getPrenom();
        std::string getAdresse();
        std::string getNumeroTelephone();

    void afficherInfos();
};

#endif