/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H

#include <string.h>
#include <iostream>
#include "Ecran.h"
#include "BaseException.h"


using namespace std;

class RGBException : public BaseException
{		
		//fonctions amies
		friend ostream& operator<<(ostream& s, const RGBException& exc);
			
	private:
		int valeur;
		
	public:
		//constructeurs
		RGBException(void);
		RGBException(int val,const char* MsgTmp);
		RGBException(const RGBException& CE);
		//destructeur
		~RGBException();
				
		//getters
		int getValeur() const;

		
		//setters
		void setValeur(int val);


};

#endif //RGBEXCEPTION_H
