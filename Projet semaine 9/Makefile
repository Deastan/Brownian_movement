CXX = g++-4.8
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
# CXXFLAGS += -pedantic -Wall         # pour les purs et durs
# CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                     # pour profiler
# LDFLAGS  += -pg                     # pour profiler
# CXXFLAGS += -O2                     # pour optimiser la vitesse

all:: testSysteme

Vecteur.o: Vecteur.cc Vecteur.h

Particule.o: Particule.cc Particule.h 

TXTNeon.o: TXTNeon.cc TXTNeon.h

TXTArgon.o: TXTArgon.cc TXTArgon.h

Enceinte.o: Enceinte.cc Enceinte.h

Systeme.o: Systeme.cc Systeme.h

testSysteme.o: testSysteme.cc Systeme.h

testSysteme: testSysteme.o Systeme.o Enceinte.o Particule.o TXTNeon.o TXTArgon.o Vecteur.o
