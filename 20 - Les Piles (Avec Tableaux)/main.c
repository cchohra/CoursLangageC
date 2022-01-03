#include <stdio.h>
#include <stdlib.h>

/*
    Le but de ce projet et de déclarer le type "Pile" en utilisant les tableaux.
        - Définir la structure du type "Pile".
        - Déclarer les fonctions :
            * empiler.
            * dépiler.
            * sommet.
            * pileVide.
            * pilePleine.

    Par la suite nous déclarer une fonction qui affiche les éléments d'une Pile, et tester
    les diffrentes fonctions dans le programme principal.
*/

#define n 5

typedef struct pile {
    int tab[n];
    int sommet;
} pile;

// Une fonction qui teste si la pile est vide
int estVide(pile P) {
    return (P.sommet == -1);
}

// Une fonction qui teste si la pile est pleine
int estPleine(pile P) {
    return (P.sommet == n-1);
}

// Une fonction qui retourne le sommet de la pile
int sommet(pile P) {
    if (estVide(P)) {
        printf("Erreur dans la fonction sommet : La pile est vide");
        exit(0);
    }
    else {
        return P.tab[P.sommet];
    }
}

// Une fonction qui ajoute un élément au dessus des autres élément dans la pile
void empiler(pile *P, int v) {
    if (estPleine(*P)) {
        printf("Erreur dans la fonction empiler : La pile est pleine, impossible d'empiler");
        exit(0);
    }
    else {
        (*P).sommet = (*P).sommet + 1;
        (*P).tab[(*P).sommet] = v;
    }
}

// Une fonction qui retourne le sommet et le supprime de la pile
int depiler(pile *P) {
    if (estVide(*P)) {
        printf("Erreur dans la fonction depiler : La pile est vide");
        exit(0);
    }
    else {
        int v = (*P).tab[(*P).sommet];
        (*P).sommet = (*P).sommet - 1;
        return v;
    }
}

// Une fonction qui initialise une pile vide
pile initialeserPileVide() {
    pile P;
    P.sommet = -1;
    return P;
}

void afficher(pile P) {
    if (estVide(P)) {
        printf("Pile vide, rien a afficher");
    }
    else {
        pile Q = initialeserPileVide();
        int x;
        while (!estVide(P)) {
            x = depiler(&P);
            printf("%d\n", x);
            empiler(&Q, x);
        }
        while (!estVide(Q)) {
            x = depiler(&Q);
            empiler(&P, x);
        }
    }
}

int main()
{
    pile P = initialeserPileVide();
    empiler(&P, 5);
    empiler(&P, 7);
    empiler(&P, 3);
    afficher(P);
    int x = sommet(P);
    printf("Le premier element dans la pile est %d\n", x);
    x = depiler(&P);
    printf("L'element depile est est %d\n", x);
    printf("La pile apres l'operation depiler\n");
    afficher(P);
    return 0;
}
