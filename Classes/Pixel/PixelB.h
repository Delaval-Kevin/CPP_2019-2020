/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 22/10/2019             */
/***********************************************************/

#ifndef PIXELB_H
#define PIXELB_H

#include <iostream>
#include "Ecran.h"
#include "Pixel.h"
#include "Couleur.h"

using namespace std;

class PixelB : public Pixel
{	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const PixelB& p);
		
	private:
		bool valeur;
		
	public:
		//constructeurs
		PixelB(void);
		PixelB(int xTmp, int yTmp, bool vTmp);
		PixelB(const PixelB& p);
		
		//getters
		bool getValeur() const;
		
		//setters
		void setValeur(bool vTmp);
		
};

#endif //PIXELB_H
