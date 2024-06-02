

# Cub3D - Mon premier RayCaster avec la minilibX

![Demo Cub3d](assets/Cub3d.gif)

**Cub3D** est un projet qui vous permet de créer une représentation graphique 3D à l'intérieur d'un labyrinthe en utilisant la technique du ray-casting. Il est inspiré du jeu Wolfenstein3D, considéré comme le premier jeu de tir à la première personne (FPS) de l'histoire du jeu vidéo. Votre objectif est de créer une vue dynamique à l'intérieur du labyrinthe, où vous pourrez vous déplacer et explorer l'environnement.

## Objectifs du Projet

Les principaux objectifs du projet sont les suivants :

- Créer une représentation graphique 3D "réaliste" d'un labyrinthe en utilisant le ray-casting.
- Utiliser la MinilibX pour la gestion des fenêtres.
- Afficher des textures pour les murs.
- Gérer les couleurs du sol et du plafond.
- Permettre de déplacer la caméra à l'intérieur du labyrinthe.

## Fichiers de Rendu

Tous les fichiers nécessaires au projet.

## Compilation et Exécution

Utilisez le Makefile fourni pour compiler le projet.

```bash
make
./cub3D [votre_fichier_de_description_de_scene.cub]
Fonctions Externes Autorisées
open, close, read, write, printf, malloc, free, perror, strerror, exit
Toutes les fonctions de la lib math (-lm man man 3 math)
Toutes les fonctions de la MinilibX
Libft Autorisée
Oui

Exemple de Fichier de Description de Scène (.cub)
Le fichier de description de scène (.cub) est utilisé pour configurer l'environnement du labyrinthe dans le projet Cub3D. Voici un exemple minimaliste de ce fichier :

plaintext
Copy code
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to-the-west_texture
EA ./path_to-the-east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
...
Le fichier .cub décrit les textures, les couleurs et la carte du labyrinthe. Voici un aperçu de son contenu :

NO : Texture pour le mur nord.
SO : Texture pour le mur sud.
WE : Texture pour le mur ouest.
EA : Texture pour le mur est.
F : Couleur du sol au format R,G,B.
C : Couleur du plafond au format R,G,B.
La carte du labyrinthe, où 1 représente un mur et d'autres caractères représentent d'autres éléments.
Vous pouvez personnaliser cet exemple en ajoutant vos propres chemins de textures, couleurs et carte du labyrinthe en respectant les règles de format.

Assurez-vous que le fichier de description de scène que vous créez suit ces règles pour que votre programme Cub3D puisse le lire correctement.


```bash
make
./cub3D [votre_fichier_de_description_de_scene.cub]
