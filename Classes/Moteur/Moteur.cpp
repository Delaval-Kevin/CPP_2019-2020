/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Moteur                                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/11/2019             */
/***********************************************************/

#include "Moteur.h"

int Moteur::cpt = 0;

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
Moteur::Moteur(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	
	fichierLog.open("traces.log", std::ofstream::app);
	
	fichierLog << "Demarrage du moteur" << endl;

}


/********************************/
/*                              */
/*         Destructeurs         */			
/*                              */
/********************************/

Moteur::~Moteur()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	
	fichierLog << "Fermeture du moteur" << endl;
	if(fichierLog)
		fichierLog.close();
}			
	
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

int Moteur::Insere(Image *pImage)
{

    ImageB* pB = dynamic_cast<ImageB*>(pImage);
    if (pB != NULL)
    {
    	cpt++;
    	pB->setId(cpt);
    	imagesB.insere(*pB);
    	fichierLog << "Insertion d'une imageB avec l'id : " << cpt << endl;
    }
    ImageNG* pNG = dynamic_cast<ImageNG*>(pImage);
    if (pNG != NULL) 
    {
    	cpt++;
    	pNG->setId(cpt);
		ImageNG::setComparaison(ImageNG::LUMINANCE);
		imagesNG.insere(*pNG);
		fichierLog << "Insertion d'une imageNG avec l'id : " << cpt << endl;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pImage);
    if (pRGB != NULL) 
    {
    	cpt++;
    	pRGB->setId(cpt);
    	imagesRGB.insere(*pRGB);
    	fichierLog << "Insertion d'une imageRGB avec l'id : " << cpt << endl;
    }

	

	return cpt;
}

ImageNG Moteur::GetImageNG(int id)
{
	if(!imagesNG.estVide())
	{
		ImageNG imTest;
		Iterateur<ImageNG> it(imagesNG);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		if(stop == 1)
			return (it);
	}

	throw MoteurException("Id de l'image est inconnu !");

}
	
Image* Moteur::GetImage(int id)
{
	Image *imageOut;

	if(!imagesNG.estVide())
	{
		ImageNG imTest;
		Iterateur<ImageNG> it(imagesNG);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		
		if(stop == 1)
		{
			imageOut = &(it.getpCur()->valeur);
			return imageOut;
		}
	}

	if(!imagesRGB.estVide())
	{
		ImageRGB imTest;
		Iterateur<ImageRGB> it(imagesRGB);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		if(stop == 1)
		{
			imageOut = &(it.getpCur()->valeur);
			return imageOut;
		}
	}

	if(!imagesB.estVide())
	{
		ImageB imTest;
		Iterateur<ImageB> it(imagesB);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		if(stop == 1)
		{
			imageOut = &(it.getpCur()->valeur);
			return imageOut;
		}
	}
	throw MoteurException("Id de l'image est inconnu !");
}

void Moteur::Affiche()
{
	cout << "------- Images NG --------------------------------------------------------------------------------------" << endl;
	if(!imagesNG.estVide())
	{
		imagesNG.Affiche();
	}

	cout << "------- Images RGB -------------------------------------------------------------------------------------" << endl;
	if(!imagesRGB.estVide())
	{
		imagesRGB.Affiche();
	}
	
	cout << "------- Images B ---------------------------------------------------------------------------------------" << endl;
	if(!imagesB.estVide())
	{
		imagesB.Affiche();
	}	
}

void Moteur::SupprimeImage(int id)
{
	if(!imagesNG.estVide())
	{
		ImageNG imTest;
		Iterateur<ImageNG> it(imagesNG);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		
		if(stop == 1)
		{
			it.remove();
			fichierLog << "Suppression d'une imageNG avec l'id : " << id << endl;
			return;
		}
	}

	if(!imagesRGB.estVide())
	{
		ImageRGB imTest;
		Iterateur<ImageRGB> it(imagesRGB);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		
		if(stop == 1)
		{
			it.remove();
			fichierLog << "Suppression d'une imageRGB avec l'id : " << id << endl;
			return;
		}
	}
	
	if( imagesB.estVide())
	{
		ImageB imTest;
		Iterateur<ImageB> it(imagesB);
		int stop = 0;
		it.reset();
		while(!it.end() && stop == 0)
		{
			imTest = (it);
			if(imTest.getId() == id)
				stop = 1;
			else
				it++;
		}
		
		if(stop == 1)
		{
			it.remove();
			fichierLog << "Suppression d'une imageB avec l'id : " << id << endl;
			return;
		}
	}
	throw MoteurException("Id de l'image est inconnu !");
}

