/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo                                                     */
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
ImageNG::ImageNG(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut\n");
	#endif
	id=0;
	nom=0;
	matrice=0;
	setDimension(Dimension::VGA);

}

//Constructeur d'initialisation par le nom
ImageNG::ImageNG(const char *p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation par le nom\n");
	#endif
	id=0;
	nom=0;
	setNom(p);
	matrice=0;
	importFromBMP(p);
}

//Constructeur d'initialisation complet sans la dimension
ImageNG::ImageNG(int a,const char *p)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation sans la dimension\n");
	#endif
	id=a;
	nom=0;
	setNom(p);
	matrice=0;
	setDimension(Dimension::VGA);
}

//Constructeur d'initialisation complet avec la dimension
ImageNG::ImageNG(int a,const char *p,const Dimension& d)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec la dimension\n");
	#endif
	id=a;
	nom=0;
	setNom(p);
	matrice=0;
	setDimension(d);
}

//Constructeur de copie
ImageNG::ImageNG(const ImageNG& i)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie\n");
	#endif
	id=i.id;
	nom = 0;
	setNom(i.getNom());
	matrice=0;
	setDimension(i.getDimension());
	
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
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
	TraceConstructeur("Appel au destructeur\n");
	#endif
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

/********************************/
/*                              */
/*            Operator          */			
/*                              */
/********************************/

ImageNG& ImageNG::operator=(const ImageNG& i)
{
	id=i.id;
//	nom = 0; Perte de mémoire car l'objet appelant est déjà crée et à donc déjà été initialisé!!!
	setNom(i.nom);
//	matrice=0; Perte de mémoire car l'objet appelant est déjà crée et à donc déjà été initialisé!!!
	setDimension(i.dimension);
	
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			setPixel(x,y,i.getPixel(x,y));
		}
	}
	return *this;
}

//Opérateur << du cout
ostream& operator<<(ostream& s, const ImageNG& i)
{
	if(i.nom==0)
	{
		s<< " Nom : pas de nom" << i.dimension << " Luminance : " << i.getLuminance() << " Contraste : " << i.getContraste() << endl;
		return s;
	}

	s<< " Nom : " << i.nom << i.dimension << " Luminance : " << i.getLuminance() << " Contraste : " << i.getContraste() << endl;
	return s;
}

//Augmente la luminance de l'image
ImageNG operator+(const ImageNG& i, int lum)
{
	ImageNG tmp(i);
	for(int x=0 ; x<tmp.dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<tmp.dimension.getHauteur() ; y++)
		{
			tmp.setPixel(x,y,(tmp.getPixel(x,y)+lum));
			if(tmp.getPixel(x,y)>255)
				tmp.setPixel(x,y,255);
		}
	}
	return tmp;
}

//Augmente la luminance de l'image
ImageNG operator+(int lum, const ImageNG& i)
{
	return i + lum;
}

//Remplace un pixel dans l'image
ImageNG operator+(const ImageNG& i, const PixelNG& p)
{
	ImageNG tmp(i);

	tmp.setPixel(p.getX(),p.getY(),p.getValeur());
	
	return tmp;
}

//Remplace un pixel dans l'image
ImageNG operator+(const PixelNG& p, const ImageNG& i)
{
	return i + p;
}

//Diminue la luminance de l'image
ImageNG operator-(const ImageNG& i, int lum)
{
	ImageNG tmp(i);
	for(int x=0 ; x<tmp.dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<tmp.dimension.getHauteur() ; y++)
		{
			tmp.setPixel(x,y,(tmp.getPixel(x,y)-lum));
			if(tmp.getPixel(x,y)<0)
				tmp.setPixel(x,y,0);
		}
	}
	return tmp;
}

//Soustrait les pixels d'une image à l'autre
ImageNG operator-(const ImageNG& i1, const ImageNG& i2)
{
	ImageNG tmp(i1);
	for(int x=0 ; x<tmp.dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<tmp.dimension.getHauteur() ; y++)
		{
			tmp.setPixel(x,y,(tmp.getPixel(x,y)-i2.getPixel(x,y)));
			if(tmp.getPixel(x,y)<0)
				tmp.setPixel(x,y,0);
		}
	}
	return tmp;
}

