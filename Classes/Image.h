/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 15/10/2019             */
/***********************************************************/

#ifndef IMAGE_H
#define IMAGE_H

#include <string.h>
#include <iostream>
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "Ecran.h"
#include "Dimension.h"


using namespace std;

class Image
{
	protected:
		int id;
		char *nom;
		Dimension dimension;	
	
	public:
		//constructeurs
		Image(void);
		Image(int a,const char *p);
		Image(int a,const char *p,const Dimension& d);
		Image(const ImageNG& i);
		//destructeur
		~Image();
		
		//getters
		int getId() const;
		const char* getNom() const;
		const Dimension& getDimension() const;

		//setters
		void setNom(const char* nompro);
		void setId(int idpro);
		void setDimension(const Dimension& d);
		
		//methodes
		void Affiche()const;
};

#endif //IMAGE_H
