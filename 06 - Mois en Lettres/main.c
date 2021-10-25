#include <stdio.h>
#include <stdlib.h>

/*
Afficher un mois selon son ordre
    - Lire l'ordre (numéro) du mois.
    - Ecrire le mois en lettres.
*/

int main()
{
    int mois;
    printf("Saisir l'ordre du mois : ");
    scanf("%d", &mois);
    switch (mois) {
    case 1: // Si la variable mois est égale à 1
        printf("Janvier\n");
        break;
    case 2: // Si la variable mois est égale à 2
        printf("Fevrier\n");
        break;
    case 3: // Etc
        printf("Mars\n");
        break;
    case 4: // Etc
        printf("Avril\n");
        break;
    case 5:
        printf("Mai\n");
        break;
    case 6:
        printf("Juin\n");
        break;
    case 7:
        printf("Juillet\n");
        break;
    case 8:
        printf("Aout\n");
        break;
    case 9:
        printf("Septembre\n");
        break;
    case 10:
        printf("Octobre\n");
        break;
    case 11:
        printf("Novembre\n");
        break;
    case 12:
        printf("Decembre\n");
        break;
    default: // Si tous les cas précédents ne sont pas vérifiés
        printf("Je ne reconnais pas ce mois\n");
        break;
    }
    return 0;
}
