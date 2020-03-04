/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#ifndef IMAGERGB_H
#define IMAGERGB_H

#include <string.h>
#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "Image.h"
#include "ImageNG.h"
#include "Couleur.h"
#include "Dimension.h"
#include "PixelRGB.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "BaseException.h"
#include "XYException.h"
#include "Matrice.h"

using namespace std;

class ImageRGB : public Image
{	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const ImageRGB& i);
		friend ImageRGB operator+(const PixelRGB& p, const ImageRGB& i);
		
	private:
		Matrice<Couleur> matrice;
		bool MatValid;
		
	public:
		//constructeurs
		ImageRGB(void);
		ImageRGB(const char *p);
		ImageRGB(int a,const char *p);
		ImageRGB(int a,const char *p,const Dimension& d);
		ImageRGB(const ImageRGB& i);
		//destructeur
		~ImageRGB();

		//operators
		const ImageRGB& operator=(const ImageRGB& i);
		ImageRGB operator+(const PixelRGB& p);		
		
		//getters
		Couleur getPixel(int x,int y) const;
		
		//setters
		void setDimension(const Dimension& d);
		void setPixel(int x,int y, const Couleur& valeur);
		void setBackground(const Couleur& valeur);
		
		//methodes
		void Affiche()const;
		void Dessine()const;
		void Dessine(int x, int y) const;
		void importFromBMP(const char* fichier);
		void exportToBMP(const char* fichier);
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		ImageNG getRouge() const;
		ImageNG getVert() const;
		ImageNG getBleu() const;
		void setRGB(const ImageNG &r, const ImageNG &g, const ImageNG &b);
};

#endif //IMAGERGB_H
