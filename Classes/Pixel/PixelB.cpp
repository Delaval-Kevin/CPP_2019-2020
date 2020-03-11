/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 22/10/2019             */
/***********************************************************/

#include "PixelB.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
PixelB::PixelB(void):Pixel()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	valeur = false;
}

//Constructeur d'initialisation
PixelB::PixelB(int xTmp, int yTmp, bool vTmp):Pixel(xTmp,yTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setValeur(vTmp);
}

//Constructeur de copie
PixelB::PixelB(const PixelB& p):Pixel(p)
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
ostream& operator<<(ostream& s, const PixelB& p)
{
	s<< " X : " << p.getX() << " Y : " << p.getY() << " Couleur : " << p.valeur;
	return s;
}
			
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/
						
bool PixelB::getValeur() const
{
	return valeur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void PixelB::setValeur(bool vTmp)
{
	valeur = vTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
		
		
