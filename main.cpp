#include <iostream>
#include <vector>
#include <string>
#include "GestionForfait/include/client.h"
#include "GestionForfait/include/operateur.h"
#include "GestionForfait/include/forfait.h"
#include "GestionForfait/include/forfaitillimite.h"
#include "GestionForfait/include/prepayee.h"
#include "GestionForfait/src/client.cpp"
#include "GestionForfait/src/operateur.cpp"
#include "GestionForfait/src/forfait.cpp"
#include "GestionForfait/src/forfaitillimite.cpp"
#include "GestionForfait/src/prepayee.cpp"

using namespace std;

vector<Client> clients; // stockage des clients
Operateur* operateur = nullptr; // operateur telecom

void afficherMenu()
{
    cout << "\n";
    cout << "====================================" << endl;
    cout << "   SYSTEME FORFAITS TELECOM         " << endl;
    cout << "        (SIMULATION)                " << endl;
    cout << "------------------------------------" << endl;
    cout << " 1. Ajouter un client               " << endl;
    cout << " 2. Souscrire un forfait            " << endl;
    cout << " 3. Afficher les clients            " << endl;
    cout << " 4. Afficher les forfaits           " << endl;
    cout << " 5. Afficher operateur              " << endl;
    cout << " 6. Quitter                         " << endl;
    cout << "====================================" << endl;
    cout << "=> Choisis une option : ";
}

void initialiserOperateur()
{
    operateur = new Operateur("TelecomPlus", "Cameroun" );
    
    // Ajouter des forfaits standards
    operateur->ajouterForfait(new Forfait("Basic", 999, 10000, false, false));
    operateur->ajouterForfait(new Forfait("Standard", 1999, 5000, true, false));
    operateur->ajouterForfait(new Forfait("Premium", 2999, 10000, true, true));
    
    // Ajouter des forfaits illimités
    operateur->ajouterForfait(new ForfaitIllimite("Illimite Start", 3999, 20000, true, true, 5000, false));
    operateur->ajouterForfait(new ForfaitIllimite("Illimite Pro", 5999, 50000, true, true, 10000, true));
    operateur->ajouterForfait(new ForfaitIllimite("Illimite Gold", 7999, 100000, true, true, 20000, true));

    // Ajouter un forfait prépayé optionnel
    operateur->ajouterForfait(new Prepayee("Prepayé Découverte", 0.0, 1500, false, false, 5000, true));
}

void ajouterClient()
{
    string nom, prenom, numero;

    cout << "\n AJOUT CLIENT" << endl;
    cout << "Nom client : ";
    getline(cin >> ws, nom);

    cout << "Prenom client : ";
    getline(cin >> ws, prenom);

    cout << "Numero : ";
    getline(cin >> ws, numero);

    Client c(nom, prenom, numero);
    clients.push_back(c);

    cout << "Client ajoute !" << endl;
}

void souscrireForfait()
{
    if (clients.empty())
    {
        cout << "Aucun client disponible. Ajoutez d'abord un client." << endl;
        return;
    }

    cout << "\nSOUSCRIPTION FORFAIT" << endl;
    cout << "Liste des clients :" << endl;
    for (size_t i = 0; i < clients.size(); i++)
    {
        cout << "  " << (i + 1) << ". " << clients[i].getNom() << " " << clients[i].getPrenom()
             << " (" << clients[i].getNumeroTelephone() << ")" << endl;
    }

    int choixClient;
    cout << "Choisissez un client (1-" << clients.size() << ") : ";
    cin >> choixClient;

    if (choixClient < 1 || choixClient > clients.size())
    {
        cout << "Choix invalide" << endl;
        return;
    }

    operateur->afficherForfaits();

    int choixForfait;
    cout << "Choisissez un forfait (1-" << operateur->getForfaitsDisponibles().size() << ") : ";
    cin >> choixForfait;

    if (choixForfait < 1 || choixForfait > operateur->getForfaitsDisponibles().size())
    {
        cout << "Choix invalide" << endl;
        return;
    }

    clients[choixClient - 1].setForfaitActuel(operateur->getForfaitsDisponibles()[choixForfait - 1]);
    cout << "Forfait souscrit avec succes !" << endl;
}

void afficherClients()
{
    if (clients.empty())
    {
        cout << "Aucun client disponible." << endl;
        return;
    }

    cout << "\n📋 LISTE CLIENTS" << endl;
    for (size_t i = 0; i < clients.size(); i++)
    {
        clients[i].afficherInfos();
    }
}

void afficherForfaits()
{
    operateur->afficherForfaits();
    
    int choix;
    cout << "\nVoir les details d'un forfait ? (1=Oui, 0=Non) : ";
    cin >> choix;
    
    if (choix == 1)
    {
        int index;
        cout << "Numero du forfait : ";
        cin >> index;
        
        if (index >= 1 && index <= operateur->getForfaitsDisponibles().size())
        {
            operateur->getForfaitsDisponibles()[index - 1]->afficherDetails();
        }
        else
        {
            cout << "Choix invalide" << endl;
        }
    }
}

int main()
{
    int choix;

    initialiserOperateur();

    do {
        afficherMenu();
        cin >> choix;

        switch (choix)
        {
            case 1:
                ajouterClient();
                break;
            case 2:
                souscrireForfait();
                break;
            case 3:
                afficherClients();
                break;
            case 4:
                afficherForfaits();
                break;
            case 5:
                operateur->afficherInfos();
                break;
            case 6:
                cout << "Fermeture..." << endl;
                break;
            default:
                cout << "❌ Choix invalide" << endl;
        }

    } while (choix != 6);

    delete operateur;
    return 0;
}
