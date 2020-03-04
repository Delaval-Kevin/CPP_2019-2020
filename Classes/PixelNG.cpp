/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 10/10/2019             */
/***********************************************************/

#include "PixelNG.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
PixelNG::PixelNG(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut\n");
	#endif
	x=0;
	y=0;
	valeur=0;
}

//Constructeur d'initialisation
PixelNG::PixelNG(int xTmp, int yTmp, int valTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation\n");
	#endif
	x=xTmp;
	y=yTmp;
	valeur=valTmp;
}

//Constructeur de copie
PixelNG::PixelNG(const PixelNG& p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie\n");
	#endif
	x=p.x;
	y=p.y;
	valeur=p.valeur;
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
						
int PixelNG::getX() const
{
	return x;
}

int PixelNG::getY() const
{
	return y;
}

int PixelNG::getValeur() const
{
	return valeur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
void PixelNG::setX(const int xTmp)
{
	x=xTmp;
}

void PixelNG::setY(const int yTmp)
{
	y=yTmp;
}

void PixelNG::setValeur(const int valTmp)
{
	valeur=valTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
		
		
