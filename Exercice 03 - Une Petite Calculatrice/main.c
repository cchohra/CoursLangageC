#include <stdio.h>
#include <stdlib.h>

/*
L'objectif de cet exercice est de programmer une petite calculatrice sur console.
Le programme doit demander :
    - Le premier opérande.
    - L'opération à effectuer.
    - Le deuxième opérande.
Puis calcule et affiche le résultat de l'opération.
*/

int main()
{
    float a, b, c;
    char op;
    printf("Donner le premier operande : ");
    scanf("%g", &a);
    printf("Choisir l'operation (+, -, /, *) : ");
    scanf(" %c", &op);
    printf("Donner le deuxieme operande : ");
    scanf("%g", &b);
    switch (op) { // Prendre en compte toutes les opérations possible
    case '*' : // Cas de multiplication
        c = a * b;
        printf("%g * %g = %g\n", a, b, c);
        break;
    case '+' : // Cas d'addition
        c = a + b;
        printf("%g + %g = %g\n", a, b, c);
        break;
    case '-' : // Cas de soustraction
        c = a - b;
        printf("%g - %g = %g\n", a, b, c);
        break;
    case '/' : // Cas de division
        if (b != 0) { // Eviter la division par zéro
            c = a / b;
            printf("%g / %g = %g\n", a, b, c);
        }
        else {
            printf("Erreur, impossible de diviser par 0");
        }
        break;
    default : // Cas d'opération erronée
        printf("Operation non reconnue");
        break;
    }
    return 0;
}
