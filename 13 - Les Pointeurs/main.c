#include <stdio.h>
#include <stdlib.h>

/*
    - Stocker l'adresse m�moire d'une valeur, ou une variable
    - La d�claration d'un pointeur se fait avec la syntaxe suivante :
        * "type *nom";
        * Cette d�claration signifie que la variable "nom" peut garder
          l'adresse m�moire d'une valeur ou variable avec le type donn�.
    - Il est possible de r�server et lib�rer dynamiquement l'espace memoire
      a r�f�rencer par un pointeur :
        * La fonction "malloc" est utilis�e pour r�server de l'�space m�moire :
            > "p = malloc(taille en octet)";
        * La fonction "free" est utilis�e pour lib�rer l'espace r�serv� :
            > "free(p)";
    - Il est aussi possible de chercher la r�f�rence d'une variable existante :
        * "p = &a" : retrouve l'adresse de la variable "a" et la stocke dans "p".
    - Manipuler les pointeurs :
        * l'acces � la valeur/variable stock�e � l'adresse "p" se fait avec "*p".
        * L'affectation "p = q" quand les deux sont des pointeur recopie l'adresse
          qui �tait dans la variable "q" sur la variable "p".
*/

int main()
{
    int a = 5;
    int *p; // D�claration d'un pointeur sur un entier
    int *q;
    q = malloc(sizeof(int)); // Cr�er un espace m�moire � r�f�rencer par q.
    p = &a; // p garde l'adresse m�moire de a
    *q = 10; // ecrire la valeur 10 � l'adresse q;
    printf("q = %ld\n", q); // Affiche l'adresse r�f�renc�e par "q".
    printf("p = %ld\n", p); // Affiche l'adresse r�f�renc�e par "p" (l'adresse de a).
    printf("*q = %d\n", *q); // Afficher la valeur � l'adresse q (affiche 10).
    printf("*p = %d\n", *p); // Afficher la valeur � l'adresse p (valeur de a = 5).
    a = 8;
    printf("*p = %d (apr�s changement de a)\n", *p); // Afficher la nouvalle valeur de a = 8.
    *p = 52;
    // La valeur de "a" change �galement si on affecte une nouvelle valeur � "*p".
    printf("a = %d (apr�s changement de *p)\n", a);
    free(q); // Lib�ration de l'espace r�serv� pour q.
    q = p; // Maintenant "q" et "p" pointent sur la m�me adresse (adresse de a).
    printf("*q = %d\n", *q); // Affiche la valeur de a : 52.
    *q = 60;
    // Le changemet de "*q" se voit sur "*p" et "a" �galement.
    printf("*p = %d (apr�s changement de *q)\n", *p);
    printf("a = %d (apr�s changement de *q)\n", a);
    return 0;
}
