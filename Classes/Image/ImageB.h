/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#ifndef IMAGEB_H
#define IMAGEB_H

#include <string.h>
#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "Image.h"
#include "PixelB.h"
#include "Couleur.h"
#include "Dimension.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "BaseException.h"
#include "XYException.h"
#include "Matrice.h"

using namespace std;

class ImageB : public Image
{	

		//fonctions amies
		friend ostream& operator<<(ostream& s, const ImageB& i);
		friend ImageB operator+(const PixelB& p, const ImageB& i);
		
	private:
		Matrice<bool> matrice;
		bool MatValid;
			
	public:
		//constructeurs
		ImageB(void);
		ImageB(int a,const char *p);
		ImageB(int a,const char *p,const Dimension& d);
		ImageB(const ImageB& i);
		//destructeur
		~ImageB();

		//operators
		const ImageB& operator=(const ImageB& i);
		ImageB operator+(const PixelB& p);		
		
		//getters
		bool getPixel(int x,int y) const;
		
		//setters
		void setDimension(const Dimension& d);
		void setPixel(int x,int y, bool valeur);
		void setBackground(bool valeur);
		
		//methodes
		void Affiche() const;
		void Dessine() const;
		void Dessine(int x, int y) const;
		void exportToBMP(const char* fichier);
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		
		//variables membres statique
		static Couleur couleurTrue;
		static Couleur couleurFalse;
		
};

#endif //IMAGEB_H
