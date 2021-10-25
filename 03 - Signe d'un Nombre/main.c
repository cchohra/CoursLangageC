#include <stdio.h>
#include <stdlib.h>

/*
Un programme qui affiche le signe d'un nombre saisi par l'utilisateur
    - Demander à l'utilisateur de saisir un nombre.
    - Tester et afficher le signe du nombre saisi.
*/

/*
    a > n;  Test si a est strictement supérieur à n
    a >= n; Test si a est supérieur ou égal à n
    a < n;  Test si a est strictement inférieur à n
    a <= n; Test si a est inférieur ou égal à n
    a == n; Test si a est égal à n
    a != n; Test si a est différent de n
*/

int main()
{
    int a;
    printf("Veuillez saisir un nombre entier : ");
    scanf("%d", &a); // Lire la valeur de a
    if (a > 0) { // Tester si a est supérieur à 0
        printf("Le nbombre %d est positif\n", a);
    }
    else {
        if (a < 0) { // Tester si a est inférieur à 0
            printf("Le nbombre %d est negatif\n", a);
        }
        else { // Le cas ou a est nul
            printf("Le nbombre %d est nul\n", a);
        }
    }
    return 0;
}
