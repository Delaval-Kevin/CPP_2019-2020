/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 15/10/2019             */
/***********************************************************/

#include "Image.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/


//Constructeur par défaut
Image::Image(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	id = 0;
	nom = NULL;
}

//Constructeur d'initialisation complet sans la dimension
Image::Image(int a,const char *p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension");
	#endif
	id = a;
	nom = NULL;
	setNom(p);
}

//Constructeur d'initialisation complet avec la dimension
Image::Image(int a,const char *p,const Dimension& d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension");
	#endif
	id = a;
	nom = NULL;
	setNom(p);
}

//Constructeur de copie
Image::Image(const Image& i)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	id = i.id;
	nom = NULL;
	setNom(i.getNom());
	setDimension(i.getDimension());

}
			
/********************************/
/*                              */
/*         Destructeurs         */			
/*                              */
/********************************/

Image::~Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	if(nom)
	{
		delete nom;
	}
}

/********************************/
/*                              */
/*            Operator          */			
/*                              */
/********************************/


/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
void Image::setId(int idpro)
{
	id = idpro;
}

void Image::setNom(const char* nompro)
{
	if(nom)
		delete nom;
		
	if(nompro != 0)
	{	
		nom = new char[strlen(nompro)+1];
		strcpy(nom,nompro);
	}
	else
		nom = NULL;
}

void Image::setDimension(const Dimension& d)
{	
	dimension.setLargeur(d.getLargeur());
	dimension.setHauteur(d.getHauteur());
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

int Image::getId() const
{
	return id;
}

const char* Image::getNom() const
{
	return nom;
}

const Dimension& Image::getDimension() const
{
	return dimension;
}

/********************************/
/*                              */
/*           Methodes           */			
/*                              */
/********************************/
			
void Image::Save(ofstream &fichier) const
{
	int taille;

	fichier.write((char*)&id, sizeof(id));
	
	taille = strlen(nom)+1;
	fichier.write((char*)&taille, sizeof(taille));
	
	fichier.write((char*)nom, taille);
	
	dimension.Save(fichier);
}

void Image::Load(ifstream &fichier)
{
	char *tmpNom;
	int taille;
	
	fichier.read((char*)&id, sizeof(id));
	fichier.read((char*)&taille, sizeof(taille));	
	tmpNom = new char[taille];
	fichier.read((char*)tmpNom, taille);
	
	setNom(tmpNom);
	delete tmpNom;
	
	dimension.Load(fichier);
}





