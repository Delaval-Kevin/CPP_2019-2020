/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#include "RGBException.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
RGBException::RGBException(void):BaseException()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	valeur = 0;
}

//Constructeur d'initialisation
RGBException::RGBException(int val,const char* MsgTmp):BaseException(MsgTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setValeur(val);
}

//Constructeur de copie
RGBException::RGBException(const RGBException& BE):BaseException(BE)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setValeur(BE.valeur);
}

/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

RGBException::~RGBException()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif

}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

ostream& operator<<(ostream& s, const RGBException& exc)
{
	if(exc.message == 0)
	{
		s << exc.valeur << " Erreur ! ";
		return s;
	}

	s << exc.valeur << " " << exc.message ;
	return s;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

int RGBException::getValeur() const
{
	return valeur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void RGBException::setValeur(int val)
{
	valeur = val;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

