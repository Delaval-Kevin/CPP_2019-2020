/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 13/11/2019             */
/***********************************************************/

#ifndef LISTEBASE_H
#define LISTEBASE_H

#include <iostream>
#include "Ecran.h"


using namespace std;

template<class T> struct Cellule
{
	T valeur;
	struct Cellule<T> *suivant;
};


template <class T> class Iterateur;


template <class T> class ListeBase
{	
	
	friend class Iterateur<T>;

	protected:
		struct Cellule<T> *pTete;
		
	public:
		//constructeurs
		ListeBase(void);
		ListeBase(const ListeBase& LB);
		//destructeur
		virtual ~ListeBase();
				
		//operators
		const ListeBase<T>& operator=(const ListeBase& LB);
		//getters
		int getNombreElements() const;
		struct Cellule<T>* getTete() const;
		
		//setters
		void setTete(struct Cellule<T> *Tete);
		
		//methodes
		bool estVide() const;
		void Affiche() const;
		void virtual insere(const T &val) = 0;

};

#endif //LISTEBASE_H
