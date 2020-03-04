/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 24/10/2019             */
/***********************************************************/

#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include "Ecran.h"
#include "XYException.h"


using namespace std;

template <class T> class Matrice {	
		
	private:
		T** tab;
		int largeur;
		int hauteur;
		
		//methode privée
		void CreeTab(int h, int l);		/* Car je ne veux pas qu'un utilisateur de la         */
		void setLargeurConstruct(int l);	/* classe puisse crée un matrice de taille différente */
		void setHauteurConstruct(int h);	/* que celle de la hauteur et largeur encodée         */
		
	public:
		//constructeurs
		Matrice(void);
		Matrice(int l, int h);
		Matrice(int l, int h, const T& val);
		Matrice(const Matrice& m);
		//destructeur
		~Matrice();
		
		//operators
		const Matrice<T>& operator=(const Matrice& m);
		T operator()(int x, int y) const;
		T& operator()(int x, int y);
		
		//getters
		int getLargeur() const;
		int getHauteur() const;
		T getValeur(int x, int y) const;
		
		//setters
		void setLargeur(int l);
		void setHauteur(int h);
		void setValeur(int x, int y, const T& val);

		//methodes
		void Affiche() const;
		
};

#endif //MATRICE_H
