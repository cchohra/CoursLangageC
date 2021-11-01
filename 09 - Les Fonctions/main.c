#include <stdio.h>
#include <stdlib.h>

/*
    Les sous programmes
        - Utilisés pour décomposer le problème en sous problèmes plus simples.
        - Aussi utilisés pour éviter la répétition du même code plusieurs fois.
        - Pas de procedure, que des fonctions.
        - Une fonction est définie par :
            * Type, Nom, Arguments.
        - Les fonctions de type "void" sont l'équivalent des procedures.
        - Tous les paramètres sont passés par valeur (pas de passage par variable).
        - La foncttion "doit" retourner une valeur à la fin de son execution (sauf les fonctions de type void).
        - L'instruction return est la dernière instruction à executer dans une fonction.
            * Les instructions après la commande "return" sont toutes ignorées.

    Les variables :
        - Les variables déclarées dans une fonction ne sont pas visibles pour les autres fonctions.
        - Les variables globales peuvent être utilisées par toutes les fonction (pas recommandé).
*/

// Une fonction qui calcule la somme de deux nombres entiers
int somme(int a, int b) {
    int c;
    c = a + b;
    return c;
}

int main() {
    int x, y, z;
    printf("Donnez la valeur de x : ");
    scanf("%d", &x);
    printf("Donnez la valeur de y : ");
    scanf("%d", &y);
    // Appelle à la fonction et affectation du résultat à la variable z
    z = somme(x, y);
    printf("%d + %d = %d\n", x, y, z);
    return 0;
}
