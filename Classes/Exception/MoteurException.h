/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/11/2019             */
/***********************************************************/

#ifndef MOTEUREXCEPTION_H
#define MOTEUREXCEPTION_H

#include <string.h>
#include <iostream>
#include "Ecran.h"
#include "BaseException.h"


using namespace std;

class MoteurException : public BaseException
{		
		//fonctions amies
		friend ostream& operator<<(ostream& s, const MoteurException& exc);
	
	private:
		
	public:
		//constructeurs
		MoteurException(void);
		MoteurException(const char* MsgTmp);
		MoteurException(const MoteurException& ME);
		//destructeur
		~MoteurException();
				
		//getters


		//setters


};

#endif //MOTEUREXCEPTION_H
