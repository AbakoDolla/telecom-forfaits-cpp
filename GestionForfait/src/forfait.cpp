#include "../include/forfait.h"
#include <iostream>
using namespace std;

Forfait::Forfait(string nom, double prixMensuel, int donneesMobiles, bool appelsIllimites, bool smsIllimites)
{
    this->nom = nom;
    this->prixMensuel = prixMensuel;
    this->donneesMobiles = donneesMobiles;
    this->appelsIllimites = appelsIllimites ? 1 : 0;
    this->smsIllimites = smsIllimites ? 1 : 0;
}

Forfait::~Forfait()
{
}

string Forfait::getNom() const
{
    return nom;
}

double Forfait::getPrixMensuel() const
{
    return prixMensuel;
}

int Forfait::getDonneesMobiles() const
{
    return donneesMobiles;
}

bool Forfait::getAppelsIllimites() const
{
    return appelsIllimites == 1;
}

bool Forfait::getSmsIllimites() const
{
    return smsIllimites == 1;
}

void Forfait::setNom(string nom)
{
    this->nom = nom;
}

void Forfait::setPrixMensuel(double prix)
{
    this->prixMensuel = prix;
}

void Forfait::setDonneesMobiles(int donnees)
{
    this->donneesMobiles = donnees;
}

void Forfait::setAppelsIllimites(bool illimites)
{
    this->appelsIllimites = illimites ? 1 : 0;
}

void Forfait::setSmsIllimites(bool illimites)
{
    this->smsIllimites = illimites ? 1 : 0;
}

void Forfait::afficherDetails() const
{
    cout << "\n";
    cout << "==================================================" << endl;
    cout << "               FORFAIT INFO                       " << endl;
    cout << "                                                 " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "  Nom: " << nom << "                              " << endl;
    cout << "  Prix mensuel: " << prixMensuel << " Fcfa          " << endl;
    cout << "  Donnees mobiles: " << donneesMobiles << " MB   " << endl;
    cout << "  Appels illimites: " << (appelsIllimites ? "Oui" : "Non") << "" << endl;
    cout << "  SMS illimites: " << (smsIllimites ? "Oui" : "Non") << "" << endl;
    cout << "                                                   " << endl;
    cout << "---------------------------------------------------" << endl;
}

string Forfait::getType() const
{
    return "Standard";
}
