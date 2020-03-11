/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include "Ecran.h"
#include "XYException.h"

using namespace std;

class Pixel {	
		
	protected:
		int x;
		int y;
		
	public:
		//constructeurs
		Pixel(void);
		Pixel(int xTmp, int yTmp);
		Pixel(const Pixel& p);
		
		//getters
		int getX() const;
		int getY() const;
		
		//setters
		void setX(const int xTmp);
		void setY(const int yTmp);
		
};

#endif //PIXEL_H
