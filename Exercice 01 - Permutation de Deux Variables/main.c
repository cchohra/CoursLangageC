#include <stdio.h>
#include <stdlib.h>

/*
Permutation de deux variables
    - Lire la valeur des deux variables (a et b)
    - Permuter les valeurs (a -> b, b -> a)
    - Afficher les nouvelles valeurs après permutation
*/

int main()
{
    float a, b, temp;
    // Lire la valeur de a
    printf("Veuillez saisir la valeur de a : ");
    scanf("%f", &a);
    // Lire la valeur de b
    printf("Veuillez saisir la valeur de b : ");
    scanf("%f", &b);
    // Algorithme de permutation
    temp = a;
    a = b;
    b = temp;
    // Afficher les valeurs après permutation
    printf("Les valeurs de a et b apres permutation\n");
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    return 0;
}
