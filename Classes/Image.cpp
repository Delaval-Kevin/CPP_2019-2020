/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
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
	id=0;
	nom=0;
	setDimension(Dimension::VGA);

}

//Constructeur d'initialisation complet sans la dimension
Image::Image(int a,const char *p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension");
	#endif
	id=a;
	nom=0;
	setNom(p);
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet avec la dimension
Image::Image(int a,const char *p,const Dimension& d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension");
	#endif
	id=a;
	nom=0;
	setNom(p);
	setDimension(d);
}

//Constructeur de copie
Image::Image(const Image& i)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	id=i.id;
	nom = 0;
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
		
	if(nompro!=0)
	{	
		nom = new char[strlen(nompro)+1];
		strcpy(nom,nompro);
	}
	else
		nom=0;
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
			
void ImageNG::Affiche() const
{
	if(nom)
		cout << "Nom = " << getNom() << endl;
	else
		cout << "Nom = Pas de nom" << endl;
   cout << "Id  = " << getId() << endl;
   dimension.Affiche();
}











