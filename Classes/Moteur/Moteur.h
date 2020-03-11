/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Moteur                                     */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/11/2019             */
/***********************************************************/

#ifndef MOTEUR_H
#define MOTEUR_H

#include <string.h>
#include <fstream>
#include "Ecran.h"
#include "Image.h"
#include "ImageB.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "Dimension.h"
#include "Couleur.h"
#include "Pixel.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Traitements.h"
#include "BaseException.h"
#include "XYException.h"
#include "MoteurException.h"
#include "WindowSDLclick.h"

using namespace std;

class Moteur{
		
	private:
		//variables membre
		ListeTriee<ImageNG> imagesNG;
		Liste<ImageRGB>		imagesRGB;
		Liste<ImageB>		imagesB;
		ofstream			fichierLog;
		static int 			cpt;
		
		//méthodes
		int Insere(Image *pImage);
		ImageNG GetImageNG(int id);
		Image* GetImage(int id);
		
	public:		
		//constructeurs
		Moteur(void);
		
		//destructeur
		~Moteur();	
		//operators

		//getters

		//setters
		
		//méthodes
		void Affiche();
		void SupprimeImage(int id);
		int ImporteImageNG(const char *fichier);
		int ImporteImageRGB(const char * fichier);
		void VisualiseImage(int id);
		void VisualiseImages(int id1, int id2);
		void ExporterBMP(int id, const char* fichier);
		int AugmenteLuminosite(int id, int val);
		int DiminueLuminosite(int id, int val);
		int Soustraire(int id1, int id2);
		int Seuillage(int id, int seuil);
		int Negatif(int id);
		int FiltreMedian(int id, int tailleFiltre);
		int FiltreMoyenneur(int id, int tailleFiltre);
		int FiltreMoyenneurSelection(int id, int tailleFiltre);
		int Dilatation(int id, int tailleFiltre);
		int Erosion(int id, int tailleFiltre);
		void ChangColorBool(Couleur coulT, Couleur coulF);
		void Save(ofstream &fichier);
		void Load(ifstream &fichier);
		int ImporteCSV(const char *nomFichier);
		int DetectionContour(int id, int tailleFiltre);
};

#endif //MOTEUR_H
