/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 14/11/2019             */
/***********************************************************/

#ifndef LISTETRIEE_H
#define LISTETRIEE_H

#include <iostream>
#include "Ecran.h"
#include "ListeBase.h"

using namespace std;

template<class T> class ListeTriee : public ListeBase<T>
{	

	private:
		
	public:
		//constructeurs
		ListeTriee(void);
		ListeTriee(const ListeTriee& LT);
		//destructeur
		~ListeTriee();
				
		//operators

		//getters
		
		//setters
		
		//methodes
		void insere(const T &val);

};

#endif //LISTETRIEE_H
