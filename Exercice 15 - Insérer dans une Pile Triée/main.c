#include <stdio.h>
#include <stdlib.h>

/*
    Nous allons écrire une fonction qui permet d'insérer un nombre
    dans une pile d'entiers triés. Puis nous allons écrire
    un petit programme pour tester la fonction.
*/

#define n 10

typedef struct pile {
    int tab[n];
    int sommet;
} pile;

int estVide(pile P) {
    return (P.sommet == -1);
}

int estPleine(pile P) {
    return (P.sommet == n-1);
}

int sommet(pile P) {
    if (estVide(P)) {
        printf("Erreur dans la fonction sommet : La pile est vide");
        exit(0);
    }
    else {
        return P.tab[P.sommet];
    }
}

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

// Une fonction qui permet d'insérer un élément dans une pile triée
void insererPileTriee(pile *P, int v) {
    if (estPleine(*P)) {
        printf("Erreur dans la fonction insererPileTriiee : La pile est pleine, impossible d'empiler");
    }
    else {
        pile Q = initialeserPileVide();
        // D'abord dépiler tous les éléments supérieurs à v
        // et les garder dans une pile Q
        while (!estVide(*P) && sommet(*P) > v) {
            int x = depiler(P);
            empiler(&Q, x);
        }
        // Empiler v
        empiler(P, v);
        // Puis retourner les éléments gardés dans Q
        while (!estVide(Q)) {
            int x = depiler(&Q);
            empiler(P, x);
        }
    }
}

int main()
{
    pile P = initialeserPileVide();
    empiler(&P, 2);
    empiler(&P, 5);
    empiler(&P, 10);
    empiler(&P, 25);
    empiler(&P, 30);
    printf("La pile avant insertion\n");
    afficher(P);
    insererPileTriee(&P, 14);
    printf("La pile apres insertion\n");
    afficher(P);
    insererPileTriee(&P, 1);
    printf("La pile apres insertion de 1\n");
    afficher(P);
    return 0;
}
