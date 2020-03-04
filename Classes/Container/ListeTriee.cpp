/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 13/11/2019             */
/***********************************************************/

#include "ListeTriee.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
template <class T> ListeTriee<T>::ListeTriee(void):ListeBase<T>()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
}

//Constructeur de copie
template <class T> ListeTriee<T>::ListeTriee(const ListeTriee& L):ListeBase<T>(L)
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

template <class T> ListeTriee<T>::~ListeTriee()
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
		
template <class T> void ListeTriee<T>::insere(const T &val)
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
			Cellule<T> *tmpPrec = NULL;
			Cellule<T> *tmp = this->getTete();
			while(tmp->suivant != NULL && nouv->valeur > tmp->valeur)
			{
				tmpPrec = tmp;
				tmp = tmp->suivant;
			}
			if(nouv->valeur < tmp->valeur)
			{
				if(tmpPrec == NULL)
				{
					nouv->suivant = this->getTete();
					this->setTete(nouv);
				}
				else
				{
					tmpPrec->suivant = nouv;
					nouv->suivant = tmp;
				}
			}
			else
			{
				nouv->suivant = tmp->suivant;
				tmp->suivant = nouv;
			}
		}
	}
}

template class ListeTriee<int>;
#include "ImageNG.h"
template class ListeTriee<ImageNG>;

	
		
