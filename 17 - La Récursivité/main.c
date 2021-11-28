#include <stdio.h>
#include <stdlib.h>

/*
    La r�cursivit� : c'est juste une fonction qui fait appel � elle m�me
        - D�composer le probl�me en sous-probl�mes de m�me nature.
        - La d�composition conduit � un cas �l�mentaire.

    Exemples :
    1. Calcul de la factorielle
        - n! = n * (n - 1)!.
        - 0! = 1.
    2. Calcul de la puissance
        - m ^ n = m * m ^ (n - 1).
        - m ^ 0 = 1.

    Puis �crire un programme qui demande de saisir deux entiers positifs "n" et "m"
    et qui calcule et affiche les trois valeurs suivantes : n!, m!, n ^ m.
*/

int factorielle(int n) {
    if (n == 0) return 1; // Cas �l�mentaire
    else return n * factorielle(n - 1); // Relation de r�currence
}

int puissance(int m, int n) {
    if (n == 0) return 1; // Cas �l�mentaire
    else return m * puissance(m, n - 1); // Relation de r�currence
}

int main() {
    int n, m, f1, f2, p;
    printf("Donnez la valeur de n : ");
    scanf("%d", &n);
    printf("Donnez la valeur de m : ");
    scanf("%d", &m);
    f1 = factorielle(n);
    f2 = factorielle(m);
    p = puissance(m, n);
    printf("%d! = %d\n", n, f1);
    printf("%d! = %d\n", m, f2);
    printf("%d ^ %d = %d\n", m, n, p);
    return 0;
}
