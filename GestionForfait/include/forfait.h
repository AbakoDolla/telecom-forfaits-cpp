#ifndef FORFAIT_H
#define FORFAIT_H

#include <string>

class Forfait
{
    protected:
        std::string nom;
        double prixMensuel;
        int donneesMobiles; // en MB
        int appelsIllimites;
        int smsIllimites;

    public:
        Forfait(std::string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites);
        virtual ~Forfait();

        std::string getNom();
        double getPrixMensuel();
        int getDonneesMobiles();
        bool getAppelsIllimites();
        bool getSmsIllimites();

        void setNom(std::string nom);
        void setPrixMensuel(double prix);
        void setDonneesMobiles(int donnees);
        void setAppelsIllimites(bool illimites);
        void setSmsIllimites(bool illimites);

        virtual void afficherDetails();
        virtual std::string getType();
};

#endif
