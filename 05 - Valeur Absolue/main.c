#include <stdio.h>
#include <stdlib.h>

/*
Calculer la valeur absolue d'un nombre
    - Lire un nombre réel.
    - Calculer sa valeur absolue.
*/

int main()
{
    float x, y;
    printf("Donnez la valeur de x : ");
    scanf("%f", &x);
    y = (x > 0) ? x : -x;
/*
    if (x > 0) {
        y = x;
    }
    else {
        y = -x;
    }
*/
    printf("La valeur absolue de %g est %g", x, y);
    return 0;
}
