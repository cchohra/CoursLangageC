#include <stdio.h>
#include <stdlib.h>

/*
Ann�e bissextile : ann�e qui comporte 366 jours.
    - L'ann�e doit �tre divisible par 4.
    - Si l'ann�e est divisible par 100, elle doit aussi �tre divisible par 400.

Exemple : 2004, 2000.
Contre exemple : 2021, 1900.
*/

/*
Tester si une ann�e donn�e est bissextile
    - Lire l'ann�e.
    - Tester et dire si l'ann�e est bissextile ou pas.
*/

/*
    a && b -> v�rifier que a est vrai et b est vrai.
    a || b -> v�rifier que a est vrai ou bien b est vrai (ou les deux sont vrais).
    !a     -> v�rifier que a est faux.
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
