CXX = g++-4.8
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

all:: testSysteme

Vecteur.o: Vecteur.cc Vecteur.h

Particule.o: Particule.cc Particule.h 

TXTNeon.o: TXTNeon.cc TXTNeon.h

TXTArgon.o: TXTArgon.cc TXTArgon.h

TXTHelium.o: TXTHelium.cc TXTHelium.h

Enceinte.o: Enceinte.cc Enceinte.h

Systeme.o: Systeme.cc Systeme.h

testSysteme.o: testSysteme.cc Systeme.h

testSysteme: testSysteme.o Systeme.o Enceinte.o Particule.o TXTNeon.o TXTHelium.o TXTArgon.o Vecteur.o
