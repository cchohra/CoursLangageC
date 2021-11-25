#include <stdio.h>
#include <stdlib.h>

/*
    - Stocker l'adresse mémoire d'une valeur, ou une variable
    - La déclaration d'un pointeur se fait avec la syntaxe suivante :
        * "type *nom";
        * Cette déclaration signifie que la variable "nom" peut garder
          l'adresse mémoire d'une valeur ou variable avec le type donné.
    - Il est possible de réserver et libérer dynamiquement l'espace memoire
      a référencer par un pointeur :
        * La fonction "malloc" est utilisée pour réserver de l'éspace mémoire :
            > "p = malloc(taille en octet)";
        * La fonction "free" est utilisée pour libérer l'espace réservé :
            > "free(p)";
    - Il est aussi possible de chercher la référence d'une variable existante :
        * "p = &a" : retrouve l'adresse de la variable "a" et la stocke dans "p".
    - Manipuler les pointeurs :
        * l'acces à la valeur/variable stockée à l'adresse "p" se fait avec "*p".
        * L'affectation "p = q" quand les deux sont des pointeur recopie l'adresse
          qui était dans la variable "q" sur la variable "p".
*/

int main()
{
    int a = 5;
    int *p; // Déclaration d'un pointeur sur un entier
    int *q;
    q = malloc(sizeof(int)); // Créer un espace mémoire à référencer par q.
    p = &a; // p garde l'adresse mémoire de a
    *q = 10; // ecrire la valeur 10 à l'adresse q;
    printf("q = %ld\n", q); // Affiche l'adresse référencée par "q".
    printf("p = %ld\n", p); // Affiche l'adresse référencée par "p" (l'adresse de a).
    printf("*q = %d\n", *q); // Afficher la valeur à l'adresse q (affiche 10).
    printf("*p = %d\n", *p); // Afficher la valeur à l'adresse p (valeur de a = 5).
    a = 8;
    printf("*p = %d (après changement de a)\n", *p); // Afficher la nouvalle valeur de a = 8.
    *p = 52;
    // La valeur de "a" change également si on affecte une nouvelle valeur à "*p".
    printf("a = %d (après changement de *p)\n", a);
    free(q); // Libération de l'espace réservé pour q.
    q = p; // Maintenant "q" et "p" pointent sur la même adresse (adresse de a).
    printf("*q = %d\n", *q); // Affiche la valeur de a : 52.
    *q = 60;
    // Le changemet de "*q" se voit sur "*p" et "a" également.
    printf("*p = %d (après changement de *q)\n", *p);
    printf("a = %d (après changement de *q)\n", a);
    return 0;
}
