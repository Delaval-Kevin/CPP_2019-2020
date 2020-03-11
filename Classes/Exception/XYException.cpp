/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#include "XYException.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
XYException::XYException(void):BaseException()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	coordonnee = 0;
}

//Constructeur d'initialisation
XYException::XYException(char coTmp,const char* MsgTmp):BaseException(MsgTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setCoordonnee(coTmp);
}

//Constructeur de copie
XYException::XYException(const XYException& XE):BaseException(XE)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setCoordonnee(XE.coordonnee);
}

/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

XYException::~XYException()
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

ostream& operator<<(ostream& s, const XYException& exc)
{
	if(exc.message == 0)
	{
		s << exc.coordonnee << " Erreur ! ";
		return s;
	}

	s << exc.coordonnee << " " << exc.message ;
	return s;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

char XYException::getCoordonnee() const
{
	return coordonnee;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void XYException::setCoordonnee(char coTmp)
{
	coordonnee = coTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