int Moteur::ImporteImageNG(const char *fichier)
{
	int id;
	ImageNG image;
	try
	{
		image.importFromBMP(fichier);
		fichierLog << "Importation d'une imageNG avec le nom : " << fichier << endl;
	}
	catch(BaseException bEx)
	{
		throw MoteurException(bEx.getMessage());
	}
	
	id = Insere(&image);
	
	return id;
}

int Moteur::ImporteImageRGB(const char * fichier)
{
	int id;
	ImageRGB image;
	try
	{
		image.importFromBMP(fichier);
		fichierLog << "Importation d'une imageRGB avec le nom : " << fichier << endl;
	}
	catch(BaseException bEx)
	{
		throw MoteurException(bEx.getMessage());
	}
	
	id = Insere(&image);
	return id;
}
	
void Moteur::VisualiseImage(int id)
{
	Image *image = this->GetImage(id);
	image->Affiche();
	image->Dessine();
}

void Moteur::VisualiseImages(int id1, int id2)
{
	int hautMax;
	Image *image1;
	Image *image2;
	Dimension Dim1;
	Dimension Dim2;
	
	image1 = GetImage(id1);
	image2 = GetImage(id2);
	
	Dim1 = image1->getDimension();
	Dim2 = image2->getDimension();
	
	if(Dim1.getHauteur() > Dim2.getHauteur())
		hautMax = Dim1.getHauteur();
	else
		hautMax = Dim2.getHauteur();
	
	WindowSDL::open((Dim1.getLargeur() + Dim2.getLargeur()), hautMax);
	WindowSDL::setBackground(0, 0, 0);

	image1->Dessine(0, 0);
	image2->Dessine(Dim1.getLargeur(), 0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}
	
void Moteur::ExporterBMP(int id, const char* fichier)
{
	char nom[80];
	strcpy(nom, "../images/");
	strcat(nom, fichier);
	strcat(nom, ".bmp");
	Image *image = this->GetImage(id);
	image->exportToBMP(nom);
	fichierLog << "Exportation d'une image avec le nom : " << fichier << endl;
}

int Moteur::AugmenteLuminosite(int id, int val)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
		imageTmp = *pNG + val;
		fichierLog << "Augmentation de la luminosite de l'imageNG id : " << id << " de valeur : " << val << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
		imageR = imageR + val;
		imageG = pRGB->getVert();
		imageG = imageG + val;
		imageB = pRGB->getBleu();
		imageB = imageB + val;
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Augmentation de la luminosite de l'imageRGB id : " << id << " de valeur : " << val << endl;
		idTmp = Insere(&image);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
	return 0;
}

int Moteur::DiminueLuminosite(int id, int val)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
		imageTmp = *pNG - val;
		fichierLog << "Diminution de la luminosite de l'imageNG id : " << id << " de valeur : " << val << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
		imageR = imageR - val;
		imageG = pRGB->getVert();
		imageG = imageG - val;
		imageB = pRGB->getBleu();
		imageB = imageB - val;
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Diminution de la luminosite de l'imageRGB id : " << id << " de valeur : " << val << endl;
		idTmp = Insere(&image);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
	return 0;
}