//pré-incrémentation de la luminance
ImageNG ImageNG::operator++()
{
	(ImageNG)(*this)=(*this)+20;
	return *this;
}

//post-incrémentation de la luminance
ImageNG ImageNG::operator++(int)
{
	ImageNG tmp(*this);
	*this=(*this)+20;
	return tmp;
}

// pré-décrémentation de la luminance
ImageNG ImageNG::operator--()
{
	(ImageNG)(*this)=(*this)-20;
	return *this;
}

//post-décrémentation de la luminance
ImageNG ImageNG::operator--(int)
{
	ImageNG tmp(*this);
	*this=(*this)-20;
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
		for(int x=0 ; x<dimension.getLargeur() ; x++)
		{
			for(int y=0 ; y<dimension.getHauteur() ; y++)
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
		for(int x=0 ; x<dimension.getLargeur() ; x++)
		{
			for(int y=0 ; y<dimension.getHauteur() ; y++)
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
		for(int x=0 ; x<dimension.getLargeur() ; x++)
		{
			for(int y=0 ; y<dimension.getHauteur() ; y++)
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
	int **mattmp;
	Dimension dimTmp(dimension);
	
	mattmp = matrice;

	matrice = new int*[d.getLargeur()];
	for(int x=0 ; x<d.getLargeur() ; x++)
		matrice[x] = new int[d.getHauteur()];
		
	dimension.setLargeur(d.getLargeur());
	dimension.setHauteur(d.getHauteur());
	
	setBackground(0);

	if(mattmp!=0)
	{	
		for(int x=0 ; x<dimTmp.getLargeur() && x<d.getLargeur() ; x++)
		{
			for(int y=0 ; y<dimTmp.getHauteur() && y<d.getHauteur() ; y++)
			{
				setPixel(x,y,mattmp[x][y]);
			}
		}	

		for(int x=0 ; x<dimTmp.getLargeur() ; x++)
			delete[] mattmp[x];
		delete[] mattmp;
	
		mattmp = 0;
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
	return matrice[x][y];
}

//Retourne la luminance moyenne de l'image
int ImageNG::getLuminance() const
{
	int lum=0;
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			lum = lum + getPixel(x,y);
		}
	}
	
	lum = lum/(dimension.getLargeur()*dimension.getHauteur());
	
	return lum;
}

//Retourne le pixel a la valeur la plus basse
int ImageNG::getMinimum() const
{
	int min;
	min = getPixel(0,0);
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			if(min>getPixel(x,y))
				min=getPixel(x,y);
		}
	}
	return min;
}

//Retourne le pixel a la valeur la plus haute
int ImageNG::getMaximum() const
{
	int max;
	max = getPixel(0,0);
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			if(max<getPixel(x,y))
				max=getPixel(x,y);
		}
	}
	return max;
}

float ImageNG::getContraste() const
{
	float cont;

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
	if(nom)
		cout << "Nom = " << getNom() << endl;
	else
		cout << "Nom = Pas de nom" << endl;
   cout << "Id  = " << getId() << endl;
   dimension.Affiche();
}

//Permet d'afficher l'image dans une fenêtre
void ImageNG::Dessine()
{
	WindowSDL::open(dimension.getLargeur(), dimension.getHauteur());
	
	WindowSDLimage im(dimension.getLargeur(),dimension.getHauteur());
		
	for(int x=0 ; x<dimension.getLargeur() ; x++)
	{
		for(int y=0 ; y<dimension.getHauteur() ; y++)
		{
			im.setPixel(x,y,getPixel(x,y),getPixel(x,y),getPixel(x,y));
		}
	}
	WindowSDL::drawImage(im,0,0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

//Importe une image d'un dossier
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

//Enregistre une image dans un dossier
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












