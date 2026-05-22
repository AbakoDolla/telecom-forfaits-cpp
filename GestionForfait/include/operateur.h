#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <string>
#include <vector>
#include "forfait.h"
#include "forfaitillimite.h"

class Operateur
{
    private:
        std::string nom;
        std::string pays;
        std::vector<Forfait*> forfaitsDisponibles;

    public:
        Operateur(std::string nom, std::string pays);
        ~Operateur();

        std::string getNom() const;
        std::string getPays() const;
        const std::vector<Forfait*>& getForfaitsDisponibles() const;

        void setNom(std::string nom);
        void setPays(std::string pays);

        void ajouterForfait(Forfait* forfait);
        void supprimerForfait(int index);
        void afficherForfaits() const;
        void afficherInfos() const;
};

#endif
