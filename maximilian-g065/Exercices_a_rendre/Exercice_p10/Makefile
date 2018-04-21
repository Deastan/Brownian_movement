CXX=g++-4.8

CXXFLAGS = -std=c++11 `wx-config --cxxflags`
LDLIBS   = `wx-config --libs gl,core,base` -lGLU -lGL


all:: GUI

H2O.o : H2O.h H2O.cc
Moucheron.o : Moucheron.h Moucheron.cc
Blob.o : Blob.h Blob.cc

Vue_OpenGL.o : Vue_OpenGL.h Vue_OpenGL.cc
Fenetre.o : Fenetre.h Fenetre.cc
GUI.o : GUI.h GUI.cc

GUI : H2O.o Moucheron.o Blob.o Fenetre.o Vue_OpenGL.o

clean:
	@-/bin/rm -f *.o