int Moteur::Soustraire(int id1, int id2)
{
	int idTmp;
	Image *image1;
	Image *image2;
	
	image1 = GetImage(id1);
	image2 = GetImage(id2);
	
	ImageNG* pNG1 = dynamic_cast<ImageNG*>(image1);
    if (pNG1 != NULL) 
    {
		ImageNG* pNG2 = dynamic_cast<ImageNG*>(image2);
		if (pNG2 != NULL) 
		{
			ImageNG imageTmp;
			try
			{
				imageTmp = *pNG1 - *pNG2;
			}
			catch(XYException exc)
			{
			  throw MoteurException(exc.getMessage());
			}
			fichierLog << "Soustraction de l'imageNG id : " << id2 << " a l'imageNG id : " << id1 << endl;
			idTmp = Insere(&imageTmp);
		
			return idTmp;
		}
    }

	ImageRGB* pRGB1 = dynamic_cast<ImageRGB*>(image1);
    if (pRGB1 != NULL) 
    {
		ImageRGB* pRGB2 = dynamic_cast<ImageRGB*>(image2);
		if (pRGB2 != NULL) 
		{
			ImageNG imageR1, imageG1, imageB1;
			ImageNG imageR2, imageG2, imageB2;
			ImageRGB image1(*pRGB1);
			ImageRGB image2(*pRGB2);
			imageR1 = pRGB1->getRouge();
			imageR2 = pRGB2->getRouge();
		 	try
			{   	
				imageR1 = imageR1 - imageR2;
			}
			catch(BaseException bEx)
			{
				throw MoteurException(bEx.getMessage());
			}
			
			imageG1 = pRGB1->getVert();
			imageG2 = pRGB2->getVert();
			imageG1 = imageG1 - imageG2;
			
			imageB1 = pRGB1->getBleu();
			imageB2 = pRGB2->getBleu();
			imageB1 = imageB1 - imageB2;
			
			image1.setRGB(imageR1, imageG1, imageB1);
			
			fichierLog << "Soustraction de l'imageRGB id : " << id2 << " a l'imageRGB id : " << id1 << endl;
			idTmp = Insere(&image1);
		
			return idTmp;
		}
    }

	throw MoteurException("Type d'image non supporte !");

	return 0;
}
		
