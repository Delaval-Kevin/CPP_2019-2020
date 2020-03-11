/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 18/10/2019             */
/***********************************************************/

#include "Traitements.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/



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

			
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

		
/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/
					
		
/********************************/
/*                              */
/*           Methodes           */			
/*                              */
/********************************/
			
ImageB Traitements::Seuillage(const ImageNG& imageIn, int seuil)
{
	ImageB imageOut;

	imageOut.setDimension(imageIn.getDimension());
	
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();
	
	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			if(imageIn.getPixel(x, y) > seuil )
				imageOut.setPixel(x, y, true);
			else
				imageOut.setPixel(x, y, false);
		}
	}

	return imageOut;
}

ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille, Pixel p1, Pixel p2)
{
	if((taille%2) == 0)
		throw BaseException("La taille du filtre doit etre impair !");

	ImageNG imageOut(imageIn);
	
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();
	
	/* Inversion des pixels si mal mis */
	
	if(p1.getX() > p2.getX())
	{
		int tmp;
		tmp = p2.getX();
		p2.setX(p1.getX());
		p1.setX(tmp);
	}
	if(p1.getY() > p2.getY())
	{
		int tmp;
		tmp = p2.getY();
		p2.setY(p1.getY());
		p1.setY(tmp);
	}	

	/* Vérification si c'est pour toute l'image */
	
	if(p2.getX() == 0 && p2.getY() == 0 && p1.getX() == 0 && p1.getY() == 0)
	{
		p2.setX(larg);
		p2.setY(haut);
	}
	
	/* Application du filtre */
	
	int p1L, p1H, p2L, p2H;
	
	p1L = p1.getX();
	p1H = p1.getY();
	p2L = p2.getX();
	p2H = p2.getY();
	
	for(int x = p1L ; x < p2L ; x++)
	{
		for(int y = p1H ; y < p2H ; y++)
		{
			int cpt = 0;
			int moyenne = 0;
			
			for(int i = (x-(taille/2)) ; i <= (x+(taille/2)) ; i++)
			{
				for(int j = (y-(taille/2)) ; j <= (y+(taille/2)) ; j++)
				{
					if( i >= 0 && i < larg && j >= 0 && j < haut)
					{
						cpt++;
						moyenne = moyenne + imageIn.getPixel(i,j);
					}
				}
			}
			
			moyenne = moyenne / cpt;
			imageOut.setPixel(x,y,moyenne);
		}
	}
	
	return imageOut;
}

ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille)
{
	if((taille%2) == 0)
		throw BaseException("La taille du filtre doit etre impair !");
		
	ImageNG imageOut(imageIn);

	
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			int cpt = 0;			
			ListeTriee<int> liste;
			Iterateur<int> it(liste);
			
			for(int i = (x-(taille/2)) ; i <= (x+(taille/2)) ; i++)
			{
				for(int j = (y-(taille/2)) ; j <= (y+(taille/2)) ; j++)
				{
					if( i >= 0 && i < larg && j >= 0 && j < haut)
					{
						liste.insere(imageIn.getPixel(i,j));
						cpt++;
					}
				}
			}
			int cur;
			for(it.reset(), cur = 0 ; cur < (cpt/2) ; it++, cur++);
			int tmp = it.remove();
			imageOut.setPixel(x, y, tmp);
		}
	}	
	
	return imageOut;
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille)
{
	if((taille%2) == 0)
		throw BaseException("La taille du filtre doit etre impair !");
		
	ImageNG imageOut(imageIn);
	
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			int min = imageIn.getPixel(x,y);		
			for(int i = (x-(taille/2)) ; i <= (x+(taille/2)) ; i++)
			{
				for(int j = (y-(taille/2)) ; j <= (y+(taille/2)) ; j++)
				{
					if( i >= 0 && i < larg && j >= 0 && j < haut)
					{
						if(min > imageIn.getPixel(i,j))
							min = imageIn.getPixel(i,j);
					}
				}
			}
			imageOut.setPixel(x, y, min);
		}
	}
		
	return imageOut;
}
ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille)
{
	if((taille%2) == 0)
		throw BaseException("La taille du filtre doit etre impair !");
		
	ImageNG imageOut(imageIn);
	
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			int max = imageIn.getPixel(x,y);		
			for(int i = (x-(taille/2)) ; i <= (x+(taille/2)) ; i++)
			{
				for(int j = (y-(taille/2)) ; j <= (y+(taille/2)) ; j++)
				{
					if( i >= 0 && i < larg && j >= 0 && j < haut)
					{
						if(max < imageIn.getPixel(i,j))
							max = imageIn.getPixel(i,j);
					}
				}
			}
			imageOut.setPixel(x, y, max);
		}
	}
			
	return imageOut;
}

ImageNG Traitements::Negatif(const ImageNG& imageIn)
{
	ImageNG imageOut(imageIn);

	int tmp;
	int haut = imageIn.getDimension().getHauteur();
	int larg = imageIn.getDimension().getLargeur();

	for(int x = 0 ; x < larg ; x++)
	{
		for(int y = 0 ; y < haut ; y++)
		{
			tmp = 255 - imageIn.getPixel(x,y);
			imageOut.setPixel(x, y, tmp);
		}
	}	

	return imageOut;
}





