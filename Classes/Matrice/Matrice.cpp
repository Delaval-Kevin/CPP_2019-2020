/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 24/10/2019             */
/***********************************************************/

#include "Matrice.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
template <class T> Matrice<T>::Matrice(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	tab = NULL;
	setLargeurConstruct(3);
	setHauteurConstruct(3);
	CreeTab(getLargeur(), getHauteur());
}

//Constructeur d'initialisation sans valeurs
template <class T> Matrice<T>::Matrice(int l, int h)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans valeurs");
	#endif
	tab = NULL;
	setLargeurConstruct(l);
	setHauteurConstruct(h);
	CreeTab(getLargeur(), getHauteur());
}

//Constructeur d'initialisation avec valeurs
template <class T> Matrice<T>::Matrice(int l, int h, const T& val)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec valeurs");
	#endif
	tab = NULL;
	setLargeurConstruct(l);
	setHauteurConstruct(h);
	CreeTab(getLargeur(), getHauteur());

	int haut = getHauteur();
	int larg = getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setValeur(x,y,val);
		}
	}
}

//Constructeur de copie
template <class T> Matrice<T>::Matrice(const Matrice& m)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	tab = NULL;
	setLargeurConstruct(m.getLargeur());
	setHauteurConstruct(m.getHauteur());
	CreeTab(getLargeur(), getHauteur());
		
	int haut = getHauteur();
	int larg = getLargeur();
		
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setValeur(x,y,m.getValeur(x,y));
		}
	}
}
		
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

template <class T> Matrice<T>::~Matrice()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	if(tab)
	{
		int larg = getLargeur();
		for(int x = 0 ; x < larg ; x++)
			delete[] tab[x];
		delete[] tab;
	}
}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

template <class T>  const Matrice<T>& Matrice<T>::operator=(const Matrice& m)
{
	CreeTab(m.getLargeur(), m.getHauteur());

	int haut = getHauteur();
	int larg = getLargeur();

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setValeur(x,y,m.getValeur(x,y));
		}
	}	
	 
	return *this;
}

template <class T> T Matrice<T>::operator()(int x, int y) const
{
	return getValeur(x,y);
}

template <class T> T& Matrice<T>::operator()(int x, int y)
{
	return tab[x][y];
}
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

template <class T> int Matrice<T>::getLargeur() const
{
	return largeur;
}

template <class T> int Matrice<T>::getHauteur() const
{
	return hauteur;
}

template <class T> T Matrice<T>::getValeur(int x, int y) const
{
	return tab[x][y];
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
template <class T> void Matrice<T>::setLargeurConstruct(int l)
{
	if(l <= 0)
		throw XYException('x', "Dimension invalide");
		
	largeur = l;
}
	
template <class T> void Matrice<T>::setHauteurConstruct(int h)
{
	if(h <= 0)
		throw XYException('y', "Dimension invalide");
		
	hauteur = h;
}

template <class T> void Matrice<T>::setLargeur(int l)
{
	if(l <= 0)
		throw XYException('x', "Dimension invalide");
		
	CreeTab(l, getHauteur());
	
	largeur = l;
}
	
template <class T> void Matrice<T>::setHauteur(int h)
{
	if(h <= 0)
		throw XYException('y', "Dimension invalide");
	
	CreeTab(getLargeur(), h);
	
	hauteur = h;
}

template <class T> void Matrice<T>::setValeur(int x, int y, const T& val)
{
	if(x >= getLargeur() || y >= getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	tab[x][y] = val;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
template <class T> void Matrice<T>::Affiche() const
{
	int haut = getHauteur();
	int larg = getLargeur();
	
	for(int x = 0 ; x < haut ; x++)
	{
		for(int y = 0 ; y < larg ; y++)
		{
			cout << getValeur(y,x) << " ";
		}
		cout << endl;
	}	
	cout << endl;
}

template <class T> void Matrice<T>::CreeTab(int l, int h)
{	
	if(tab)
	{
		int larg = getLargeur();
		
		for(int x = 0 ; x < larg ; x++)
			delete[] tab[x];
		delete[] tab;
	}
	
	setLargeurConstruct(l);
	setHauteurConstruct(h);

	int larg = getLargeur();
	int haut = getHauteur();
	tab = new T*[larg];
	for(int x = 0 ; x < larg ; x++)
		tab[x] = new T[haut];
			
}


template class Matrice<int>;
template class Matrice<char>;
template class Matrice<bool>;
#include "Couleur.h"
template class Matrice<Couleur>;

	
		
