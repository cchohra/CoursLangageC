#include <stdio.h>
#include <stdlib.h>

/*
Année bissextile : année qui comporte 366 jours.
    - L'année doit être divisible par 4.
    - Si l'année est divisible par 100, elle doit aussi être divisible par 400.

Exemple : 2004, 2000.
Contre exemple : 2021, 1900.
*/

/*
Tester si une année donnée est bissextile
    - Lire l'année.
    - Tester et dire si l'année est bissextile ou pas.
*/

/*
    a && b -> vérifier que a est vrai et b est vrai.
    a || b -> vérifier que a est vrai ou bien b est vrai (ou les deux sont vrais).
    !a     -> vérifier que a est faux.
*/

int main()
{
    int annee;
    printf("Veuillez saisir l'annee a tester : ");
    scanf("%d", &annee);
    if (((annee % 4 == 0) && (annee % 100 != 0)) || ((annee % 4 == 0) && (annee % 100 == 0) && (annee % 400 == 0))) {
        printf("L'annee %d est bissextile", annee);
    }
    else {
        printf("L'annee %d n'est pas bissextile", annee);
    }
    return 0;
}
