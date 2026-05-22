#include "../include/prepayee.h"
#include <iostream>
using namespace std;

Prepayee::Prepayee(string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites, int credits, bool valide)
    : Forfait(nom, prixMensuel, donneesMobiles, appelsIllimites, smsIllimites)
{
    this->credits = credits;
    this->valide = valide;
}

Prepayee::~Prepayee()
{
}

int Prepayee::getCredits() const
{
    return credits;
}

bool Prepayee::isValide() const
{
    return valide;
}

void Prepayee::setCredits(int credits)
{
    this->credits = credits;
}

void Prepayee::setValide(bool valide)
{
    this->valide = valide;
}

void Prepayee::afficherDetails() const
{
    cout << "\n";
    cout << "===================================================" << endl;
    cout << "               FORFAIT PRÉPAYÉ INFO                " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "|  Nom: " << nom << "                             |" << endl;
    cout << "|  Prix mensuel: " << prixMensuel << " Fcfa          |" << endl;
    cout << "|  Donnees mobiles: " << donneesMobiles << " MB   |" << endl;
    cout << "|  Credits restants: " << credits << "                     |" << endl;
    cout << "|  Forfait valide: " << (valide ? "Oui" : "Non") << "|" << endl;
    cout << "|                                                |" << endl;
    cout << "===================================================" << endl;
}

string Prepayee::getType() const
{
    return "Prepayé";
}
