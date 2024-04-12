#include "BaseClients.h"
#include <iostream>
#include <fstream>
#include <vector>

int BaseClient::baseclients_authentifier(int num_carte)
{
    std::ifstream fichier("yuba.txt"); // Ouvre le fichier yuba.txt en mode lecture

    if (fichier.is_open()) {
        std::vector<int> valeurs; // Vecteur pour stocker les valeurs lues

        int valeur;
        while (fichier >> valeur) { // Lecture des valeurs du fichier
            valeurs.push_back(valeur); // 
        }

        fichier.close(); // Ferme le fichier

       
        for (int val : valeurs) {
            if (num_carte == val) {
                return 1; // Carte trouvée
            }
        }

        return 0; // Carte non trouvée
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return -1; // Erreur lors de l'ouverture du fichier
    }
}
