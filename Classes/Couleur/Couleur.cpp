/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#include "Couleur.h"

//Initialisation des variables membre statiques et constantes

const Couleur Couleur::ROUGE(255,0,0);
const Couleur Couleur::VERT(0,255,0);
const Couleur Couleur::BLEU(0,0,255);
const Couleur Couleur::BLANC(255,255,255);
const Couleur Couleur::NOIR(0,0,0);

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
Couleur::Couleur(void)
{
	#ifdef DEBUG
//	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	rouge = 0;
	vert = 0;
	bleu = 0;
}

//Constructeur d'initialisation
Couleur::Couleur(int rTmp, int vTmp, int bTmp)
{
	#ifdef DEBUG
//	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	setRouge(rTmp);
	setVert(vTmp);
	setBleu(bTmp);
}

//Constructeur de copie
Couleur::Couleur(const Couleur& c)
{
	#ifdef DEBUG
//	TraceConstructeur("Appel au constructeur de copie");
	#endif
	setRouge(c.rouge);
	setVert(c.vert);
	setBleu(c.bleu);
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
ostream& operator<<(ostream& s, const Couleur& c)
{
	s<< " r:" << c.getRouge() << " v:" << c.getVert() << " b:" << c.getBleu() ;
	return s;
}

//Opérateur >> de cin
istream& operator>>(istream& s, Couleur& c)
{
	int rTmp,vTmp,bTmp;
	cout << "Entrez la valeur pour le rouge : ";
	cin >> rTmp;
	cout << "Entrez la valeur pour le vert  : ";
	cin >> vTmp;
	cout << "Entrez la valeur pour le bleu  : ";
	cin >> bTmp;
	
	c.setRouge(rTmp);
	c.setVert(vTmp);
	c.setBleu(bTmp);
	
	return s;
}

const Couleur& Couleur::operator=(const Couleur& c)
{
	setRouge(c.getRouge());
	setVert(c.getVert());
	setBleu(c.getBleu());
	
	return *this;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

int Couleur::getRouge() const
{
	return rouge;
}

int Couleur::getVert() const
{
	return vert;
}

int Couleur::getBleu() const
{
	return bleu;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void Couleur::setRouge(int rTmp)
{
	if(rTmp > 255 || rTmp < 0)
		throw RGBException(rTmp,"Composante du rouge invalide");
	
	rouge = rTmp;
}

void Couleur::setVert(int vTmp)
{
	if(vTmp > 255 || vTmp < 0)
		throw RGBException(vTmp,"Composante du vert invalide");

	vert = vTmp;
}

void Couleur::setBleu(int bTmp)
{
	if(bTmp > 255 || bTmp < 0)
		throw RGBException(bTmp,"Composante du bleu invalide");
		
	bleu = bTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void Couleur::Affiche() const
{
	  cout << " r = " << getRouge() << " v = " << getVert() << " b = " << getBleu();
}

//Sauvegarde la dimension dans un fichier via les flux
void Couleur::Save(ofstream &fichier) const
{
	Couleur tmpCoul(*this);
	fichier.write((char*)&tmpCoul, sizeof(tmpCoul));
}

//Charge la dimension dans un fichier via les flux
void Couleur::Load(ifstream &fichier)
{
	Couleur tmpCoul;
	fichier.read((char*)&tmpCoul, sizeof(tmpCoul));
	*this = tmpCoul;
}




