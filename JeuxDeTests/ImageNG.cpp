/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
/*Date de la dernière mise à jour : 29/09/2019             */
/***********************************************************/

#include "ImageNG.h"


			/*****************/
			/* Constructeurs */			
			/*****************/

ImageNG::ImageNG(void)
{
	Trace("Appel au constructeur par défaut\n");
	id=0;
	nom=0;
	matrice=0;
	setDimension(Dimension::VGA);

}

ImageNG::ImageNG(int a,const char *p)
{
	Trace("Appel au constructeur d'initialisation sans la dimension\n");
	id=a;
	nom=0;
	setNom(p);
	matrice=0;
	setDimension(Dimension::VGA);
}

ImageNG::ImageNG(int a,const char *p,const Dimension& d)
{
	Trace("Appel au constructeur d'initialisation avec la dimension\n");
	id=a;
	nom=0;
	setNom(p);
	matrice=0;
	setDimension(d);
}

ImageNG::ImageNG(const ImageNG& i)
{
	Trace("Appel au constructeur de copie\n");
	id=i.id;
	nom = 0;
	setNom(i.nom);
	matrice=0;
	setDimension(i.dimension);
	
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			matrice[x][y] = i.matrice[x][y];
		}
	}
}
			
			/*****************/
			/* Destructeurs  */			
			/*****************/

ImageNG::~ImageNG()
{
	Trace("Appel au destructeur\n");
	if(nom)
	{
		delete nom;
	}
	if(matrice)
	{
		for(int x=0 ; x<dimension.getLargeur() ; x++)
			delete[] matrice[x];
		delete[] matrice;
	}
}

			/*****************/
			/*    Setters    */			
			/*****************/
			
void ImageNG::setId(const int idpro)
{
	id = idpro;
}

void ImageNG::setNom(const char* nompro)
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

void ImageNG::setDimension(const Dimension& d)
{
	int **mattmp;
	int larg,haut,tmpl,tmph;
	
	mattmp = matrice;

	matrice = new int*[d.getLargeur()];
	for(int x=0 ; x<d.getLargeur() ; x++)
		matrice[x] = new int[d.getHauteur()];

	if(mattmp!=0)
	{	
		tmpl = dimension.getLargeur();
		tmph = dimension.getHauteur();
	
		dimension.setLargeur(d.getLargeur());
		dimension.setHauteur(d.getHauteur());
		
		setBackground(255);
		
		if(tmpl>d.getLargeur())
			larg = d.getLargeur();
		else
			larg = tmpl;
		
		if(tmph>d.getHauteur())
			haut = d.getHauteur();
		else
			haut = tmph;
		
		for(int x=0 ; x<larg ; x++)
		{
			for(int y=0 ; y<haut ; y++)
			{
				setPixel(x,y,mattmp[x][y]);
			}
		}	

		for(int x=0 ; x<tmpl ; x++)
			delete[] mattmp[x];
		delete[] mattmp;
	
		mattmp = 0;
	}
	else
	{
		dimension.setLargeur(d.getLargeur());
		dimension.setHauteur(d.getHauteur());	
	}

}

void ImageNG::setPixel(int x,int y, int val)
{
	matrice[x][y] = val;
}

void ImageNG::setBackground(int val)
{
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			setPixel(x,y,val);
		}
	}
}

			/*****************/
			/*    Getters    */			
			/*****************/

int ImageNG::getId() const
{
	return id;
}

const char* ImageNG::getNom() const
{
	return nom;
}

Dimension ImageNG::getDimension() const
{
	return dimension;
}

int ImageNG::getPixel(int x,int y)
{
	return matrice[x][y];
}


			/*****************/
			/*   Methodes    */			
			/*****************/
			
void ImageNG::Affiche() const
{
	if(nom)
		cout << "Nom = " << getNom() << endl;
	else
		cout << "Nom = Pas de nom" << endl;
   cout << "Id  = " << getId() << endl;
   dimension.Affiche();
}

void ImageNG::Dessine()
{
	WindowSDL::open(dimension.getLargeur(), dimension.getHauteur());
	
	WindowSDLimage im(dimension.getLargeur(),dimension.getHauteur());
		
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			im.setPixel(x,y,matrice[x][y],matrice[x][y],matrice[x][y]);
		}
	}
	WindowSDL::drawImage(im,0,0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

void ImageNG::importFromBMP(const char* fichier)
{
	int pR, pG, pB, val; 
	WindowSDLimage im;
	im.importFromBMP(fichier);
	dimension.setLargeur(im.getWidth());
	dimension.setHauteur(im.getHeight());
	setDimension(dimension);
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			im.getPixel(x,y,&pR,&pG,&pB);
			val=(pR+pG+pB)/3;
			setPixel(x,y,val);
		}
	}
}

void ImageNG::exportToBMP(const char* fichier)
{
	int val;
	WindowSDLimage im(dimension.getLargeur(),dimension.getHauteur());
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			val = getPixel(x,y);
			im.setPixel(x,y,val,val,val);
		}
	}
	im.exportToBMP(fichier);
}












