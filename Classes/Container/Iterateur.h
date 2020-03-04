/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 14/11/2019             */
/***********************************************************/

#ifndef ITERATEUR_H
#define ITERATEUR_H


#include "Ecran.h"
#include "ListeBase.h"
#include "BaseException.h"


using namespace std;

template<class T> class Iterateur
{	

	private:
		ListeBase<T> &lis;
		struct Cellule<T> *pCur;
		
	public:
		//constructeurs
		Iterateur(ListeBase<T> &l):lis(l),pCur(l.getTete()) {};

		//destructeur	
				
		//operators
		void operator++();
		void operator++(int);
		operator T() const;
		T& operator&();
		
		//getters
		
		//setters
		
		//methodes
		void reset();
		bool end() const;
		T remove();
		Cellule<T>* getpCur() const;

};

#endif //ITERATEUR_H
