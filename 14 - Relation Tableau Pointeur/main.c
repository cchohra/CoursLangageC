#include <stdio.h>
#include <stdlib.h>

/*
    - Dans le langage C, un tableau est d�fini par l'adresse de son premier �l�ment.
    - Il est possible de d�clarer des tableaux de taille dynamique en utilisant
      la fonction "malloc" avec la taille voulue.
        * Exemple : int *T = malloc(sizeof(int) * n);
          pour r�server l'espace d'un tableau d'entiers de taille "n".
        * Cet espace m�moire doit �tre lib�r� avec la fonction "free".
*/

#define n 6

int main() {

    // "n" doit �tre connu pour d�clarer un trableau avec cette syntaxe
    // sur les compilateur les plus r�cents �a marche pour un "n" variable aussi
    // n�anmoins, cela r�duit la portabilit� du code.
    int T[n] = {5, 9, 4, 2, 7, 1};
    printf("*T = %d\n", *T); // Un tableau peut �tre consid�r� comme un pointeur
                             // sur sa premi�re valeur (Affiche 5).
    int *p = &T[2];
    printf("*p = %d\n", *p); // Affiche 4.
    printf("p[0] = %d\n", p[0]); // Un pointeur "p" peut aussi �tre utilis� comme un tableau
                          // qui commence � l'adresse "p" (affiche 4 aussi).
    printf("p[1] = %d\n", p[1]); // Affiche 2.
    printf("p[-1] = %d\n", p[-1]); // Affiche 9.

    p[-1] = 18; // Faites attention aux adresses, cette instruction change T[1] aussi.
    printf("T[1] = %d\n", T[1]); // Affiche 18.

    printf("l'adresse p : %ld\n", p);
    p = p + 1; // Une incr�mentation de 1, fait avancer le pointeur "p" � l'adresse de
               // la variable suivante (+4 dans le cas d'un entier)
    printf("l'adresse p : %ld (apres incrementation de 1)\n", p);

    // POUR RESERVER DES TABLEAUX DE TAILLE "n" AVEC "n" VARIABLE
    int m;
    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &m);
    int *V = malloc(sizeof(int) * m); // R�server l'espace m�moire pour "m" entier
    printf("L'espace memoire pour un tableau de taille %d est reserve\n", m);
    // Utiliser "V" comme tableau de "m" entier.
    free(V); // Il faut lib�rer l'espace m�moire apr�s l'utilisation.
    printf("L'espace memoire pour un tableau de taille %d est libere\n", m);

    return 0;

}
