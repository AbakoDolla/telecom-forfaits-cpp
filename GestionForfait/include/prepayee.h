#ifndef PREPAYEE_H
#define PREPAYEE_H

#include "forfait.h"

class Prepayee : public Forfait
{
    private:
        int credits;
        bool valide;

    public:
        Prepayee(std::string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites, int credits, bool valide);
        ~Prepayee();

        int getCredits() const;
        bool isValide() const;

        void setCredits(int credits);
        void setValide(bool valide);

        void afficherDetails() const override;
        std::string getType() const override;
};

#endif
