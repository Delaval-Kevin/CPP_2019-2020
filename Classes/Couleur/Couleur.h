/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#ifndef COULEUR_H
#define COULEUR_H


#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "RGBException.h"

using namespace std;

class Couleur
{	
		
		//fonctions amies
		friend ostream& operator<<(ostream& s, const Couleur& c);
		friend istream& operator>>(istream& s, Couleur& c);
		
	private:
		int rouge;
		int vert;
		int bleu;
		
	public:
		//constructeurs
		Couleur(void);
		Couleur(int rTmp, int vTmp, int bTmp);
		Couleur(const Couleur& c);

		//operators
		const Couleur& operator=(const Couleur& c);
		
		//getters
		int getRouge() const;
		int getVert() const;
		int getBleu() const;
		
		//setters
		void setRouge(int rTmp);
		void setVert(int vTmp);
		void setBleu(int bTmp);
		
		//méthodes
		void Affiche() const;
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		
		//variables membres statique
		static const Couleur ROUGE;
		static const Couleur VERT;
		static const Couleur BLEU;
		static const Couleur BLANC;
		static const Couleur NOIR;
};

#endif //COULEUR_H
