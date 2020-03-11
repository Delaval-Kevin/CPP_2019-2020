/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 10/10/2019             */
/***********************************************************/

#ifndef IMAGENH_H
#define IMAGENG_H

#include <string.h>
#include <iostream>
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "Ecran.h"
#include "Dimension.h"
#include "PixelNG.h"

using namespace std;

class ImageNG {

		//fonctions amies
		friend ostream& operator<<(ostream& s, const ImageNG& i);
		friend ImageNG operator+(const ImageNG& i, int lum);
		friend ImageNG operator+(int lum, const ImageNG& i);
		friend ImageNG operator-(const ImageNG& i, int lum);
		friend ImageNG operator-(const ImageNG& i1, const ImageNG& i2);
		friend ImageNG operator+(const ImageNG& i, const PixelNG& p);
		friend ImageNG operator+(const PixelNG& p, const ImageNG& i);
			
	private:
		int id;
		char *nom;
		int ** matrice;
		Dimension dimension;	
	
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
		ImageNG& operator=(const ImageNG& i);
		ImageNG operator++();
		ImageNG operator++(int);
		ImageNG operator--();
		ImageNG operator--(int);
		bool operator==(const ImageNG& i);	
		bool operator<(const ImageNG& i);
		bool operator>(const ImageNG& i);	
		
		//getters
		int getId() const;
		const char* getNom() const;
		const Dimension& getDimension() const;
		int getPixel(int x,int y) const;
		int getLuminance() const;
		int getMinimum() const;
		int getMaximum() const;
		float getContraste() const;
		int getComparaison() const;

		//setters
		void setNom(const char* nompro);
		void setId(int idpro);
		void setDimension(const Dimension& d);
		void setPixel(int x,int y, int val);
		void setBackground(int val);
		static void setComparaison(int c);
		
		//methodes
		void Affiche()const;
		void Dessine();
		void importFromBMP(const char* fichier);
		void exportToBMP(const char* fichier);
		
		//variables membres statique
		static const int LUMINANCE;
		static const int PIXEL_A_PIXEL;
		static int comparaison;
};

#endif //IMAGENG_H
