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
Pixel::Pixel(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	x = 0;
	y = 0;
}

//Constructeur d'initialisation
Pixel::Pixel(int xTmp, int yTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setX(xTmp);
	setY(yTmp);
}

//Constructeur de copie
Pixel::Pixel(const Pixel& p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setX(p.x);
	setY(p.y);
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
			
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

int Pixel::getX() const
{
	return x;
}

int Pixel::getY() const
{
	return y;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
void Pixel::setX(const int xTmp)
{
	if(xTmp < 0)
		throw XYException('x', "Coordonnees pixel invalides");
		
	x = xTmp;
}

void Pixel::setY(const int yTmp)
{
	if(yTmp < 0)
		throw XYException('y', "Coordonnees pixel invalides");
		
	y = yTmp;
}

		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
		
		
