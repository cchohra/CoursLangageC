#include <stdio.h>
#include <stdlib.h>

/*
    Les sous programmes
        - Utilis�s pour d�composer le probl�me en sous probl�mes plus simples.
        - Aussi utilis�s pour �viter la r�p�tition du m�me code plusieurs fois.
        - Pas de procedure, que des fonctions.
        - Une fonction est d�finie par :
            * Type, Nom, Arguments.
        - Les fonctions de type "void" sont l'�quivalent des procedures.
        - Tous les param�tres sont pass�s par valeur (pas de passage par variable).
        - La foncttion "doit" retourner une valeur � la fin de son execution (sauf les fonctions de type void).
        - L'instruction return est la derni�re instruction � executer dans une fonction.
            * Les instructions apr�s la commande "return" sont toutes ignor�es.

    Les variables :
        - Les variables d�clar�es dans une fonction ne sont pas visibles pour les autres fonctions.
        - Les variables globales peuvent �tre utilis�es par toutes les fonction (pas recommand�).
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
    // Appelle � la fonction et affectation du r�sultat � la variable z
    z = somme(x, y);
    printf("%d + %d = %d\n", x, y, z);
    return 0;
}
