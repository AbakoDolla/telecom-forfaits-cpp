#ifndef FORFAITILLIMITE_H
#define FORFAITILLIMITE_H

#include "forfait.h"

class ForfaitIllimite : public Forfait
{
    private:
        int donneesBonus; // Donnees supplementaires en MB
        bool roamingInternational;

    public:
        ForfaitIllimite(std::string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites, int donneesBonus, bool roamingInternational);
        ~ForfaitIllimite();

        int getDonneesBonus();
        bool getRoamingInternational();

        void setDonneesBonus(int bonus);
        void setRoamingInternational(bool roaming);

        void afficherDetails() override;
        std::string getType() override;
};

#endif
