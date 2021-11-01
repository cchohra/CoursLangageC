#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Ce programme demande à l'utilisateur de saisir un nombre entier positif
    et puis détermine si ce dernier est premier ou pas.
    Un nombre n est premier si :
        - n > 1
        - n n'est divisible que par 1 et lui même.
    Le programme doit être décomposé au moins en deux fonctions
        - La fonction "premier" qui retourne "true" si son argument est premier,
          et "false" sinon.
        - La fonction main (programme principal) qui demande à l'utilisateur
          de saisir un nombre entier positif, et puis utilise la fonction
          "premier" pour tester s'il est premier ou pas.
*/

// Une fonction qui retourne 1 si son argument est premier et 0 sinon
bool premier(int n) {
    // Tester si le nombre est supérieur à 1
    if (n > 1) {
        // Tester s'il existe un nombre entier entre
        // "2" et "n / 2" qui divise n
        for (int i = 2; i <= n / 2; i++) {
            // Si un seul diviseur est trouvé, nous retournons "faux"
            if (n % i == 0) {
                return false;
            }
        }
        // Si aucun diviseur n'est trouvé, nous retournons "vrai"
        return true;
    }
    // Si "n" est inférieur ou égal à 1 alors retourner "faux"
    else {
        return false;
    }
}

// Une fonction qui affiche si un nombre donné est premier ou pas
void testerPremier(int n) {
    // Tester si "n" est premier
    if (premier(n)) {
        printf("Le nombre %d est premier\n", n);
    }
    else {
        printf("Le nombre %d n'est pas premier\n", n);
    }
}

int main() {
    int n;
    printf("Veuillez saisir un nombre entier positif : ");
    scanf("%d", &n);
    while (n < 2) {
        printf("%d est inferieur a 2\n", n);
        printf("Veuillez saisir un nombre entier positif : ");
        scanf("%d", &n);
    }
    // Appel à la fonction testerPremier
    testerPremier(n);
    return 0;
}
