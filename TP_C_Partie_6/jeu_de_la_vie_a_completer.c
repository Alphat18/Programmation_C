/*
 * The Game of Life
 * 
 * Representation informatique d'un système biologique tres simple.
 * Une grille (que l'on apellera tableau de jeu) est composé d'un certain nombre de cellules.
 * 
 * Une celulle peut etre vivante ou morte. A partir d'un état initial, les celulles vont évoluer dans le temps selon trois règles:
 * 		Si elle est entourée de 2 cellules vivantes, elle ne change pas d'état.
 * 		Si elle est entourée de 3 cellules vivantes, elle devient vivante.
 * 		Si elle est entourée par moins de 2 cellules vivantes ou plus de 3 cellules vivantes elle devient morte.
 * 
 * 
 * Le tableau de jeu est ici representé par un tableau informatique a deux dimensions (matrice).
 * chaque case de ce tableau représente une cellule, qui peut être soit vivante (1) soit morte (0).
 * l'affichage represente les cellules vivantes par un 'x' et les mortes par un ' ' dans la console.
 *
 */
#include <stdio.h>
#include <unistd.h>

/* taille de l'ecran */

#define BOARD_WIDTH	    20
#define BOARD_HEIGHT    20

/* lit un fichier contenant un état du jeu initial */

void read_file(int board[BOARD_WIDTH][BOARD_HEIGHT], char *name) {
	FILE *f;
	/* A FAIRE :
		ouverture du fichier (le nom du fichier est contenu dans la variable "*name")
	*/

	char s[100]; /* chaine de caractere (tableau de characteres) */

	for (int j=0; j < BOARD_HEIGHT; j++) {
		fgets(s, 100, f); /* récuperer une ligne du fichier */

		for (int i=0; i < BOARD_WIDTH; i++) {
			if (s[i] == 'x') { /* si on rencontre un 'x' dans le fichier */
				board[i][j] = 1; /* on initialise la case comme vivante */
			} else { /* sinon */
				board[i][j] = 0; /* on initialise la case comme morte */
			}
		}
	}
	
	/* A FAIRE :
		fermer le fichier
	*/
}

/* affiche le tableau de jeu dans la console */

void print(int board[BOARD_WIDTH][BOARD_HEIGHT]) {

	/* A FAIRE : afficher le tableau de jeu
		il faut itérer sur chacune des cases du tableau (board) (iteration sur les lignes et les colonnes)

		si une case contient un 1, on affiche un 'x'
		si une case contient un 0, on affiche un ' ' (espace)

		ne pas oublier de faire un retour a la ligne apreès avoir afficher une ligne
	*/

	usleep(500000); /* on attend 500 milisecondes (permet de fixer la vitesse d'affichage -> ici 2fps) */
	puts("\033[H\033[J"); /* efface l'écran pour l'affichage suivant */
}

/* retourne le nombre de voisins vivants d'une case 
	x et y : coordonnees de la case
*/

int adjacent_to(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y) {

	/* A FAIRE : compter le nombre de voisins vivant autour d'une case (de coordonnée x, y)
		il faut parcourir les cases autour de la case de coordonnée x, y
		puis compter le nombre de ces cases qui sont vivantes (de valeur 1)

		!attention! : lorsque la case du milieu est sur une bordure, il faut prendre en compte les cases de l'autre côté du tableau de jeu
		(un peu comme dans certains snake ou l'on peut traverser l'écran a gauche et ressortir a droite)

		on retourne a la fin le nombre de cases vivantes adjacentes
	*/
}

/*  parcours toute les cases du jeux et détermine leurs prochains états
	pour chaque case:
		- on compte le nombre de voisins vivants (utiliser un appel de fonction)
		selon le nombre de voisins vivants:
			- 2 -> on ne change pas la case.
			- 3 -> la case devient vivante.
			- moins de 2 ou plus de 3 -> la case devient morte.

	un tableau temporaire (newboard) est utilisé afin d'effectuer le changement d'état du jeu.
*/

void play(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
	int	newboard[BOARD_WIDTH][BOARD_HEIGHT];

	for (int i=0; i < BOARD_WIDTH; i++) { /* itération sur les colonnes */
		for (int j=0; j < BOARD_HEIGHT; j++) { /* itération sur les lignes */
			/* A FAIRE :
				compter le nombre de voisins vivants (utiliser fonction adjacent_to)

				déterminer le prochain état de chaque case selon les regles décrites au dessus de la fonction play. (utiliser des conditions if/else)
				!attention! : il faut modifier l'etat des cases dans le tableau de jeu "newboard"
			*/
		}
	}

	/* remplace l'ancien tableau de jeu par celui mis a jour */
	for (int i=0; i < BOARD_WIDTH; i++) {
		for (int j=0; j < BOARD_HEIGHT; j++) {
			board[i][j] = newboard[i][j];
		}
	}
}

/* programme principal */

int main (int argc, char *argv[]) {
	int	board[BOARD_WIDTH][BOARD_HEIGHT]; /* création du tableau de jeu */
	read_file(board, argv[1]); /* initialisation du tableau de jeu en utilisant un fichier */

	while(1) { /* boucle principale infinie */
		/* A FAIRE: (utiliser les fonctions définies plus haut)
			affichage du jeu
			mise a jour du jeu
		*/
	}
}

