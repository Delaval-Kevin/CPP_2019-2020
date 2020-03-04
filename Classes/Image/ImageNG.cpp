/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 10/10/2019             */
/***********************************************************/

#include "ImageNG.h"

//Initialisation de la variable membre statiques
const int ImageNG::LUMINANCE = 0;
const int ImageNG::PIXEL_A_PIXEL = 1;
int ImageNG::comparaison = 0;

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/


//Constructeur par défaut
ImageNG::ImageNG(void):Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation par le nom
ImageNG::ImageNG(const char *p):Image()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation par le nom");
	#endif
	setNom(p);
	MatValid = false;
	importFromBMP(p);
}

//Constructeur d'initialisation complet sans la dimension
ImageNG::ImageNG(int a,const char *p):Image(a, p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension");
	#endif
	MatValid = false;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet avec la dimension
ImageNG::ImageNG(int a,const char *p,const Dimension& d):Image(a, p, d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension");
	#endif
	MatValid = false;
	setDimension(d);
}

//Constructeur de copie
ImageNG::ImageNG(const ImageNG& i):Image(i)
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

ImageNG::~ImageNG()
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

const ImageNG& ImageNG::operator=(const ImageNG& i)
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
ostream& operator<<(ostream& s, const ImageNG& i)
{
	if(i.nom == 0)
	{
		s<< "Id : " << i.getId() << " Nom : pas de nom" << i.getDimension() << " Luminance : " << i.getLuminance() << " Contraste : " << i.getContraste();
		return s;
	}

	s<< "Id : " << i.getId() << " Nom : " << i.getNom() << i.getDimension() << " Luminance : " << i.getLuminance() << " Contraste : " << i.getContraste();
	return s;
}

//Augmente la luminance de l'image
ImageNG ImageNG::operator+(int lum)
{
	ImageNG tmp(*this);
	int haut = tmp.dimension.getHauteur();
	int larg = tmp.dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			if(tmp.getPixel(x,y)+lum > 250)
				tmp.setPixel(x,y,250);
			else	
				tmp.setPixel(x,y,(tmp.getPixel(x,y)+lum));
		}
	}
	return tmp;
}

//Augmente la luminance de l'image
ImageNG operator+(int lum, const ImageNG& i)
{
	ImageNG tmp(i);
	return tmp + lum;
}

//Remplace un pixel dans l'image
ImageNG ImageNG::operator+(const PixelNG& p)
{
	ImageNG tmp(*this);

	tmp.setPixel(p.getX(),p.getY(),p.getValeur());
	
	return tmp;
}

//Remplace un pixel dans l'image
ImageNG operator+(const PixelNG& p, const ImageNG& i)
{
	ImageNG tmp(i);
	return tmp + p;
}

//Diminue la luminance de l'image
ImageNG ImageNG::operator-(int lum)
{
	ImageNG tmp(*this);	
	int haut = tmp.dimension.getHauteur();
	int larg = tmp.dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			if(tmp.getPixel(x,y)-lum < 0)
				tmp.setPixel(x,y,0);
			else
				tmp.setPixel(x,y,(tmp.getPixel(x,y)-lum));
		}
	}
	return tmp;
}

//Soustrait les pixels d'une image à l'autre
ImageNG ImageNG::operator-(const ImageNG& i)
{
	if(dimension != i.dimension)
		throw XYException('d',"Soustraction impossible !");

	ImageNG tmp(*this);
	int val;
	int haut = tmp.dimension.getHauteur();
	int larg = tmp.dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = tmp.getPixel(x,y)-i.getPixel(x,y);
			if(val < 0)
				val = 0;
				
			tmp.setPixel(x,y,val);
		}
	}
	return tmp;
}

//pré-incrémentation de la luminance
ImageNG ImageNG::operator++()
{
	*this = (*this)+20;
	return *this;
}

//post-incrémentation de la luminance
ImageNG ImageNG::operator++(int)
{
	ImageNG tmp(*this);
	*this = (*this)+20;
	return tmp;
}

// pré-décrémentation de la luminance
ImageNG ImageNG::operator--()
{
	*this = (*this)-20;
	return *this;
}

//post-décrémentation de la luminance
ImageNG ImageNG::operator--(int)
{
	ImageNG tmp(*this);
	*this = (*this)-20;
	return tmp;
}

bool ImageNG::operator==(const ImageNG& i)
{
	//Comparaison sur la luminance
	if(comparaison == 0)
	{
		if(getLuminance() == i.getLuminance())
			return true;
		else
			return false;
	}
	//Comparaison pixel à pixel
	else
	{
		if(dimension != i.dimension)
			throw XYException('d',"Comparaison impossible !");
		
		int haut = dimension.getHauteur();
		int larg = dimension.getLargeur();	
		
		for(int x = 0 ; x < larg ; x++)
		{
			for(int y = 0 ; y < haut ; y++)
			{
				if(getPixel(x,y) != i.getPixel(x,y))
					return false;
			}
		}
		return true;		
	}
}
	
bool ImageNG::operator<(const ImageNG& i)
{
	//Comparaison sur la luminance
	if(comparaison == 0)
	{
		if(getLuminance() < i.getLuminance())
			return true;
		else
			return false;	
	}
	//Comparaison pixel à pixel
	else
	{
		if(dimension != i.dimension)
			throw XYException('d',"Comparaison impossible !");

		int haut = dimension.getHauteur();
		int larg = dimension.getLargeur();
			
		for(int x = 0 ; x < larg ; x++)
		{
			for(int y = 0 ; y < haut ; y++)
			{
				if(getPixel(x,y) >= i.getPixel(x,y))
					return false;
			}
		}
		return true;	
	}
}

