/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 11/10/2019             */
/***********************************************************/

#include "Dimension.h"

//Initialisation des variables membre statiques et constantes

const Dimension Dimension::VGA(640,480);
const Dimension Dimension::HD(1280,720);
const Dimension Dimension::FULL_HD(1920,1080);

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/


//Constructeur par défaut
Dimension::Dimension(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut\n");
	#endif
	largeur=400;
	hauteur=300;
}

//Constructeur d'initialisation
Dimension::Dimension(int larg,int haut)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation\n");
	#endif
	largeur=larg;
	hauteur=haut;
}

//Constructeur de copie
Dimension::Dimension(const Dimension& d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie\n");
	#endif
	largeur=d.largeur;
	hauteur=d.hauteur;
}

/********************************/
/*                              */
/*         Destructeurs         */			
/*                              */
/********************************/
			
/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

//Opérateur << de cout			
ostream& operator<<(ostream& s, const Dimension& d)
{
	s<< " Largeur : " << d.largeur << " Hauteur : " << d.hauteur;
	return s;
}

//Opérateur >> de cin
istream& operator>>(istream& s, Dimension& d)
{
	int larg,haut;
	cout << "Entrez la largeur : ";
	cin >> larg;
	cout << "Entrez la hauteur : ";
	cin >> haut;
	
	d.largeur = larg;
	d.hauteur = haut;
	
	return s;
}

bool Dimension::operator==(const Dimension& d)
{
	if(largeur == d.getLargeur() && hauteur == d.getHauteur())
		return true;
	else
		return false;
}

bool Dimension::operator!=(const Dimension& d)
{
	if(largeur == d.getLargeur() && hauteur == d.getHauteur())
		return false;
	else
		return true;
}
			
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void Dimension::setLargeur(int larg)
{
	largeur=larg;
}

void Dimension::setHauteur(int haut)
{
	hauteur=haut;
}
		
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/
					
int Dimension::getLargeur() const
{
	return largeur;
}

int Dimension::getHauteur() const
{
	return hauteur;
}	
		
/********************************/
/*                              */
/*           Methodes           */			
/*                              */
/********************************/
			
void Dimension::Affiche() const
{
	  cout << "Largeur  = " << getLargeur() << endl;
	  cout << "Hauteur  = " << getHauteur() << endl;
}




