#include <stdio.h>
#include <stdlib.h>

/*
Un programme qui affiche le signe d'un nombre saisi par l'utilisateur
    - Demander � l'utilisateur de saisir un nombre.
    - Tester et afficher le signe du nombre saisi.
*/

/*
    a > n;  Test si a est strictement sup�rieur � n
    a >= n; Test si a est sup�rieur ou �gal � n
    a < n;  Test si a est strictement inf�rieur � n
    a <= n; Test si a est inf�rieur ou �gal � n
    a == n; Test si a est �gal � n
    a != n; Test si a est diff�rent de n
*/

int main()
{
    int a;
    printf("Veuillez saisir un nombre entier : ");
    scanf("%d", &a); // Lire la valeur de a
    if (a > 0) { // Tester si a est sup�rieur � 0
        printf("Le nbombre %d est positif\n", a);
    }
    else {
        if (a < 0) { // Tester si a est inf�rieur � 0
            printf("Le nbombre %d est negatif\n", a);
        }
        else { // Le cas ou a est nul
            printf("Le nbombre %d est nul\n", a);
        }
    }
    return 0;
}
