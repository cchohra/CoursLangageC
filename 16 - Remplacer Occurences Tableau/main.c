#include <stdio.h>
#include <stdlib.h>

/*
    - Un tableau est toujours passé par adresse (dû à sa nature).

    Exemple : une fonction qui prend comme arguments un tableau "T"
              et deux valeurs "a" et "b" et qui remplace toutes
              les occurence de "a" dans "T" par "b".
*/

#define n 6

// Une fonction qui remplace les occurences de "a" par "b" dans le tableau "T"
void changerOccurences(int T[], int a, int b) {
    for (int i = 0; i < n; i++) {
        if (T[i] == a) {
            T[i] = b;
        }
    }
}

int main()
{
    int T[n] = {5, 9, 4, 5, 7, 1};
    printf("Le tableau avant changement\n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    // Les tableau passent toujours par adresse, pas besoin d'écrire "&T"
    changerOccurences(T, 5, 17);
    printf("Le tableau apres changement\n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    return 0;
}
