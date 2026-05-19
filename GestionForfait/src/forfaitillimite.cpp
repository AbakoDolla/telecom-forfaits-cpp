#include "../include/forfaitillimite.h"
#include <iostream>
using namespace std;

ForfaitIllimite::ForfaitIllimite(string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites, int donneesBonus, bool roamingInternational)
    : Forfait(nom, prixMensuel, donneesMobiles, appelsIllimites, smsIllimites)
{
    this->donneesBonus = donneesBonus;
    this->roamingInternational = roamingInternational;
}

ForfaitIllimite::~ForfaitIllimite()
{
}

int ForfaitIllimite::getDonneesBonus()
{
    return donneesBonus;
}

bool ForfaitIllimite::getRoamingInternational()
{
    return roamingInternational;
}

void ForfaitIllimite::setDonneesBonus(int bonus)
{
    this->donneesBonus = bonus;
}

void ForfaitIllimite::setRoamingInternational(bool roaming)
{
    this->roamingInternational = roaming;
}

void ForfaitIllimite::afficherDetails()
{
    cout << "\n";
    cout << "╔═════════════════════════════════════════════════╗" << endl;
    cout << "║           📦 FORFAIT ILLIMITE INFO               ║" << endl;
    cout << "║                                                 ║" << endl;
    cout << "╠═════════════════════════════════════════════════╣" << endl;
    cout << "║  Nom: " << nom << "                             ║" << endl;
    cout << "║  Prix mensuel: " << prixMensuel << " €          ║" << endl;
    cout << "║  Donnees mobiles: " << donneesMobiles << " MB   ║" << endl;
    cout << "║  Donnees bonus: " << donneesBonus << " MB       ║" << endl;
    cout << "║  Appels illimites: " << (appelsIllimites ? "Oui" : "Non") << "                    ║" << endl;
    cout << "║  SMS illimites: " << (smsIllimites ? "Oui" : "Non") << "                       ║" << endl;
    cout << "║  Roaming international: " << (roamingInternational ? "Oui" : "Non") << "              ║" << endl;
    cout << "║                                                 ║" << endl;
    cout << "╚═════════════════════════════════════════════════╝" << endl;
}

string ForfaitIllimite::getType()
{
    return "Illimite";
}
