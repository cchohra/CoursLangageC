#include <stdio.h>
#include <stdlib.h>

/*
    Les tableaux?
        - Cr�er et organiser une s�rie de valeurs du m�me type.
            * Stocker un certain nombre de notes pour calculer la moyenne.
            * Les chaines de caract�res
            * ... etc.
        - Pour d�clarer un tableau, nous utilisons la syntaxe suivante :
            * type nom[taille].
            * Recommand� : la taille du tableau doit �tre une valeur constante.
            * Je vous montre prochainement comment d�clarer des tableaux
              de taille variable.
        - Chaque �l�ment du tableau est accessible via son indice.
            * L'indexation des tableaux dans le langage C commence � "0".
            * Le dernier indice dans un tableau de taille "n" est "n - 1".
            * Nous utilisons la syntaxe T[i] pour acc�der � l'�l�ment � l'indice "i"
              dans le tableau "T".
            * Attention : le langage C n'offre aucune protection contre le
              d�passement des bornes d'un tableau.
*/

// D�finir une valeur constante � utiliser comme taille de tableau
#define n 5

int main() {
    // D�clarer un tableau T de taille n
    int T[n];
    // Lire les �l�ments du tableau
    printf("Veuillez saisir les %d elements du tableau\n", n);
    for (int i = 0; i < n; i++) {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
    // Calculer la somme des �l�ments du tableau
    int S = 0;
    for (int i = 0; i < n; i++) {
        S = S + T[i];
    }
    // Calculer le produit des �l�ments du tableau
    int P = 1;
    for (int i = 0; i < n; i++) {
        P = P * T[i];
    }
    // Afficher les r�sultats
    printf("La somme des elements du tableau est : %d\n", S);
    printf("Le produit des elements du tableau est : %d\n", P);
    return 0;
}
