#include <stdio.h>
#include <stdlib.h>

#define n 20

// Utiliser l'algorithme de tri à bulles pour trier les éléments d'un tableau
int main()
{
    // Déclaration et initialisation du tableau
    int T[n] = {10, 46, 25, 5, 17, 37, 20, 36, 20, 35, 30, 26, 1, 8, 22, 39, 44, 38, 28, 15};
    int t = 0; // Une variable à utiliser pour tester si le tableau est trié
    do {
        t = 1; // Nous supposons initialement que le tableau est trié
        for (int i = 0; i < n - 1; i++) {
            if (T[i] > T[i + 1]) { // C'est deux éléments successifs ne sont pas triés
                t = 0; // Indiquer que le tableau T n'est pas trié
                // Effectuer une permutation des deux éléments
                int temp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = temp;
            }
        }
    } while (t == 0);
    // Afficher le tableau après l'avoir trié
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    return 0;
}