int Moteur::Seuillage(int id, int seuil)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageB imageTmp;
		imageTmp = Traitements::Seuillage(*pNG, seuil);
		imageTmp.setNom(image->getNom());
		fichierLog << "Seuillage de l'image id : " << id << " avec un seuil de : " << seuil << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::Negatif(int id)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
		imageTmp = Traitements::Negatif(*pNG);
		fichierLog << "Negatif de l'imageNG id : " << id << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
		imageR = Traitements::Negatif(imageR);
		imageG = pRGB->getVert();
		imageG = Traitements::Negatif(imageG);
		imageB = pRGB->getBleu();
		imageB = Traitements::Negatif(imageB);
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Negatif de l'imageRGB id : " << id << endl;
		idTmp = Insere(&image);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::FiltreMedian(int id, int tailleFiltre)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
    	try
    	{
			imageTmp = Traitements::FiltreMedian(*pNG, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}
		fichierLog << "Filtre median de l'imageNG id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
     	try
    	{   	
			imageR = Traitements::FiltreMedian(imageR, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}			
		imageG = pRGB->getVert();
		imageG = Traitements::FiltreMedian(imageG, tailleFiltre);
		imageB = pRGB->getBleu();
		imageB = Traitements::FiltreMedian(imageB, tailleFiltre);
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Filtre median de l'imageRGB id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&image);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::FiltreMoyenneur(int id, int tailleFiltre)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
    	try
    	{
			imageTmp = Traitements::FiltreMoyenneur(*pNG, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}
		fichierLog << "Filtre moyenneur de l'imageNG id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&imageTmp);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
     	try
    	{   	
			imageR = Traitements::FiltreMoyenneur(imageR, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}			
		imageG = pRGB->getVert();
		imageG = Traitements::FiltreMoyenneur(imageG, tailleFiltre);
		imageB = pRGB->getBleu();
		imageB = Traitements::FiltreMoyenneur(imageB, tailleFiltre);
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Filtre moyenneur de l'imageRGB id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&image);
		
		VisualiseImages(id, idTmp);
		
		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::FiltreMoyenneurSelection(int id, int tailleFiltre)
{
	if((tailleFiltre%2) == 0)
		throw MoteurException("La taille du filtre doit etre impair !");
		
	Image *image = GetImage(id);	
	
	ImageB* pB = dynamic_cast<ImageB*>(image);
    if (pB == NULL) 
    {
    	int idTmp;
		Pixel pixel1, pixel2;
    	Dimension Dim = image->getDimension();
    	
    	WindowSDL::open(Dim.getLargeur(), Dim.getHauteur());
    	image->Dessine(0, 0);
    	
    	WindowSDLclick click1;
    	WindowSDLclick click2;
    	
    	click1 = WindowSDL::waitClick();
    	if(click1.getX() == -1 && click1.getY() == -1)
    	{
    		WindowSDL::close();
    		return 0;
    	}
    	
    	click2 = WindowSDL::waitClick();
    	if(click2.getX() == -1 && click2.getY() == -1)
    	{
    		WindowSDL::close();
    		return 0;
    	}    	
    	
    	pixel1.setX(click1.getX());
    	pixel1.setY(click1.getY());
    	
    	pixel2.setX(click2.getX());
    	pixel2.setY(click2.getY());
    	
    	WindowSDL::close();
    	
    	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
		if (pNG != NULL) 
		{
			int run = 1;
			ImageNG imageTmp(*pNG);
			do
			{		
				imageTmp = Traitements::FiltreMoyenneur(imageTmp, tailleFiltre, pixel1, pixel2);
				
				WindowSDL::open(Dim.getLargeur(), Dim.getHauteur());
				imageTmp.Dessine(0, 0);
			
				WindowSDLclick click1;
				WindowSDLclick click2;
			
				click1 = WindowSDL::waitClick();
				if(click1.getX() == -1 && click1.getY() == -1)
				{
					run = 0;
					WindowSDL::close();
				}
				else
				{
					click2 = WindowSDL::waitClick();
					if(click2.getX() == -1 && click2.getY() == -1)
					{
						run = 0;
						WindowSDL::close();
					}
					else
					{
						pixel1.setX(click1.getX());
						pixel1.setY(click1.getY());
			
						pixel2.setX(click2.getX());
						pixel2.setY(click2.getY());
			
						WindowSDL::close();
					}
				}
			}while(run);
			fichierLog << "Filtre moyenneur avec selection de l'imageNG id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
			idTmp = Insere(&imageTmp);
			
			VisualiseImages(id, idTmp);
		
			return idTmp;
		}
		
		ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
		if (pRGB != NULL) 
		{
			int run = 1;
			ImageNG imageR, imageG, imageB;
			ImageRGB image(*pRGB);
			do
			{
				imageR = image.getRouge();
				imageR = Traitements::FiltreMoyenneur(imageR, tailleFiltre, pixel1, pixel2);
				
				imageG = image.getVert();
				imageG = Traitements::FiltreMoyenneur(imageG, tailleFiltre, pixel1, pixel2);
			
				imageB = image.getBleu();
				imageB = Traitements::FiltreMoyenneur(imageB, tailleFiltre, pixel1, pixel2);
				image.setRGB(imageR, imageG, imageB);
				
				WindowSDL::open(Dim.getLargeur(), Dim.getHauteur());
				image.Dessine(0, 0);
			
				WindowSDLclick click1;
				WindowSDLclick click2;
			
				click1 = WindowSDL::waitClick();
				if(click1.getX() == -1 && click1.getY() == -1)
				{
					run = 0;
					WindowSDL::close();
				}
				else
				{
					click2 = WindowSDL::waitClick();
					if(click2.getX() == -1 && click2.getY() == -1)
					{
						run = 0;
						WindowSDL::close();
					}
					else
					{
						pixel1.setX(click1.getX());
						pixel1.setY(click1.getY());
			
						pixel2.setX(click2.getX());
						pixel2.setY(click2.getY());
			
						WindowSDL::close();
					}				
				}
			}while(run);
			fichierLog << "Filtre moyenneur avec selection de l'imageRGB id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
			idTmp = Insere(&image);
			
			VisualiseImages(id, idTmp);
		
			return idTmp;
		}		
	}
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::Dilatation(int id, int tailleFiltre)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
    	try
    	{
			imageTmp = Traitements::Dilatation(*pNG, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}
		fichierLog << "Dilatation de l'imageNG id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&imageTmp);
		
		return idTmp;
    }

    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
     	try
    	{   	
			imageR = Traitements::Dilatation(imageR, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}			
		imageG = pRGB->getVert();
		imageG = Traitements::Dilatation(imageG, tailleFiltre);
		imageB = pRGB->getBleu();
		imageB = Traitements::Dilatation(imageB, tailleFiltre);
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Dilatation de l'imageRGB id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&image);

		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}

int Moteur::Erosion(int id, int tailleFiltre)
{
	int idTmp;
	Image *image = GetImage(id);	
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(image);
    if (pNG != NULL) 
    {
    	ImageNG imageTmp;
    	try
    	{
			imageTmp = Traitements::Erosion(*pNG, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}
		fichierLog << "Erosion de l'imageNG id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&imageTmp);

		return idTmp;
    }

    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image);
    if (pRGB != NULL) 
    {
    	ImageNG imageR, imageG, imageB;
    	ImageRGB image(*pRGB);
    	imageR = pRGB->getRouge();
     	try
    	{   	
			imageR = Traitements::Erosion(imageR, tailleFiltre);
		}
		catch(BaseException bEx)
		{
			throw MoteurException(bEx.getMessage());
		}			
		imageG = pRGB->getVert();
		imageG = Traitements::Erosion(imageG, tailleFiltre);
		imageB = pRGB->getBleu();
		imageB = Traitements::Erosion(imageB, tailleFiltre);
		image.setRGB(imageR, imageG, imageB);
		fichierLog << "Erosion de l'imageRGB id : " << id << " avec une taille de filtre de : " << tailleFiltre << endl;
		idTmp = Insere(&image);

		return idTmp;
    }
    
    throw MoteurException("Type d'image non supporte !");
    
    return 0;
}	

int Moteur::DetectionContour(int id, int tailleFiltre)
{
	int idTmp1, idTmp2, idFin;
	
	idTmp1 = Dilatation(id, tailleFiltre);
	
	idTmp2 = Erosion(id, tailleFiltre);
	
	idFin = Soustraire(idTmp1, idTmp2);
		
	VisualiseImages(id, idFin);
	
	return idFin;	
}
		
void Moteur::ChangColorBool(Couleur coulT, Couleur coulF)
{
  ImageB::couleurTrue = coulT;
  ImageB::couleurFalse = coulF;
}
		
void Moteur::Save(ofstream &fichier)
{	
	if(!imagesNG.estVide())
	{	
		char Type = 'N';
		ImageNG imTest;
		Iterateur<ImageNG> it(imagesNG);

		it.reset();
		while(!it.end())
		{
			imTest = (it);
			fichier.write((char*)&Type, sizeof(char));
			imTest.Save(fichier);
			it++;
		}
	}
	
	if(!imagesRGB.estVide())
	{
		char Type = 'C';
		ImageRGB imTest;
		Iterateur<ImageRGB> it(imagesRGB);

		it.reset();
		while(!it.end())
		{
			imTest = (it);
			fichier.write((char*)&Type, sizeof(char));
			imTest.Save(fichier);
			it++;
		}
	}

	if(!imagesB.estVide())
	{
		char Type = 'B';
		ImageB imTest;
		Iterateur<ImageB> it(imagesB);

		it.reset();
		while(!it.end())
		{
			imTest = (it);
			fichier.write((char*)&Type, sizeof(char));
			imTest.Save(fichier);
			it++;
		}
	}
	char Type = 'F';
	fichier.write((char*)&Type, sizeof(char));
	fichierLog << "Sauvegerde des images" << endl;
}

void Moteur::Load(ifstream &fichier)
{
	char Type;
	fichierLog << "Chargement des images" << endl;
	
	fichier.read((char*)&Type, sizeof(char));
	
	if(Type != 0)
	{
		while(Type != 'F')
		{
			if(Type == 'N')
			{
				ImageNG image;
				image.Load(fichier);
				Insere(&image);
			}
			else
			{
				if(Type == 'C')
				{
					ImageRGB image;
					image.Load(fichier);
					Insere(&image);			
				}
				else
				{	
					if(Type == 'B')
					{
						ImageB image;
						image.Load(fichier);
						Insere(&image);			
					}
				}
			}
			
			fichier.read((char*)&Type, sizeof(char));		
		}
	}
}
		
int Moteur::ImporteCSV(const char *nomFichier)
{
	int cpt = 0;
	char Tampon[80];
	ifstream fichier(nomFichier, ios::in);
	
	if(fichier == NULL)
		throw MoteurException("Le fichier csv n'existe pas !");
	
	while(fichier) //Double précaution sinon double lecture du dernier élément 
	{
		fichier >> Tampon;
		if(!fichier.eof())
		{
			char *pch;
			pch = strtok(Tampon, ":;,");
			while(pch != NULL)
			{
				if(strcmp(pch, "NG") == 0)
				{
					cpt++;
					pch = strtok(NULL, ":;,");
					try
					{
						ImporteImageNG(pch);
					}
					catch(...)
					{
						cpt--;
					}
				}
				
				if(strcmp(pch, "RGB") == 0)
				{
					cpt++;
					pch = strtok(NULL, ":;,");
					try
					{
						ImporteImageRGB(pch);
					}
					catch(...)
					{
						cpt--;
					}
				}
				else
					pch = strtok(NULL, ":;,");
			}
		}
	}		
	fichier.close();
	
	fichierLog << "Importation de " << cpt << " image(s) a partir d'un fichier csv" << endl;
	
	return cpt;
}	
		
		
		
		

