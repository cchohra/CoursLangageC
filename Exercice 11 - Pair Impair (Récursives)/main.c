#include <stdio.h>
#include <stdlib.h>

/*
    Nous allons déclarer les deux fonctions suivantes :
        - La fonction "pair" : qui prend comme argument un entier positif "n"
          et qui retourne "1" si "n" est pair, et "0" sinon.
        - La fonction "impair" : qui prend comme argument un entier positif "n"
          et qui retourne "1" si "n" est impair, et "0" sinon.
    Les deux fonctions doivent être définies en récursion mutuelle comme suit :
        - La fonction pair :
            * Si "n = 0" retourner 1.
            * Sinon retourner impair(n - 1).
        - La fonction impair :
            * Si "n = 0" retourner 0.
            * Sinon retourner pair(n - 1).
*/

int impair(int n);

int pair(int n) {
    if (n == 0) return 1;
    else return impair(n - 1);
}

int impair(int n) {
    if (n == 0) return 0;
    else return pair(n - 1);
}

int main() {
    int n;
    printf("Donnez la valeur de n : ");
    scanf("%d", &n);
    if (pair(n)) printf("%d est un nombre pair\n", n);
    if (impair(n)) printf("%d est un nombre impair\n", n);
    return 0;
}
