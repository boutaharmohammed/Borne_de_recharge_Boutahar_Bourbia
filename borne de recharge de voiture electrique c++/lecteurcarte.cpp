
#include "lecteurcarte.h"
#include <iostream>
#include <lcarte.h>
#include "BaseClients.h"
#include "voyants.h"
#include "recharge.h"
#include <fstream> // Bibliothèque pour gérer les fichiers


using namespace std;
int A;

 //BaseClient BaseClient;
void LecteurCarte::initialiser()
{
  
  initialisations_ports();
}

void LecteurCarte::lire_carte()
{
          BaseClient BaseClient;
		  voyants voyants ;
          recharge recharge;
          std::string password ;
          std::string passe="passe";
           std::string Mot;
           ;
          int Mode;
            std::cout<<"inserer votre carte :"<<std::endl;
             std::cout<<"tapez numero de mode choisis :"<<std::endl;
             std::cout<<"1==> administrateur\n2==> Client:"<<std::endl;  
              std :: cin >> Mode ;
            
            
            if(Mode==1)
            { 
           
           std :: string mot ;
				
				do {
				std::cout << "Entrez le mot de passe : ";
				std :: cin >> mot ;
				
				if (mot == passe)
				 {
				std::cout << "Mot de passe correct. Accès autorisé." << std :: endl;
				
				break; //pour Sortir de la boucle une fois que le mot de passe est correct
				} 
				else
				 {
				  std::cout << "Mot de passe incorrect. Réessayez." << std :: endl;
				
				 }
				} while (true); // Continue dans la boucle indéfiniment jusqu'à ce que le mot de passe soit correct
				
				
              
              
               // Création d'un objet pour écrire dans le fichier
             std::ofstream fichier("yuba.txt", std::ios::app); // Ouverture du fichier en mode ajout

          		if (fichier.is_open()) {
          		int valeur;
		
          		std::cout << "Veuillez saisir une valeur (entrez 00 pour arrêter) : ";
           		while (std::cin >> valeur && valeur != 00)
           		{
            		fichier << valeur << std::endl; // Écriture de la valeur dans le fichier
             		std::cout << "Valeur enregistrée. Entrez une autre valeur (00 pour arrêter) : ";
        		}
		
        		fichier.close(); // Fermeture du fichier
        		std::cout << "Les valeurs ont été enregistrées dans le fichier avec succès." << std::endl;
    		} else {
        		std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
               }
            
            
            
              
            
            
            }
            
                          
             attente_insertion_carte();
	   int numero = lecture_numero_carte();
	   std::cout<<"Numéro de la carte :"<< numero <<std::endl;
	  
           int 	autontification = BaseClient.baseclients_authentifier(numero);
           // std::cout<<"status :"<< autontification <<std::endl;
        if(autontification ==1)
		{ std::cout<<"choisir un mot de passe :"<<std::endl;
	  	   std :: cin >> password ;
		  std::cout<<"authentification reussite:"<<std::endl;
          voyants.init();
          voyants.clignoteCharge(VERT);
          //voyants.Recharge();
          A= recharge.Recharge();
          //std::cout<<"A==== :"<< A <<std::endl;
          if(A==1)
          {
          recharge.charge();
          
          		
          		
				std :: string input ;
				
				do {
				std::cout << "Entrez le mot de passe que vous avez choisis : ";
				std :: cin >> input ;
				
				if (input == password)
				 {
				std::cout << "Mot de passe correct. Accès autorisé." << std :: endl;
				recharge.recup();
				break; // Sort de la boucle une fois que le mot de passe est correct
				} 
				else
				 {
				  std::cout << "Mot de passe incorrect. Réessayez." << std :: endl;
				
				 }
				} while (true); // Continuer la boucle indéfiniment jusqu'à ce que le mot de passe soit correct
				
				
				
          
		}
		if(A==2)
              { 
                   std::cout<<"Penser a appuyer sur le Button charge:"<<std::endl;
                 
               }
		}
        else
            { 
                   std::cout<<"ta carte existe pas sur la BDD:"<<std::endl;
                   voyants.init();
                   voyants.clignoteDefault(ROUGE);
				   voyants.allumerDispo(VERT);
				   
                    
               }
               
               
       attente_retrait_carte();
	   liberation_ports();
 }
