#include <stdio.h>
#include <stdlib.h>

#define n 20

// Utiliser l'algorithme de tri � bulles pour trier les �l�ments d'un tableau
int main()
{
    // D�claration et initialisation du tableau
    int T[n] = {10, 46, 25, 5, 17, 37, 20, 36, 20, 35, 30, 26, 1, 8, 22, 39, 44, 38, 28, 15};
    int t = 0; // Une variable � utiliser pour tester si le tableau est tri�
    do {
        t = 1; // Nous supposons initialement que le tableau est tri�
        for (int i = 0; i < n - 1; i++) {
            if (T[i] > T[i + 1]) { // C'est deux �l�ments successifs ne sont pas tri�s
                t = 0; // Indiquer que le tableau T n'est pas tri�
                // Effectuer une permutation des deux �l�ments
                int temp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = temp;
            }
        }
    } while (t == 0);
    // Afficher le tableau apr�s l'avoir tri�
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
    return 0;
}
