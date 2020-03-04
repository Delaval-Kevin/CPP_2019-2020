/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement des erreurs                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 23/10/2019             */
/***********************************************************/

#include "BaseException.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
BaseException::BaseException(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	message = NULL;
}

//Constructeur d'initialisation
BaseException::BaseException(const char* MsgTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	message = NULL;
	setMessage(MsgTmp);
}

//Constructeur de copie
BaseException::BaseException(const BaseException& BE)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	message = NULL;
	setMessage(BE.getMessage());
}

/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

BaseException::~BaseException()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	if(message)
	{
		delete message;
	}
}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

ostream& operator<<(ostream& s, const BaseException& exc)
{
	if(exc.message == 0)
	{
		s << " Erreur ! ";
		return s;
	}

	s << exc.message ;
	return s;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

const char* BaseException::getMessage() const
{
	return message;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void BaseException::setMessage(const char* MsgTmp)
{
	if(message)
		delete message;
		
	if(MsgTmp != 0)
	{	
		message = new char[strlen(MsgTmp)+1];
		strcpy(message,MsgTmp);
	}
	else
		message = NULL;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

