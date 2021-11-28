#include <stdio.h>
#include <stdlib.h>

/*
    Nous allons écrire une fonction permettant d'inverser un tableau récursivement
    en suivant le processus suivant :
        - Si la taille du tableau est 0 (tableau vide) ou bien 1, le tableau n'est pas changer.
        - Sinon :
            1. Permuter le premier et le dernier élément.
            2. Faire une appel récursive sur le tableau contenant les éléments
               à partir du deuxième jusqu'à l'avant dernier.
*/

#define n 10

void inverser(int *T, int a) {
    // Si le tableau est vide, ou s'il contient un seul élément alors pas besoin de l'inverser
    if (a > 1) { // Si le tableau contient au moins deux éléments
        // Permuter le premier et le dernier élément
        int temp = T[0];
        T[0] = T[a - 1];
        T[a - 1] = temp;

        // Appel récursif avec un tableau qui commence par le deuxième élément
        inverser(&T[1], a - 2);
    }
}

int main() {
    int T[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Le tableau avant inversion : \n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    inverser(T, n);
    printf("Le tableau apres inversion : \n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    return 0;
}
