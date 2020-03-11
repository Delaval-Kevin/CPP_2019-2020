/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 14/11/2019             */
/***********************************************************/

#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include "Ecran.h"
#include "ListeBase.h"

using namespace std;

template<class T> class Liste : public ListeBase<T>
{	

	private:
		
	public:
		//constructeurs
		Liste(void);
		Liste(const Liste& L);
		//destructeur
		~Liste();
				
		//operators

		//getters
		
		//setters
		
		//methodes
		void insere(const T &val);

};

#endif //LISTE_H
