/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#include "ImageRGB.h"

//Constructeur par défaut
ImageRGB::ImageRGB(void):Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation par le nom
ImageRGB::ImageRGB(const char *p):Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation par le nom");
	#endif
	setNom(p);
	MatValid = false;
	importFromBMP(p);
}

//Constructeur d'initialisation complet sans la dimension
ImageRGB::ImageRGB(int a,const char *p):Image(a, p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet avec la dimension
ImageRGB::ImageRGB(int a,const char *p,const Dimension& d):Image(a , p, d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension");
	#endif
	MatValid = false;
	setDimension(d);
}

//Constructeur de copie
ImageRGB::ImageRGB(const ImageRGB& i):Image(i)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	MatValid = false;
	setDimension(i.getDimension());
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setPixel(x,y,i.getPixel(x,y));
		}
	}
}

/********************************/
/*                              */
/*         Destructeurs         */			
/*                              */
/********************************/

ImageRGB::~ImageRGB()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif

}

/********************************/
/*                              */
/*            Operator          */			
/*                              */
/********************************/

const ImageRGB& ImageRGB::operator=(const ImageRGB& i)
{
	id = i.id;
	setNom(i.nom);
	setDimension(i.dimension);
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setPixel(x,y,i.getPixel(x,y));
		}
	}
	return *this;
}

//Opérateur << du cout
ostream& operator<<(ostream& s, const ImageRGB& i)
{
	if(i.nom == 0)
	{
		s << "Id : " << i.getId() << " Nom : pas de nom" << i.getDimension();
		return s;
	}

	s << "Id : " << i.getId() << " Nom : " << i.nom << i.getDimension();
	return s;
}

//Remplace un pixel dans l'image
ImageRGB ImageRGB::operator+(const PixelRGB& p)
{
	ImageRGB tmp(*this);

	tmp.setPixel(p.getX(),p.getY(),p.getValeur());
	
	return tmp;
}

//Remplace un pixel dans l'image
ImageRGB operator+(const PixelRGB& p, const ImageRGB& i)
{
	ImageRGB tmp(i);
	return tmp + p;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void ImageRGB::setDimension(const Dimension& d)
{
	Matrice<Couleur> mattmp;
	Dimension dimTmp(dimension);
	
	mattmp = matrice;
		
	Image::setDimension(d);
	
	matrice.setHauteur(dimension.getHauteur());
	matrice.setLargeur(dimension.getLargeur());
	
	if(MatValid == true)
	{	
		int haut = d.getHauteur();
		int larg = d.getLargeur();
		int hautTmp = dimTmp.getHauteur();
		int largTmp = dimTmp.getLargeur();
	
		for(int x = 0 ; x < largTmp && x < larg ; x++)
		{
			for(int y = 0 ; y < hautTmp && y < haut ; y++)
			{
				setPixel(x,y,mattmp(x,y));
			}
		}	
	}
	else
	{
		MatValid = true;
	}
}

void ImageRGB::setPixel(int x,int y, const Couleur& valeur)
{
	if(x >= dimension.getLargeur() || y >= dimension.getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	matrice(x,y) = valeur;
}

void ImageRGB::setBackground(const Couleur& valeur)
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setPixel(x,y,valeur);
		}
	}
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/



Couleur ImageRGB::getPixel(int x,int y) const
{
	if(x >= dimension.getLargeur() || y >= dimension.getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	return matrice(x,y);
}

/********************************/
/*                              */
/*           Methodes           */			
/*                              */
/********************************/
			
void ImageRGB::Affiche() const
{
	cout << "Type      : RGB" << endl;
	
	cout << "Id        : " << getId() << endl;;
	
	if(nom)
		cout << "Nom       : " << getNom() << endl;
	else
		cout << "Nom       : pas de nom" << endl;;
	
	cout << "Dimension :" << getDimension() << endl;
}

//Permet d'afficher l'image dans une fenêtre et ouvre la fenêtre
void ImageRGB::Dessine() const
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDL::open(larg, haut);
	
	WindowSDLimage im(larg, haut);
		
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			im.setPixel(x,y,getPixel(x,y).getRouge(),getPixel(x,y).getVert(),getPixel(x,y).getBleu());
		}
	}
	WindowSDL::drawImage(im,0,0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

//Permet d'afficher l'image dans une fenêtre aux coordonées donné sans ouvrir de fenêtre
void ImageRGB::Dessine(int x, int y) const
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDLimage im(larg, haut);
		
	for(int i = 0 ; i < larg ; i++)
	{
		for(int j = 0 ; j < haut ; j++)
		{
			im.setPixel(i,j,getPixel(i,j).getRouge(),getPixel(i,j).getVert(),getPixel(i,j).getBleu());
		}
	}
	WindowSDL::drawImage(im,x,y);
}

//Importe une image d'un dossier
void ImageRGB::importFromBMP(const char* fichier)
{
	int pR, pG, pB;
	Couleur c;
	WindowSDLimage im;
	im.importFromBMP(fichier);
	dimension.setLargeur(im.getWidth());
	dimension.setHauteur(im.getHeight());
	
	setDimension(dimension);
	
	setNom(fichier);
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			im.getPixel(x,y,&pR,&pG,&pB);
			c.setRouge(pR);
			c.setVert(pG);
			c.setBleu(pB);
			setPixel(x,y,c);
		}
	}
}

//Enregistre une image dans un dossier
void ImageRGB::exportToBMP(const char* fichier)
{
	Couleur c;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDLimage im(larg, haut);
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			c = getPixel(x,y);
			im.setPixel(x,y,c.getRouge(),c.getVert(),c.getBleu());
		}
	}
	im.exportToBMP(fichier);
}

//Sauvegarde la dimension avec l'image dans un fichier via les flux
void ImageRGB::Save(ofstream &fichier) const
{
	Couleur val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	Image::Save(fichier);
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = getPixel(x, y);
			val.Save(fichier);
		}
	}
	
}

//Charge la dimension et l'image dans un fichier via les flux
void ImageRGB::Load(ifstream &fichier)
{
	Couleur val;
	
	Image::Load(fichier);
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val.Load(fichier);
			setPixel(x, y, val);
		}
	}
}

ImageNG ImageRGB::getRouge() const
{
	Couleur c;
	ImageNG image;
	
	image.setDimension(getDimension());
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			c = getPixel(x,y);
			image.setPixel(x, y, c.getRouge());
		}
	}
	
	return image;
}

ImageNG ImageRGB::getVert() const
{
	Couleur c;
	ImageNG image;
	
	image.setDimension(getDimension());
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			c = getPixel(x,y);
			image.setPixel(x, y, c.getVert());
		}
	}
	
	return image;
}

ImageNG ImageRGB::getBleu() const
{
	Couleur c;
	ImageNG image;
	
	image.setDimension(getDimension());
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			c = getPixel(x,y);
			image.setPixel(x, y, c.getBleu());
		}
	}
	
	return image;
}

void ImageRGB::setRGB(const ImageNG &r, const ImageNG &g, const ImageNG &b)
{
	Couleur c;

	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			c.setRouge(r.getPixel(x, y));
			c.setVert(g.getPixel(x, y));
			c.setBleu(b.getPixel(x, y));
			setPixel(x, y, c);
		}
	}
}




