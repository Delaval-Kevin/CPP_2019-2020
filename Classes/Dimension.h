/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 11/10/2019             */
/***********************************************************/

#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>
#include "Ecran.h"

using namespace std;

class Dimension{

		//fonctions amies
		friend ostream& operator<<(ostream& s, const Dimension& d);
		friend istream& operator>>(istream& s, Dimension& d);
		
	private:
		int largeur;
		int hauteur;
	
	public:
		//constructeurs
		Dimension(void);
		Dimension(int larg,int haut);
		Dimension(const Dimension& d);
		
		//operators
		bool operator==(const Dimension& d);
		bool operator!=(const Dimension& d);

		//getters
		int getLargeur() const;
		int getHauteur() const;

		//setters
		void setLargeur(int larg);
		void setHauteur(int haut);
		
		//méthodes
		void Affiche() const;	
		
		//variables membres statique
		static const Dimension VGA;
		static const Dimension HD;
		static const Dimension FULL_HD;
};



#endif //DIMENSION_H
