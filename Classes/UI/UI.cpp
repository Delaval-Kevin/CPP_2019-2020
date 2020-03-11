/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : User Interface                             */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/11/2019             */
/***********************************************************/

#include "UI.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

UI::UI(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par defaut");
	#endif
	moteur = NULL;
}
	
UI::UI(Moteur *Mot)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	moteur = Mot;
}
		
UI::UI(const UI& ui)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	moteur = ui.moteur;
}
	

/********************************/
/*                              */
/*         Destructeurs         */			
/*                              */
/********************************/
	
UI::~UI()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
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

void UI::Menu()
{

	cout << "********************************************************************************************************" << endl;
	cout << "******* Mini PhotShop en C++ ***************************************************************************" << endl;
	cout << "********************************************************************************************************" << endl;
	cout << endl;
	moteur->Affiche();
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "******* Menu general ***********************************************************************************" << endl;
	cout << "  0. Quitter" << endl;
	cout << "  1. Visualiser une image et ses caracteristiques" << endl;
	cout << "  2. Visualiser deux images simultanement" << endl;
	cout << "  3. Importer un ensemble d'images a partir d'un fichier csv" << endl;
	cout << "  4. Exporter vers BMP" << endl;
	cout << "  5. Supprimer une image" << endl;
	cout << "******* Menu ImageNG ***********************************************************************************" << endl;
	cout << "  6. Importer une imageNG" << endl;
	cout << "  7. Seuillage" << endl;
	cout << "******* Menu ImageNG et ImageRGB ***********************************************************************" << endl;	
	cout << "  8. Augmenter la luminosite" << endl;
	cout << "  9. Diminuer la luminosite" << endl;
	cout << " 10. Soustraire deux images" << endl;
	cout << " 11. Filtre moyenneur" << endl;
	cout << " 12. Filtre median" << endl;
	cout << " 13. Erosion" << endl;
	cout << " 14. Dilatation" << endl;
	cout << " 15. Detection des contours" << endl;
	cout << " 16. Negatif" << endl;
	cout << "******* Menu ImageRGB **********************************************************************************" << endl;
	cout << " 17. Importer une imageRGB" << endl;
	cout << "******* Menu ImageB ************************************************************************************" << endl;
	cout << " 18. Changer les couleurs des booleens" << endl;
}

