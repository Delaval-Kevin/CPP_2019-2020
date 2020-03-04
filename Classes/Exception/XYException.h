/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H

#include <string.h>
#include <iostream>
#include "Ecran.h"
#include "BaseException.h"


using namespace std;

class XYException : public BaseException
{		
		//fonctions amies
		friend ostream& operator<<(ostream& s, const XYException& exc);
	
	private:
		char coordonnee;
		
	public:
		//constructeurs
		XYException(void);
		XYException(char coTmp,const char* MsgTmp);
		XYException(const XYException& XE);
		//destructeur
		~XYException();
				
		//getters
		char getCoordonnee() const;

		//setters
		void setCoordonnee(char coTmp);


};

#endif //XYEXCEPTION_H
