/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : User Interface                             */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/11/2019             */
/***********************************************************/

#ifndef UI_H
#define UI_H

#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "Moteur.h"
#include "Couleur.h"

#define FICHIER "sauvegarde.dat"


using namespace std;

class UI{
		
	private:
		Moteur *moteur;
		
	public:
		//constructeurs
		UI(void);
		UI(Moteur *Mot);
		UI(const UI& ui);
		//destructeur
		~UI();	
		//operators

		//getters

		//setters
		
		//méthodes
		void Menu();
		void Start();
		int LireNombre(int *pN, int min, int max);

};

#endif //UI_H
