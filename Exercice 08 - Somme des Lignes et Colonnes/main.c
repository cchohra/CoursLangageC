#include <stdio.h>
#include <stdlib.h>

/*
    Un programme qui calcule et affiche la somme de chaque ligne et colonne d'une matrice
    Il doit afficher les messages suivants :
        - Les sommes des lignes
            * La somme de la ligne 1 est : ...
            * La somme de la ligne 2 est : ...
            *
            * La somme de la ligne n est : ...
        - Les sommes des colonnes
            * La somme de la colonne 1 est : ...
            * La somme de la colonne 2 est : ...
            *
            * La somme de la colonne n est : ...
*/

#define LIGNES 5
#define COLONNES 4

int main()
{
    // Déclaration et initialisation de la matrice
    int M[LIGNES][COLONNES] = { {10, 46, 25, 5},
                                {17, 37, 20, 36},
                                {20, 35, 30, 26},
                                {1, 8, 22, 39},
                                {44, 38, 28, 15} };

    printf("Calculer la somme de chaque ligne\n");
    for (int i = 0; i < LIGNES; i++) {
        int s = 0; // Initialiser pour calculer la somme de chaque ligne
        for (int j = 0; j < COLONNES; j++) {
            s = s + M[i][j];
        }
        printf("La somme de la ligne %d est %d\n", i + 1, s);
    }

    printf("Calculer la somme de chaque colonne\n");
    for (int j = 0; j < COLONNES; j++) {
        int s = 0; // Initialiser pour calculer la somme de chaque colonne
        for (int i = 0; i < LIGNES; i++) {
            s = s + M[i][j];
        }
        printf("La somme de la colonne %d est %d\n", j + 1, s);
    }

    return 0;
}