bool ImageNG::operator>(const ImageNG& i)
{
	//Comparaison sur la luminance
	if(comparaison == 0)
	{
		if(getLuminance() > i.getLuminance())
			return true;
		else
			return false;	
	}
	//Comparaison pixel à pixel
	else
	{
		if(dimension != i.dimension)
			throw XYException('d',"Comparaison impossible !");

		int haut = dimension.getHauteur();
		int larg = dimension.getLargeur();
	
		for(int x = 0 ; x < larg ; x++)
		{
			for(int y = 0 ; y < haut ; y++)
			{
				if(getPixel(x,y) <= i.getPixel(x,y))
					return false;
			}
		}
		return true;	
	}
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void ImageNG::setDimension(const Dimension& d)
{
	Matrice<int> mattmp;
	Dimension dimTmp(dimension);
	
	mattmp = matrice;
		
	Image::setDimension(d);
	
	matrice.setHauteur(dimension.getHauteur());
	matrice.setLargeur(dimension.getLargeur());
	
	setBackground(0);
	
	if(MatValid == true) // pour voir si c'est le premier passage dans la fonction si oui
	{							// les valeurs de la matrice sont aléatoires et donc pas à recopier
	
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

void ImageNG::setPixel(int x,int y, int val)
{
	if(val>255 || val<0)
		throw RGBException(val,"Niveau de gris invalide");
	if(x >= dimension.getLargeur() || y >= dimension.getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	matrice(x,y) = val;
}

void ImageNG::setBackground(int val)
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			setPixel(x,y,val);
		}
	}
}

void ImageNG::setComparaison(int c)
{
	comparaison = c;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/



int ImageNG::getPixel(int x,int y) const
{
	if(x >= dimension.getLargeur() || y >= dimension.getHauteur())
		throw XYException('d',"Coordonnes pixel invalides");
		
	return matrice(x,y);
}

//Retourne la luminance moyenne de l'image
int ImageNG::getLuminance() const
{
	int lum = 0;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			lum = lum + getPixel(x,y);
		}
	}
	
	lum = lum/(larg * haut);
	
	return lum;
}

//Retourne le pixel a la valeur la plus basse
int ImageNG::getMinimum() const
{
	int min;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	min = getPixel(0,0);
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			if(min > getPixel(x,y))
				min = getPixel(x,y);
		}
	}
	return min;
}

//Retourne le pixel a la valeur la plus haute
int ImageNG::getMaximum() const
{
	int max;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	max = getPixel(0,0);
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			if(max < getPixel(x,y))
				max = getPixel(x,y);
		}
	}
	return max;
}

float ImageNG::getContraste() const
{
	float cont;
	
	if(getMaximum() == 0)
		return 0;

	cont = (float)(getMaximum() - getMinimum())/(float)(getMaximum() + getMinimum());

	return cont;
}

int ImageNG::getComparaison() const
{
	return comparaison;
}

/********************************/
/*                              */
/*           Methodes           */			
/*                              */
/********************************/
			
void ImageNG::Affiche() const
{
	cout << "Type      : NG" << endl;
	
	cout << "Id        : " << getId() << endl;;
	
	if(nom)
		cout << "Nom       : " << getNom() << endl;
	else
		cout << "Nom       : pas de nom" << endl;;
	
	cout << "Dimension :" << getDimension() << endl;
	cout << "Luminance : " << getLuminance() << endl;
	cout << "Contraste : " << getContraste() << endl;
	cout << "Minimum   : " << getMinimum() << endl;
	cout << "Maximum   : " << getMaximum() << endl;
}

//Permet d'afficher l'image dans une fenêtre et ouvre la fenêtre
void ImageNG::Dessine() const
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDL::open(larg, haut);
	
	WindowSDLimage im(larg, haut);
		
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			im.setPixel(x,y,getPixel(x,y),getPixel(x,y),getPixel(x,y));
		}
	}
	WindowSDL::drawImage(im,0,0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

//Permet d'afficher l'image dans une fenêtre aux coordonées donné sans ouvrir de fenêtre
void ImageNG::Dessine(int x, int y) const
{
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDLimage im(larg, haut);
		
	for(int i = 0 ; i < larg ; i++)
	{
		for(int j = 0 ; j < haut ; j++)
		{
			im.setPixel(i,j,getPixel(i,j),getPixel(i,j),getPixel(i,j));
		}
	}
	WindowSDL::drawImage(im,x,y);
}

//Importe une image d'un dossier
void ImageNG::importFromBMP(const char* fichier)
{
	int pR, pG, pB, val;
	
	WindowSDLimage im;
	try
	{
		im.importFromBMP(fichier);
	}
	catch(WindowSDLexception Wxc)
	{
		throw BaseException(Wxc.getMessage());
	}
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
			val=(pR+pG+pB)/3;
			setPixel(x,y,val);
		}
	}
}

//Enregistre une image dans un dossier
void ImageNG::exportToBMP(const char* fichier)
{
	int val;
	int haut = dimension.getHauteur();
	int larg = dimension.getLargeur();
	
	WindowSDLimage im(larg, haut);

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			val = getPixel(x,y);
			im.setPixel(x,y,val,val,val);
		}
	}
	im.exportToBMP(fichier);
}

//Sauvegarde la dimension avec l'image dans un fichier via les flux
void ImageNG::Save(ofstream &fichier) const
{
	int val;
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
void ImageNG::Load(ifstream &fichier)
{
	int val;
	
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










