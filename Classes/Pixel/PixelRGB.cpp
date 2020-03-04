/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 22/10/2019             */
/***********************************************************/

#include "PixelRGB.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
PixelRGB::PixelRGB(void):Pixel()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
//	couleur = Couleur::NOIR;  Normalement pas utile car dès sa création est initialisé a 0
}

//Constructeur d'initialisation
PixelRGB::PixelRGB(int xTmp, int yTmp, Couleur cTmp):Pixel(xTmp,yTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setValeur(cTmp);
}

//Constructeur de copie
PixelRGB::PixelRGB(const PixelRGB& p):Pixel(p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setValeur(p.couleur);
}
		
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/
			
/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/
			
//Opérateur << de cout
ostream& operator<<(ostream& s, const PixelRGB& p)
{
	s<< " X : " << p.getX() << " Y : " << p.getY() << " Couleur : " << p.couleur;
	return s;
}
			
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/
						
const Couleur& PixelRGB::getValeur() const
{
	return couleur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void PixelRGB::setValeur(Couleur cTmp)
{
	couleur = cTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
		
		
