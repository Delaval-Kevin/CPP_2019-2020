.SILENT:

PROGRAM = Test1 Test2 Test3 Test4 Test5

OBJS = ImageNG.o PixelNG.o Ecran.o Dimension.o WindowSDL.o WindowSDLexception.o WindowSDLimage.o WindowSDLclick.o

CLASSE = $(HOME)/C++/Classes

ECRAN = $(HOME)/Ecran

WINDOW = $(HOME)/C++/WindowSDL

GPP = g++ -m64 -Wall -D SUN -D CPP -D DEBUG -lpthread -lSDL -I $(CLASSE) -I $(ECRAN) -I $(WINDOW)
all: $(PROGRAM)


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

Ecran.o: $(ECRAN)/Ecran.cpp
	echo Creation de Ecran.o
	$(GPP) -c $(ECRAN)/Ecran.cpp

Dimension.o: $(CLASSE)/Dimension.cpp
	echo Creation de Dimension.o
	$(GPP) -c $(CLASSE)/Dimension.cpp

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
	
ImageNG.o: $(CLASSE)/ImageNG.cpp
	echo Creation de ImageNG.o
	$(GPP) -c $(CLASSE)/ImageNG.cpp
	
PixelNG.o: $(CLASSE)/PixelNG.cpp
	echo Creation de PixelNG.o
	$(GPP) -c $(CLASSE)/PixelNG.cpp
