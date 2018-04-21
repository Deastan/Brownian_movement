README

LA simulation marche sur les ordinateurs du co, bureau a distance, machine virtuelle sous windows et un ordinateur d’un ami ayant installé les bibliothèques.

Application dans le dossier “Simulation d’un gaz parfait”

POUR LE LANCER (to launch the code):

Nous rendons notre projet de programmation sur une simulation d’un gaz parfait.
Le fichier principal est GUI et permet de lancer l’application en ayant compilé une fois sur l’OS que l’on utilise. 

Pour pouvoir exécuter notre simulation, il faut lancer un programme qui peut compiler et construire du code c++ et WxWidget.
Dès lors, il faut ouvrir le terminal et se déplacer dans le dossier à l’aide des commandes cd “…” et ls qui permet de voir le contenu du dossier où l’on se trouve.

Dès qu’on est dans le bon dossier, écrire la commande make dans le terminal, et ensuite attendre qu’il y est la création des fichier “.o” qui vont permettre l’exécution de notre programme. 

Quand tout cela est fini et sans aucune erreur, il faut taper ./GUI dans le terminal et le programme s’exécute.

PENDANT LE LANCEMENT : Attention, on ne peut pas mettre plus de 425 particules pour que le programme marche correctement.
Il y a une fenêtre qui s’ouvre demandant si l’on souhaite paramétrer le système, si oui alors une série de fenêtres va permettre de faire les réglages souhaité sinon un système aléatoire va être lancé.
Ces boîtes de dialogue permettent de dialoguer avec l’utilisateur et permettent de paramétrer facilement le programme et pas de devoir aller modifier dans le code certains endroits.

Ensuite une enceinte avec un certain nombre de particules sera affiché à l’écran et il y a une interaction avec le clavier qui est à disposition de l’utilisateur.

-Les flèches directionnelles permettent de tourner autours de l’enceinte avec un déplacement angulaire.

Appuyer sur ces boutons et vous verrez ! Un canon cracheur de particules dont même un qu’on peut suivre à la trace !!!
-A,H,N permettent de créer 20 particules d’Argon,Helium et Néon qui sortiront du canon.

-F permet de créer une particule de Fluor qui a une trace. Donc nous pouvons voir la trajectoire de cette particule.

-Les deux touches zoom avant et arrière permette de faire un zoom sur le centre de l’enceinte.

-Barre d’espace permet de faire une pause de la simulation.

Pour quitter l’application, il faut fermer la fenêtre.

Il y a un fichier conception fait avec le programme doxygen en html et une version pdf qui permettent de comprendre le code avec quelques explications de notre code.

Il y a aussi un fichier JOURNAL qui contient nos étapes et un fichier REPONSES contenant les réponses aux questions qui ont étés posées pendant le projet.
 
Il  a aussi d’autres fichiers avec étapes intermédiaires que nous rendons comme les exercices
- P4 : test du fichier vecteur (commande : ./testVecteur)
- P5 : test du fichier particule (commande : ./testParticule)
- P8 : teste du système avec simulation texte (commande : ./testSysteme)
- P9 : teste du système avec simulation texte (commande : ./exerciceP9)
- P10 : partie OpenGL avec compilation séparée (commande : ./GUI)

Pour compiler, construire et exécuter, il faut aller dans le dossier rendu et choisir celui qu’on souhaite essayer.

Il faut taper dans le terminal, la commande make, et ensuite la commande associé a chacune des parties (écrites juste en haut).

Pour le P12 et P13, il n’y a pas de fichiers .cc séparés car on peut voir que ça fonctionne dans le projet final.

Réponses aux questions du README

1. Nous avons été jusqu’au P13 et n’avons pas fait le p14 pour cause de temps.
2. Nous avons une version graphique avec les bibliothèques WxWidget, OpenGL
3. Nous avons passé environ 5 heures par semaine et par personne. Au début, très peu de l’ordre de une à deux heures et à partir du P8, nous avons commencé à travailler beaucoup plus et là depuis 3 semaines, il y a je pense une 10 heures chacun et même plus. Cela sans l’ajout du canon et des boxes interactives avec l’utilisateurs.



 
