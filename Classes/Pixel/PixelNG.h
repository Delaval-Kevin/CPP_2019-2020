/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#ifndef PIXELNG_H
#define PIXELNG_H

#include <iostream>
#include "Ecran.h"
#include "Pixel.h"
#include "RGBException.h"

using namespace std;

class PixelNG : public Pixel
{	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const PixelNG& p);
		
	private:
		int valeur;
		
	public:
		//constructeurs
		PixelNG(void);
		PixelNG(int xTmp, int yTmp, int valTmp);
		PixelNG(const PixelNG& p);
		
		//getters
		int getValeur() const;
		
		//setters
		void setValeur(int valTmp);
		
};

#endif //PIXELNG_H
