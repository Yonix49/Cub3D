# Cub3D - Mon premier RayCaster avec la minilibX

**Cub3D** est un projet qui vous permet de créer une représentation graphique 3D à l'intérieur d'un labyrinthe en utilisant la technique du ray-casting. Il est inspiré du jeu Wolfenstein3D, considéré comme le premier jeu de tir à la première personne (FPS) de l'histoire du jeu vidéo. Votre objectif est de créer une vue dynamique à l'intérieur du labyrinthe, où vous pourrez vous déplacer et explorer l'environnement.

## Objectifs du Projet

Les principaux objectifs du projet sont les suivants :

- Créer une représentation graphique 3D "réaliste" d'un labyrinthe en utilisant le ray-casting.
- Utiliser la MinilibX pour la gestion des fenêtres.
- Afficher des textures pour les murs.
- Gérer les couleurs du sol et du plafond.
- Permettre de déplacer la caméra à l'intérieur du labyrinthe.

## Fichiers de Rendu
## Exemple de Fichier de Description de Scène (.cub)

Le fichier de description de scène (.cub) est utilisé pour configurer l'environnement du labyrinthe dans le projet Cub3D. Voici un exemple minimaliste de ce fichier :

```plaintext
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the-west_texture
EA ./path_to-the-east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
.

## Compilation et Exécution

Utilisez le Makefile fourni pour compiler le projet.

```bash
make
./cub3D [votre_fichier_de_description_de_scene.cub]
