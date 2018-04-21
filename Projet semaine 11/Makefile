CXX=g++-4.8

CXXFLAGS = -std=c++11 `wx-config --cxxflags`
LDLIBS   = `wx-config --libs gl,core,base` -lGLU -lGL


all:: GUI

H2O.o : H2O.h H2O.cc
Moucheron.o : Moucheron.h Moucheron.cc
Blob.o : Blob.h Blob.cc

Enceinte.o : Enceinte.h Enceinte.cc
Systeme.o : Systeme.h Systeme.cc
Vecteur.o : Vecteur.h Vecteur.cc
GenerateurAleatoire.o : GenerateurAleatoire.h GenerateurAleatoire.cc
Particule.o : Particule.h Particule.cc

Vue_OpenGL.o : Vue_OpenGL.h Vue_OpenGL.cc
Fenetre.o : Fenetre.h Fenetre.cc
GUI.o : GUI.h GUI.cc
GLNeon.o :GLNeon.cc GLNeon.h
GLHelium.o : GLHelium.cc GLHelium.h
GLArgon.o : GLArgon.h GLArgon.cc

GUI : Fenetre.o Vue_OpenGL.o Particule.o GenerateurAleatoire.o Vecteur.o Systeme.o Enceinte.o GLNeon.o GLHelium.o GLArgon.o

clean:
	@-/bin/rm -f *.o
