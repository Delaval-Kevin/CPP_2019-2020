.SILENT:

PROGRAMS = Test1 Test2 Test3 Test4 Test5 Test6 Test7 Test8 Test9 Test10

PROGRAM = MiniPhotoShop

PROG = mTestCopie2019 mTestEgal2019

OBJS = Ecran.o Couleur.o Dimension.o Pixel.o PixelB.o PixelNG.o PixelRGB.o Image.o ImageB.o ImageNG.o ImageRGB.o WindowSDL.o WindowSDLimage.o WindowSDLclick.o WindowSDLexception.o BaseException.o RGBException.o XYException.o MoteurException.o Matrice.o ListeBase.o Liste.o ListeTriee.o Iterateur.o Traitements.o Moteur.o UI.o

CLASSE = $(HOME)/C++/Classes

COULEUR = $(CLASSE)/Couleur

LISTE = $(CLASSE)/Container

DIMENSION = $(CLASSE)/Dimension

TRAITEMENT = $(CLASSE)/Traitement

MOTEUR = $(CLASSE)/Moteur

UI = $(CLASSE)/UI

PIXEL = $(CLASSE)/Pixel

IMAGE = $(CLASSE)/Image

MATRICE = $(CLASSE)/Matrice

EXCEPTION = $(CLASSE)/Exception

ECRAN = $(HOME)/Ecran

WINDOW = $(HOME)/C++/WindowSDL

GPP = g++ -m64 -Wall -D SUN -D CPP -lpthread -lSDL -I $(COULEUR) -I $(DIMENSION) -I $(PIXEL) -I $(IMAGE) -I $(EXCEPTION) -I $(ECRAN) -I $(WINDOW) -I $(MATRICE) -I $(LISTE) -I $(TRAITEMENT) -I $(MOTEUR) -I $(UI) #-D DEBUG

all: $(PROGRAM)

mTestCopie2019: mTestCopie2019.cpp $(OBJS)
	echo Creation de mTestCopie2019
	$(GPP) -o mTestCopie2019 $(OBJS) mTestCopie2019.cpp
	
mTestEgal2019: mTestEgal2019.cpp $(OBJS)
	echo Creation de mTestEgal2019
	$(GPP) -o mTestEgal2019 $(OBJS) mTestEgal2019.cpp

MiniPhotoShop: MiniPhotoShop.cpp $(OBJS)
	echo Creation de MiniPhotoShop
	$(GPP) -o MiniPhotoShop $(OBJS) MiniPhotoShop.cpp

Test1: Test1.cpp $(OBJS)
	echo Creation de Test1
	$(GPP) -o Test1 $(OBJS) Test1.cpp

Test2: Test2.cpp $(OBJS)
	echo Creation de Test2
	$(GPP) -o Test2 $(OBJS) Test2.cpp
	
Test3: Test3.cpp $(OBJS)
	echo Creation de Test3
	$(GPP) -o Test3 $(OBJS) Test3.cpp

Test4: Test4.cpp $(OBJS)
	echo Creation de Test4
	$(GPP) -o Test4 $(OBJS) Test4.cpp

Test5: Test5.cpp $(OBJS)
	echo Creation de Test5
	$(GPP) -o Test5 $(OBJS) Test5.cpp

Test6: Test6.cpp $(OBJS)
	echo Creation de Test6
	$(GPP) -o Test6 $(OBJS) Test6.cpp

Test7: Test7.cpp $(OBJS)
	echo Creation de Test7
	$(GPP) -o Test7 $(OBJS) Test7.cpp

Test8: Test8.cpp $(OBJS)
	echo Creation de Test8
	$(GPP) -o Test8 $(OBJS) Test8.cpp
	
Test9: Test9.cpp $(OBJS)
	echo Creation de Test9
	$(GPP) -o Test9 $(OBJS) Test9.cpp

Test10: Test10.cpp $(OBJS)
	echo Creation de Test10
	$(GPP) -o Test10 $(OBJS) Test10.cpp

Ecran.o: $(ECRAN)/Ecran.cpp
	echo Creation de Ecran.o
	$(GPP) -c $(ECRAN)/Ecran.cpp

Dimension.o: $(DIMENSION)/Dimension.cpp
	echo Creation de Dimension.o
	$(GPP) -c $(DIMENSION)/Dimension.cpp

