#include <stdio.h>
#include <stdlib.h>

/*
Un programme qui affiche les n premiers entiers positifs (à partir de 1) avec n donné par l'utilisateur
    - Demander à l'utilisateur de donner un nombre entier strictement positif n.
    - Afficher tous les nombres de 1 jusqu'à n.
*/

int main()
{
    int n, x;
    printf("Veuillez saisir la valeur de n : ");
    do { // Au moins une seule itération
        scanf("%d", &n);
        if (n <= 0) { // Afficher ce message si n est inférieur à 1
            printf("Erreur, veuillez saisir un nombre strictement positif : ");
        }
    } while (n <= 0);
    // Sortir de la boucle quand n est strictement positif
    // Solution avec la boucle for
    for (x = 1; x <= n; x++) { // X prend les valeurs de 1 à n
        printf("%d\n", x);
    }
    /*
    x = 1;
    // Solution avec la boucle while
    while (x <= n) { // Condition de la boucle
        printf("%d\n", x);
        x = x + 1; // Incrémentation de X pour atteindre la valeur n
    }
    */
    return 0;
}
