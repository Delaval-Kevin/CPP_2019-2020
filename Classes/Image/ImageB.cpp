/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/10/2019             */
/***********************************************************/

#include "ImageB.h"

Couleur ImageB::couleurTrue = Couleur::BLANC;
Couleur ImageB::couleurFalse = Couleur::NOIR;

//Constructeur par défaut
ImageB::ImageB(void):Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet sans la dimension
ImageB::ImageB(int a,const char *p):Image(a, p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet avec la dimension
ImageB::ImageB(int a,const char *p,const Dimension& d):Image(a, p, d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension");
	#endif
	MatValid = false;
	setDimension(d);
}

//Constructeur de copie
ImageB::ImageB(const ImageB& i):Image(i)
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

ImageB::~ImageB()
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

const ImageB& ImageB::operator=(const ImageB& i)
{
	id=i.id;
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
ostream& operator<<(ostream& s, const ImageB& i)
{
	if(i.nom == 0)
	{
		s << "Id : " << i.getId() << " Nom : pas de nom" << i.getDimension();
		return s;
	}

	s << "Id : " << i.getId() << " Nom : " << i.getNom() << i.getDimension();
	return s;
}

//Remplace un pixel dans l'image
ImageB ImageB::operator+(const PixelB& p)
{
	ImageB tmp(*this);

	tmp.setPixel(p.getX(),p.getY(),p.getValeur());
	
	return tmp;
}

//Remplace un pixel dans l'image
ImageB operator+(const PixelB& p, const ImageB& i)
{
	ImageB tmp(i);
	return tmp + p;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void ImageB::setDimension(const Dimension& d)
{
	Matrice<bool> mattmp;
	Dimension dimTmp(dimension);
	
	mattmp = matrice;
		
	Image::setDimension(d);

	matrice.setHauteur(dimension.getHauteur());
	matrice.setLargeur(dimension.getLargeur());
	
	
	setBackground(false);
	
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

void ImageB::setPixel(int x, int y, bool valeur)
{
	if(x >= dimension.getLargeur() || y >= dimension.getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	matrice(x,y) = valeur;
}

void ImageB::setBackground(bool valeur)
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



bool ImageB::getPixel(int x,int y) const
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
			
void ImageB::Affiche() const
{
	cout << "Type      : B" << endl;
	
	cout << "Id        : " << getId() << endl;;
	
	if(nom)
		cout << "Nom       : " << getNom() << endl;
	else
		cout << "Nom       : pas de nom" << endl;;
	
	cout << "Dimension :" << getDimension() << endl;
}

//Permet d'afficher l'image dans une fenêtre et ouvre la fenêtre
void ImageB::Dessine() const
{
	bool val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDL::open(larg, haut);
	
	WindowSDLimage im(larg, haut);
		
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = getPixel(x,y);
			if(val == true)
				im.setPixel(x,y,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
			else
				im.setPixel(x,y,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
		}
	}
	WindowSDL::drawImage(im,0,0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

//Permet d'afficher l'image dans une fenêtre aux coordonées donné sans ouvrir de fenêtre
void ImageB::Dessine(int x, int y) const
{
	bool val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
		WindowSDLimage im(larg, haut);
		
	for(int i = 0 ; i < larg ; i++)
	{
		for(int j = 0 ; j < haut ; j++)
		{
			val = getPixel(i,j);
			if(val == true)
				im.setPixel(i,j,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
			else
				im.setPixel(i,j,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
		}
	}
	
	WindowSDL::drawImage(im,x,y);
}


//Enregistre une image dans un dossier
void ImageB::exportToBMP(const char* fichier)
{
	bool val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDLimage im(larg, haut);
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = getPixel(x,y);
			if(val == true)
				im.setPixel(x,y,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
			else
				im.setPixel(x,y,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
		}
	}
	im.exportToBMP(fichier);
}

//Sauvegarde la dimension avec l'image dans un fichier via les flux
void ImageB::Save(ofstream &fichier) const
{
	bool val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	Image::Save(fichier);	
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = getPixel(x, y);
			fichier.write((char*)&val, sizeof(val));
		}
	}
}

//Charge la dimension et l'image dans un fichier via les flux
void ImageB::Load(ifstream &fichier)
{
	bool val;
	
	Image::Load(fichier);
	
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			fichier.read((char*)&val, sizeof(val));
			setPixel(x, y, val);
		}
	}
}



