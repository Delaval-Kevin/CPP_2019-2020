echo Creation de Ecran.o
g++ -D SUN -m64 -Wall Ecran.cpp -c

echo Creation de ImageNG.o
g++ -m64 -Wall -D SUN -c ImageNG.cpp

echo Creation de Test1
g++ -m64 -Wall -D SUN -o Test1 Test1.cpp Ecran.o ImageNG.o
