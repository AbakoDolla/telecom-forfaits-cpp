#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "forfait.h"

class Client
{
    private:
        std::string nom;
        std::string prenom;
        std::string numeroTelephone;
        Forfait* forfaitActuel;

    /*constructeur pour initialiser les attributs du client*/

    public:
        Client(std::string nom, std::string prenom, std::string numeroTelephone);
        Client(std::string nom, std::string prenom, std::string numeroTelephone, Forfait* forfait);
        ~Client();
        
        std::string getNom();
        std::string getPrenom();
        std::string getNumeroTelephone();
        Forfait* getForfaitActuel();

        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setNumeroTelephone(std::string numero);
        void setForfaitActuel(Forfait* forfait);

/*methode pour afficher les informations du client*/

    void afficherInfos();
};

#endif