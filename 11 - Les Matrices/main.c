#include <stdio.h>
#include <stdlib.h>

/*
    Une matrice est un tableau à deux dimensions.
    Une matrice peut également être vu un tableau de tableaux.
    Déclaration :
        - type nom[lignes][colonnes].
    Utilisation :
        - M[i][j].
        - i : indice de ligne.
        - j : indice de colonne.

    Exemple :
        Transposer une matrice.

*/

#define LIGNES 3
#define COLONNES 3

int main() {

    // Déclaration et initialisation de la matrice
    int M[LIGNES][COLONNES] = {{1, 9, 2}, {3, 7, 12}, {17, 8, 2}};

    printf("Affichage de la matrice avant le transpose\n");
    for (int i = 0; i < LIGNES; i++) { // Parcourir les lignes
        for (int j = 0; j < COLONNES; j++) { // Parcourir les colonnes pour chaque ligne
            printf("%d", M[i][j]);
            if (j != COLONNES - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    // Transposer la Matrice
    for (int i = 0; i < LIGNES; i++) {
        for (int j = i + 1; j < COLONNES; j++) {
            // Permutation des éléments symétriques
            int temp = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = temp;
        }
    }

    printf("Affichage de la matrice avant le transpose\n");
    for (int i = 0; i < LIGNES; i++) { // Parcourir les lignes
        for (int j = 0; j < COLONNES; j++) { // Parcourir les colonnes pour chaque ligne
            printf("%d", M[i][j]);
            if (j != COLONNES - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
