/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#include "PixelNG.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
PixelNG::PixelNG(void):Pixel()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	valeur = 0;
}

//Constructeur d'initialisation
PixelNG::PixelNG(int xTmp, int yTmp, int valTmp):Pixel(xTmp,yTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setValeur(valTmp);
}

//Constructeur de copie
PixelNG::PixelNG(const PixelNG& p):Pixel(p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setValeur(p.valeur);
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
ostream& operator<<(ostream& s, const PixelNG& p)
{
	s<< " X : " << p.getX() << " Y : " << p.getY() << " Valeur : " << p.getValeur();
	return s;
}
			
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/
						
int PixelNG::getValeur() const
{
	return valeur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void PixelNG::setValeur(int valTmp)
{
	if(valTmp>255 || valTmp<0)
		throw RGBException(valTmp,"Niveau de gris invalide");

	valeur = valTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
		
		
