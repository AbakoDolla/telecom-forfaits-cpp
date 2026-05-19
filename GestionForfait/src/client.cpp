#include "../include/client.h"
#include <iostream>
using namespace std;

/*constructeur vide*/

Client::Client()
{
    nom = "";
    prenom = "";
    numeroTelephone = "";
    forfaitActuel = nullptr;
}

/*constructeur avec parametres*/

Client::Client(string nom, string prenom, string numeroTelephone)
{
    this->nom = nom;
    this->prenom = prenom;
    this->numeroTelephone = numeroTelephone;
    this->forfaitActuel = nullptr;
}

/*constructeur avec forfait*/

Client::Client(string nom, string prenom, string numeroTelephone, Forfait* forfait)
{
    this->nom = nom;
    this->prenom = prenom;
    this->numeroTelephone = numeroTelephone;
    this->forfaitActuel = forfait;
}

/*destructeur*/

Client::~Client()
{
    // Note: We don't delete forfaitActuel here as it's managed by the Operateur
}

/*getters*/

string Client::getNom()
{
    return nom;
}

string Client::getPrenom()
{
    return prenom;
}

string Client::getNumeroTelephone()
{
    return numeroTelephone;
}

Forfait* Client::getForfaitActuel()
{
    return forfaitActuel;
}

/*setters*/

void Client::setNom(string nom)
{
    this->nom = nom;
}

void Client::setPrenom(string prenom)
{
    this->prenom = prenom;
}

void Client::setNumeroTelephone(string numero)
{
    this->numeroTelephone = numero;
}

void Client::setForfaitActuel(Forfait* forfait)
{
    this->forfaitActuel = forfait;
}

/*afficher les informations du client*/

void Client::afficherInfos()
{
     cout << "\n";
    cout << "╔═════════════════════════════════════════════════╗" << endl;
    cout << "║               👤CLIENT INFO                     ║" << endl;
    cout << "║                                                 ║" << endl;
    cout << "╠═════════════════════════════════════════════════╣" << endl;
    cout << "║  Nom: " << nom << "                             ║" << endl;
    cout << "║  Prenom: " << prenom << "                       ║" << endl;
    cout << "║  Numero de telephone: " << numeroTelephone << " ║" << endl;
    
    if (forfaitActuel != nullptr)
    {
        cout << "║  Forfait: " << forfaitActuel->getNom() << " (" << forfaitActuel->getType() << ")" << endl;
        cout << "║  Prix: " << forfaitActuel->getPrixMensuel() << " €/mois" << endl;
    }
    else
    {
        cout << "║  Forfait: Aucun                              ║" << endl;
    }
    
    cout << "║                                                 ║" << endl;
    cout << "╚═════════════════════════════════════════════════╝" << endl;
    cout << "Taper n'importe quelle touche pour revenir au menu principal..." << endl;
    cin.get();
}