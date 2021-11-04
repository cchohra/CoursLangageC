#include <stdio.h>
#include <stdlib.h>

/*
    Les tableaux?
        - Créer et organiser une série de valeurs du même type.
            * Stocker un certain nombre de notes pour calculer la moyenne.
            * Les chaines de caractères
            * ... etc.
        - Pour déclarer un tableau, nous utilisons la syntaxe suivante :
            * type nom[taille].
            * Recommandé : la taille du tableau doit être une valeur constante.
            * Je vous montre prochainement comment déclarer des tableaux
              de taille variable.
        - Chaque élément du tableau est accessible via son indice.
            * L'indexation des tableaux dans le langage C commence à "0".
            * Le dernier indice dans un tableau de taille "n" est "n - 1".
            * Nous utilisons la syntaxe T[i] pour accéder à l'élément à l'indice "i"
              dans le tableau "T".
            * Attention : le langage C n'offre aucune protection contre le
              dépassement des bornes d'un tableau.
*/

// Définir une valeur constante à utiliser comme taille de tableau
#define n 5

int main() {
    // Déclarer un tableau T de taille n
    int T[n];
    // Lire les éléments du tableau
    printf("Veuillez saisir les %d elements du tableau\n", n);
    for (int i = 0; i < n; i++) {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
    // Calculer la somme des éléments du tableau
    int S = 0;
    for (int i = 0; i < n; i++) {
        S = S + T[i];
    }
    // Calculer le produit des éléments du tableau
    int P = 1;
    for (int i = 0; i < n; i++) {
        P = P * T[i];
    }
    // Afficher les résultats
    printf("La somme des elements du tableau est : %d\n", S);
    printf("Le produit des elements du tableau est : %d\n", P);
    return 0;
}
