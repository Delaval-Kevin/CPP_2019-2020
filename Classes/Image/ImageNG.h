/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 10/10/2019             */
/***********************************************************/

#ifndef IMAGENG_H
#define IMAGENG_H

#include <string.h>
#include <iostream>
#include <fstream>
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "Ecran.h"
#include "Dimension.h"
#include "PixelNG.h"
#include "Image.h"
#include "WindowSDLexception.h"
#include "BaseException.h"
#include "RGBException.h"
#include "XYException.h"
#include "Matrice.h"

using namespace std;

class ImageNG : public Image
{

		//fonctions amies
		friend ostream& operator<<(ostream& s, const ImageNG& i);
		friend ImageNG operator+(int lum, const ImageNG& i);
		friend ImageNG operator+(const PixelNG& p, const ImageNG& i);
			
	private:
		Matrice<int> matrice;	
		static int comparaison;
		bool MatValid;
	
	public:
		//constructeurs
		ImageNG(void);
		ImageNG(const char *p);
		ImageNG(int a,const char *p);
		ImageNG(int a,const char *p,const Dimension& d);
		ImageNG(const ImageNG& i);
		//destructeur
		~ImageNG();
		
		//operators
		const ImageNG& operator=(const ImageNG& i);
		ImageNG operator+(int lum);
		ImageNG operator+(const PixelNG& p);
		ImageNG operator-(const ImageNG& i);
		ImageNG operator-(int lum);
		ImageNG operator++();
		ImageNG operator++(int);
		ImageNG operator--();
		ImageNG operator--(int);
		bool operator==(const ImageNG& i);	
		bool operator<(const ImageNG& i);
		bool operator>(const ImageNG& i);	
		
		//getters
		int getPixel(int x,int y) const;
		int getLuminance() const;
		int getMinimum() const;
		int getMaximum() const;
		float getContraste() const;
		int getComparaison() const;

		//setters
		void setDimension(const Dimension& d);
		void setPixel(int x,int y, int val);
		void setBackground(int val);
		static void setComparaison(int c);
		
		//methodes
		void Affiche()const;
		void Dessine()const;
		void Dessine(int x, int y) const;
		void importFromBMP(const char* fichier);
		void exportToBMP(const char* fichier);
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		
		//variables membres statique
		static const int LUMINANCE;
		static const int PIXEL_A_PIXEL;

};

#endif //IMAGENG_H
