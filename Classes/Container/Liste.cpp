/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 13/11/2019             */
/***********************************************************/

#include "Liste.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
template <class T> Liste<T>::Liste(void):ListeBase<T>()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
}

//Constructeur de copie
template <class T> Liste<T>::Liste(const Liste& L):ListeBase<T>(L)
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

template <class T> Liste<T>::~Liste()
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
		
template <class T> void Liste<T>::insere(const T &val)
{
	Cellule<T> *nouv = NULL;
	nouv = new Cellule<T>;
	
	if(nouv != NULL)
	{
		nouv->valeur = val;
		nouv->suivant = NULL;
		if(this->estVide())
		{
			this->setTete(nouv);
		}
		else
		{
			Cellule<T> *tmp = this->getTete();
			while(tmp->suivant != NULL)
			{
				tmp = tmp->suivant;
			}
			tmp->suivant = nouv;
		}
	}
}

template class Liste<int>;
#include "Couleur.h"
template class Liste<Couleur>;
#include "ImageB.h"
template class Liste<ImageB>;
#include "ImageRGB.h"
template class Liste<ImageRGB>;
#include "ImageNG.h"
template class Liste<ImageNG>;
	
		
