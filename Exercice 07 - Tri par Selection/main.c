#include <stdio.h>
#include <stdlib.h>

#define n 20

// Utiliser l'algorithme de tri par selection pour trier les �l�ments d'un tableau
int main()
{
    // D�claration et initialisation du tableau
    int T[n] = {10, 46, 25, 5, 17, 37, 20, 36, 20, 35, 30, 26, 1, 8, 22, 39, 44, 38, 28, 15};
    for (int i = 0; i < n - 1; i++) {
        int min = T[i]; // Initialiser le minimum par le premier �l�ment � tester
        int indMin = i;
        for (int j = i + 1; j < n; j++) { // Tester les autres �l�ments
            if (T[j] < min) { // Changer le minimum si un �l�ment inf�rieur est trouv�
                min = T[j];
                indMin = j;
            }
        }
        // Faire une permutation
        int temp = T[i];
        T[i] = T[indMin];
        T[indMin] = temp;
    }
    // Afficher le tableau apr�s l'avoir tri�
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    return 0;
}
