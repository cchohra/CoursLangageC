#include <stdio.h>
#include <stdlib.h>

/*
    - Tous les paramètre des fonctions sont passés par valeur
        * Les paramètres effectifs gardent leurs valeurs initiales
          avant l'appel de fonction.
    - Il est possible de passer l'adresse d'une variable pour
      pouvoir changer sa valeur dans une fonction.
        * La fonction doit prendre un pointeur comme argument :
            > type nom(type *argument);
        * Par la suite, nous devons passer l'adresse de la variable
          comme parametre effectif à la fonction
            > nom(&variable).
        * C'est similaire à l'utilisation de la fonction "scanf".
    - Un tableau est toujours passé par adresse (dû à sa nature).

    Exemple : une fonction qui prend comme argument deux entiers "a" et "b"
              et qui retourne comme résultat "x" et "y" tel que "a = b * x + y".
              - x = a div b.
              - y = a mod b.
*/

// Une fonction qui calcule "a div b" et "a mod b"
void modiv(int a, int b, int *x, int *y) { // les parametres "x" et "y" sont des pointeurs sur des entiers
    *x = a / b; // écrire dans la variable à l'adresse "x"
    *y = a % b; // écrire dans la variable à l'adresse "y"
}

int main()
{
    int a, b, mod, div;
    printf("Donnez la valeur de a : ");
    scanf("%d", &a);
    printf("Donnez la valeur de b : ");
    scanf("%d", &b);
    mod = 0;
    div = 0;
    modiv(a, b, &div, &mod); // Passer les adresses des variables "div" et "mod"
                             // pour que la fonction puisse changer leurs valeurs.
    printf("%d div %d = %d\n", a, b, div);
    printf("%d mod %d = %d\n", a, b, mod);
}
