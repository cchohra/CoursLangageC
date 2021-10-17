#include <stdio.h>
#include <stdlib.h>

/*
Calculer la surface et le périmetre d'un rectangle
    - Lire la largeur et la longueur
    - Calculer la surface et le périmètre
    - Afficher les variable calculées
*/

int main()
{
    float largeur, longueur, surface, perimetre;
    // Lire la largeur et la longueur
    printf("Ce programme calcule la surface et le perimetre d'un rectangle\n");
    printf("Donnez la largeur du rectangle : ");
    scanf("%f", &largeur);
    printf("Donnez la longueur du rectangle : ");
    scanf("%f", &longueur);
    // Calculer la surface
    surface = largeur * longueur;
    // Calculer la surface
    perimetre = 2 * (largeur + longueur);
    // Afficher les résultats
    printf("La surface du rectangle est : %g\nLe perimetre du rectangle est : %g", surface, perimetre);
    return 0;
}
