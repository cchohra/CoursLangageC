#include <stdio.h>
#include <stdlib.h>

/*
Calculer la somme des n premiers nombres entiers positifs (à partir de 1)
    - Lire la valeur de n.
    - Calculer et afficher la somme 1 + 2 + 3 + ..... + n.
*/

int main()
{
    int n;
    printf("Veuillez saisir la valeur de n : ");
    do {
        scanf("%d", &n);
        if (n <= 0) {
            printf("Erreur, veuillez saisir un nombre strictement positif : ");
        }
    } while (n <= 0);
    int S = 0; // Initialisation de la somme
    // Solution avec boucle for
    for (int i = 1; i <= n; i++) {
        S = S + i; // S += i;
    }
    // Solution avec boucle while
    /*
    int i = 1;
    while (i <= n) {
        S = S + i;
        i = i + 1;
    }
    */
    printf("S = %d\n", S);
    return 0;
}
