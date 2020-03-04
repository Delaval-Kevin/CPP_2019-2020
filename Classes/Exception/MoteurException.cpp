/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/11/2019             */
/***********************************************************/

#include "MoteurException.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
MoteurException::MoteurException(void):BaseException()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
}

//Constructeur d'initialisation
MoteurException::MoteurException(const char* MsgTmp):BaseException(MsgTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
}

//Constructeur de copie
MoteurException::MoteurException(const MoteurException& ME):BaseException(ME)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
}

/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

MoteurException::~MoteurException()
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

ostream& operator<<(ostream& s, const MoteurException& exc)
{
	if(exc.message == 0)
	{
		s << "\033[00;31m" << " Erreur ! " << "\033[00m";
		return s;
	}

	s << "\033[00;31m" << "\033[04m" << exc.message << "\033[00m" ;
	return s;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/


		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/


/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

