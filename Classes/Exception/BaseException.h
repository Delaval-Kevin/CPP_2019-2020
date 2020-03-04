/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <string.h>
#include <iostream>
#include "Ecran.h"

using namespace std;

class BaseException
{	
		//fonctions amies
		friend ostream& operator<<(ostream& s, const BaseException& exc);
		
	protected:
		char* message;
		
	public:
		//constructeurs
		BaseException(void);
		BaseException(const char* MsgTmp);
		BaseException(const BaseException& BE);
		//destructeur
		virtual ~BaseException();
				
		//getters
		const char* getMessage() const;

		
		//setters
		void setMessage(const char* MsgTmp);


};

#endif //BASEEXCEPTION_H
