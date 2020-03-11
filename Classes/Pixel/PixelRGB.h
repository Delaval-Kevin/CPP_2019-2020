/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 22/10/2019             */
/***********************************************************/

#ifndef PIXELRGB_H
#define PIXELRGB_H

#include <iostream>
#include "Ecran.h"
#include "Pixel.h"
#include "Couleur.h"

using namespace std;

class PixelRGB : public Pixel
{	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const PixelRGB& p);
		
	private:
		Couleur couleur;
		
	public:
		//constructeurs
		PixelRGB(void);
		PixelRGB(int xTmp, int yTmp, Couleur cTmp);
		PixelRGB(const PixelRGB& p);
		
		//getters
		const Couleur& getValeur() const;
		
		//setters
		void setValeur(Couleur cTmp);
		
};

#endif //PIXELRGB_H
