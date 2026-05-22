#include "../include/operateur.h"
#include <iostream>
using namespace std;

Operateur::Operateur(string nom, string pays)
{
    this->nom = nom;
    this->pays = pays;
}

Operateur::~Operateur()
{
    for (Forfait* forfait : forfaitsDisponibles)
    {
        delete forfait;
    }
}

string Operateur::getNom() const
{
    return nom;
}

string Operateur::getPays() const
{
    return pays;
}

const vector<Forfait*>& Operateur::getForfaitsDisponibles() const
{
    return forfaitsDisponibles;
}

void Operateur::setNom(string nom)
{
    this->nom = nom;
}

void Operateur::setPays(string pays)
{
    this->pays = pays;
}

void Operateur::ajouterForfait(Forfait* forfait)
{
    forfaitsDisponibles.push_back(forfait);
}

void Operateur::supprimerForfait(int index)
{
    if (index >= 0 && index < forfaitsDisponibles.size())
    {
        delete forfaitsDisponibles[index];
        forfaitsDisponibles.erase(forfaitsDisponibles.begin() + index);
    }
}

void Operateur::afficherForfaits() const
{
    cout << "\n";
    cout << "===================================================" << endl;
    cout << "               FORFAITS DISPONIBLES                " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    
    if (forfaitsDisponibles.empty())
    {
        cout << "║  Aucun forfait disponible                    ║" << endl;
    }
    else
    {
        for (size_t i = 0; i < forfaitsDisponibles.size(); i++)
        {
            cout << "║  " << (i + 1) << ". " << forfaitsDisponibles[i]->getNom() 
                 << " - " << forfaitsDisponibles[i]->getPrixMensuel() << " FCFA/mois" << endl;
        }
    }
    
    cout << "|                                                |" << endl;
    cout << "===================================================" << endl;
}

void Operateur::afficherInfos() const
{
    cout << "\n";
    cout << "==================================================" << endl;
    cout << "               OPERATEUR INFO                     " << endl;
    cout << "                                                  " << endl;
    cout << "===================================================" << endl;
    cout << "|  Nom: " << nom << "                             " << endl;
    cout << "|  Pays: " << pays << "                           " << endl;
    cout << "|  Nombre de forfaits: " << forfaitsDisponibles.size() << "                    " << endl;
    cout << "===================================================" << endl;
}
