/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 10/10/2019             */
/***********************************************************/

#ifndef PIXELNG_H
#define PIXELNG_H

#include <iostream>
#include "Ecran.h"

using namespace std;

class PixelNG {	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const PixelNG& p);
		
	private:
		int x;
		int y;
		int valeur;
		
	public:
		//constructeurs
		PixelNG(void);
		PixelNG(int xTmp, int yTmp, int valTmp);
		PixelNG(const PixelNG& p);
		
		//getters
		int getX() const;
		int getY() const;
		int getValeur() const;
		
		//setters
		void setX(const int xTmp);
		void setY(const int yTmp);
		void setValeur(const int valTmp);
		
};

#endif //PIXELNG_H
