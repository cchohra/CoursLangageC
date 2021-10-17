#include <stdio.h>
#include <stdlib.h>

/*
Somme de deux nombres entiers
    - Lire la valeur des deux variables (a et b)
    - Calculer la valeur de c (= a + b)
    - Afficher la variable c
*/

int main()
{
    int a, b, c;
    printf("Ceci est un programme qui calcule la somme de deux nombres\n");
    printf("Veuillez donner la valeur de a : ");
    // Lire a
    scanf("%d", &a);
    printf("Veuillez donner la valeur de b : ");
    // Lire b
    scanf("%d", &b);
    // Calculer c
    c = a + b;
    // Afficher la somme
    printf("%d + %d = %d \n", a, b, c);
    return 0;
}