WindowSDL.o: $(WINDOW)/WindowSDL.cpp 
	echo Creation de WindowSDL.o
	$(GPP) -c $(WINDOW)/WindowSDL.cpp
	
WindowSDLexception.o:	$(WINDOW)/WindowSDLexception.cpp
	echo Creation de WindowSDLexception.o
	$(GPP) -c $(WINDOW)/WindowSDLexception.cpp

WindowSDLclick.o:	$(WINDOW)/WindowSDLclick.cpp
	echo Creation de WindowSDLclick.o
	$(GPP) -c $(WINDOW)/WindowSDLclick.cpp
	
WindowSDLimage.o:	$(WINDOW)/WindowSDLimage.cpp
	echo Creation de WindowSDLimage.o
	$(GPP) -c $(WINDOW)/WindowSDLimage.cpp
	
ImageNG.o: $(IMAGE)/ImageNG.cpp
	echo Creation de ImageNG.o
	$(GPP) -c $(IMAGE)/ImageNG.cpp
	
PixelNG.o: $(PIXEL)/PixelNG.cpp
	echo Creation de PixelNG.o
	$(GPP) -c $(PIXEL)/PixelNG.cpp
	
Image.o: $(IMAGE)/Image.cpp
	echo Creation de Image.o
	$(GPP) -c $(IMAGE)/Image.cpp
	
Pixel.o: $(PIXEL)/Pixel.cpp
	echo Creation de Pixel.o
	$(GPP) -c $(PIXEL)/Pixel.cpp
	
Couleur.o: $(COULEUR)/Couleur.cpp
	echo Creation de Couleur.o
	$(GPP) -c $(COULEUR)/Couleur.cpp
	
ImageRGB.o: $(IMAGE)/ImageRGB.cpp
	echo Creation de ImageRGB.o
	$(GPP) -c $(IMAGE)/ImageRGB.cpp
	
PixelRGB.o: $(PIXEL)/PixelRGB.cpp
	echo Creation de PixelRGB.o
	$(GPP) -c $(PIXEL)/PixelRGB.cpp

ImageB.o: $(IMAGE)/ImageB.cpp
	echo Creation de ImageB.o
	$(GPP) -c $(IMAGE)/ImageB.cpp
	
PixelB.o: $(PIXEL)/PixelB.cpp
	echo Creation de PixelB.o
	$(GPP) -c $(PIXEL)/PixelB.cpp
	
BaseException.o: $(EXCEPTION)/BaseException.cpp
	echo Creation de BaseException.o
	$(GPP) -c $(EXCEPTION)/BaseException.cpp

RGBException.o: $(EXCEPTION)/RGBException.cpp
	echo Creation de RGBException.o
	$(GPP) -c $(EXCEPTION)/RGBException.cpp

XYException.o: $(EXCEPTION)/XYException.cpp
	echo Creation de XYException.o
	$(GPP) -c $(EXCEPTION)/XYException.cpp

MoteurException.o: $(EXCEPTION)/MoteurException.cpp
	echo Creation de MoteurException.o
	$(GPP) -c $(EXCEPTION)/MoteurException.cpp

Matrice.o: $(MATRICE)/Matrice.cpp
	echo Creation de Matrice.o
	$(GPP) -c $(MATRICE)/Matrice.cpp
	
ListeBase.o: $(LISTE)/ListeBase.cpp
	echo Creation de ListeBase.o
	$(GPP) -c $(LISTE)/ListeBase.cpp	
	
Liste.o: $(LISTE)/Liste.cpp
	echo Creation de Liste.o
	$(GPP) -c $(LISTE)/Liste.cpp	
	
ListeTriee.o: $(LISTE)/ListeTriee.cpp
	echo Creation de ListeTriee.o
	$(GPP) -c $(LISTE)/ListeTriee.cpp	
	
Iterateur.o: $(LISTE)/Iterateur.cpp
	echo Creation de Iterateur.o
	$(GPP) -c $(LISTE)/Iterateur.cpp		
			
Traitements.o: $(TRAITEMENT)/Traitements.cpp
	echo Creation de Traitements.o
	$(GPP) -c $(TRAITEMENT)/Traitements.cpp
	
Moteur.o: $(MOTEUR)/Moteur.cpp
	echo Creation de Moteur.o
	$(GPP) -c $(MOTEUR)/Moteur.cpp
	
UI.o: $(UI)/UI.cpp
	echo Creation de UI.o
	$(GPP) -c $(UI)/UI.cpp