void UI::Start()
{
	int run = 1;
	int err = 0;
	MoteurException Exception;
	
	ifstream fichier1(FICHIER, ios::in);
	moteur->Load(fichier1);
	fichier1.close();
	
	while(run == 1)
	{
		int choix, ok;
		EffEcran();
		Menu();
		
		if(err)
		{
			cout << Exception << endl;
			err = 0;
		}
		else
			cout << endl;
			
		cout << "Choix : ";
		ok = LireNombre(&choix,0,17);
		if(ok != 1)
			choix = -1;
		try
		{
			int id;
			char nom[80];
			switch(choix)
			{
				case 0:
					run = 0;
					break;
				
				case 1:
					cout << "Entrer l'id de l'image a visualiser : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						moteur->VisualiseImage(id);
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}	
					break;
			
				case 2:
					cout << "Entrer l'id de la premiere image a visualiser : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int id2;
						cout << "Entrer l'id de la seconde image a visualiser : ";
						ok = LireNombre(&id2,0,30000);
						if(ok)
						{
							moteur->VisualiseImages(id, id2);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}	
					break;
			
				case 3:
					cout << "Entrer le nom du fichier du fichier csv : ";
					cin >> nom;
					
					moteur->ImporteCSV(nom);				
					break;
			
				case 4:
					cout << "Entrer l'id de l'image a exporte : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						cout << "Entrer le nom que vous voulez lui donner : ";
						cin >> nom;
						moteur->ExporterBMP(id, nom);
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}					
					break;
				
				case 5:
					cout << "Entrer l'id de l'image a supprimer : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						moteur->SupprimeImage(id);
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}	
					break;
			
				case 6:
					cout << "Entrer le nom du fichier a importer : ";
					cin >> nom;
					
					moteur->ImporteImageNG(nom);
					break;
				
				case 7:
					cout << "Entrer l'id de l'image pour le seuillage : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int seuil;
						cout << "Entrer le niveau de pixel pour le seuillage : ";
						ok = LireNombre(&seuil,0,30000);
						if(ok)
						{
							moteur->Seuillage(id, seuil);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}		
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}				
					break;
					
				case 8:
					cout << "Entrer l'id de l'image pour la luminosite : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int val;
						cout << "Entrer la valeur a augmenter : ";
						ok = LireNombre(&val,0,30000);
						if(ok)
						{
							moteur->AugmenteLuminosite(id, val);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}		
					break;
			
				case 9:
					cout << "Entrer l'id de l'image pour la luminosite : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int val;
						cout << "Entrer la valeur a diminuer : ";
						ok = LireNombre(&val,0,30000);
						if(ok)
						{
							moteur->DiminueLuminosite(id, val);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}							
					break;
				
				case 10:
					cout << "Entrer l'id de la premiere image : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int id2;
						cout << "Entrer l'id de la seconde image : ";
						ok = LireNombre(&id2,0,30000);
						if(ok)
						{
							moteur->Soustraire(id, id2);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}				
					break;
			
				case 11:
					cout << "Entrer l'id de l'image pour le filtre moyenneur : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int taille;
						cout << "Entrer la taille du filtre a appliquer : ";
						ok = LireNombre(&taille,0,30000);
						if(ok)
						{
							cout << "Taille du traitement " << endl;
							cout << " 1. Toute l'image" << endl;
							cout << " 2. Selection dans l'image" << endl;
							cout << "Choix : ";
							ok = LireNombre(&choix,1,2);
							if(ok)
							{
								if(choix == 1)
									moteur->FiltreMoyenneur(id, taille);
								else
									moteur->FiltreMoyenneurSelection(id, taille);
							}
							else
							{
								err = 1;	
								Exception.setMessage("Choix incorrect!");	
							}
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}				
					break;
				
				case 12:
					cout << "Entrer l'id de l'image pour le filtre median : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int taille;
						cout << "Entrer la taille du filtre a appliquer : ";
						ok = LireNombre(&taille,0,30000);
						if(ok)
						{
							moteur->FiltreMedian(id, taille);
						}	
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}				
					break;
				
				case 13:
					cout << "Entrer l'id de l'image pour l'erosion : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int taille;
						cout << "Entrer la taille du filtre a appliquer : ";
						ok = LireNombre(&taille,0,30000);
						if(ok)
						{
							moteur->Erosion(id, taille);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}		
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}					
					break;
				
				case 14:
					cout << "Entrer l'id de l'image pour la dilatation : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int taille;
						cout << "Entrer la taille du filtre a appliquer : ";
						ok = LireNombre(&taille,0,30000);
						if(ok)
						{
							moteur->Dilatation(id, taille);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}	
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}					
					break;
				
				case 15:
					cout << "Entrer l'id de l'image pour la detection de contour : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						int taille;
						cout << "Entrer la taille du filtre a appliquer : ";
						ok = LireNombre(&taille,0,30000);
						if(ok)
						{
							moteur->DetectionContour(id, taille);
						}
						else
						{
							err = 1;	
							Exception.setMessage("Entree incorrecte !");	
						}		
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}
					break;
				
				case 16:
					cout << "Entrer l'id de l'image a mettre au negatif : ";
					ok = LireNombre(&id,0,30000);
					if(ok)
					{
						moteur->Negatif(id);
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}			
					break;
				
				case 17:
					cout << "Entrer le nom du fichier a importer : ";
					cin >> nom;
					
					moteur->ImporteImageRGB(nom);				
					break;
				
				case 18:
					int val;
					cout << "Entrer la couleur pour la valeur TRUE " << endl;
					cout << "Valeur du rouge : ";
					ok = LireNombre(&val,0,30000);
					if(ok)
					{
						Couleur coulT, coulF;
						try
						{
							coulT.setRouge(val);
							cout << "Valeur du vert : ";
							ok = LireNombre(&val,0,30000);
							if(ok)
							{
								coulT.setVert(val);
								cout << "Valeur du bleu : ";
								ok = LireNombre(&val,0,30000);
								if(ok)
								{
									coulT.setBleu(val);
									cout << "Entrer la couleur pour la valeur FALSE " << endl;
									cout << "Valeur du rouge : ";
									ok = LireNombre(&val,0,30000);
									if(ok)
									{
										coulF.setRouge(val);
										cout << "Valeur du vert : ";
										ok = LireNombre(&val,0,30000);
										if(ok)
										{
											coulF.setVert(val);
											cout << "Valeur du bleu : ";
											ok = LireNombre(&val,0,30000);
											if(ok)
											{
												coulF.setBleu(val);
												moteur->ChangColorBool(coulT, coulF);
											}
											else
											{
												err = 1;	
												Exception.setMessage("Entree incorrecte !");	
											}	
										}
										else
										{
											err = 1;	
											Exception.setMessage("Entree incorrecte !");	
										}	
									}
									else
									{
										err = 1;	
										Exception.setMessage("Entree incorrecte !");	
									}	
								}
								else
								{
									err = 1;	
									Exception.setMessage("Entree incorrecte !");	
								}	
							}
							else
							{
								err = 1;	
								Exception.setMessage("Entree incorrecte !");	
							}	
						}
						catch(RGBException RGBEx)
						{
							Exception.setMessage(RGBEx.getMessage());
							err = 1;
						}
					}
					else
					{
						err = 1;	
						Exception.setMessage("Entree incorrecte !");	
					}	
					break;
				
				default:
					err = 1;	
					Exception.setMessage("Choix incorrect !");	
					break;
			}
		}
		catch(MoteurException MEx)
		{
			Exception.setMessage(MEx.getMessage());
			err = 1;
		}
	}
	ofstream fichier2(FICHIER, ios::out);
	moteur->Save(fichier2);
	fichier2.close();
}

int UI::LireNombre(int *pN, int min, int max)
{
    char c;
    int i=0, s=1, ok=1;
    *pN=0;

    fflush(stdin);

    c=getchar();
    if(c=='-')
    {
        s=-1;
        c=getchar();
    }
    else
    {
        if(c=='+')
        {
            c=getchar();
        }
    }

    while(*pN<=3200 && ok==1 && c!='\n')
    {
        i++;
        if(c>='0' && c<='9')
        {
            *pN=*pN*10+(c-48);
            c=getchar();
        }
        else
        {
            ok=0;
        }
    }

    *pN=*pN*s;

    if(*pN<min || *pN>max)
    {
        ok=0;
    }
    if(i==0)
    {
        ok=0;
    }

    return ok;

}



