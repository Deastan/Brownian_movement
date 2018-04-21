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

all:: exerciceP9

Vecteur.o: Vecteur.cc Vecteur.h

GenerateurAleatoire.o: GenerateurAleatoire.cc GenerateurAleatoire.h

Particule.o: Particule.cc Particule.h

TXTHelium.o: TXTHelium.cc TXTHelium.h

TXTNeon.o: TXTNeon.cc TXTNeon.h

TXTArgon.o: TXTArgon.cc TXTArgon.h

Enceinte.o: Enceinte.cc Enceinte.h

Systeme.o: Systeme.cc Systeme.h

exerciceP9.o: exerciceP9.cc Systeme.h

exerciceP9: exerciceP9.o Systeme.o Enceinte.o Particule.o GenerateurAleatoire.o TXTHelium.o TXTNeon.o TXTArgon.o Vecteur.o
