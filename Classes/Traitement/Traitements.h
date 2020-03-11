/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 18/10/2019             */
/***********************************************************/

#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H

#include <iostream>
#include <fstream>
#include "Ecran.h"
//#include "XYException.h"
//#include "RGBException.h"
#include "BaseException.h"
#include "Pixel.h"
#include "ImageB.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ListeTriee.h"
#include "Iterateur.h"

using namespace std;

class Traitements{
		
	private:
	
	public:
		//constructeurs
		
		//operators

		//getters

		//setters
		
		//méthodes
		static ImageB Seuillage(const ImageNG& imageIn, int seuil);
		static ImageNG FiltreMoyenneur(const ImageNG& imageIn, int taille, Pixel p1=Pixel(), Pixel p2=Pixel());
		static ImageNG FiltreMedian(const ImageNG& imageIn, int taille);
		static ImageNG Erosion(const ImageNG& imageIn, int taille);
		static ImageNG Dilatation(const ImageNG& imageIn, int taille);
		static ImageNG Negatif(const ImageNG& imageIn);

};

#endif //TRAITEMENTS_H
