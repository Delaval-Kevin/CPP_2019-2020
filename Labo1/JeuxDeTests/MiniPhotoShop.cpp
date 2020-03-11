/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Traitement d'images                        */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 21/11/2019             */
/***********************************************************/

#include <string.h>
#include <iostream>
#include "UI.h"
#include "Moteur.h"
#include "Ecran.h"
#include "BaseException.h"




int main()
{
	Moteur moteur;
	
	UI ui(&moteur);
	
	ui.Start();
	
	return 0;
}
