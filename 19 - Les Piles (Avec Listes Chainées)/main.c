#include <stdio.h>
#include <stdlib.h>

/*
    Le but de ce projet et de déclarer le type "Pile" en utilisant les listes chaînées.
        - Définir la structure du type "Pile".
        - Déclarer les fonctions :
            * empiler.
            * dépiler.
            * pileVide.
            * sommet.
        - Nous n'avons pas besoin de déclarer la fonction "pilePleine" car les listes
          chaînées n'ont pas de limitation sur le nombre d'éléments.

    Par la suite nous déclarer une fonction qui affiche les éléments d'une Pile, et tester
    les diffrentes fonctions dans le programme principal.
*/

typedef struct noeud *pile;

typedef struct noeud {
    int val;
    pile suiv;
} noeud;

// Une fonction qui teste si la pile est vide
int estVide(pile P) {
    return P == NULL;
}

// Une fonction qui retourne le sommet de la pile
int sommet(pile P) {
    if (estVide(P)) {
        printf("Erreur dans la fonction sommet : La pile est vide");
        exit(0);
    }
    else {
        return P->val;
    }
}

// Une fonction qui ajoute un élément au dessus des autres élément dans la pile
pile empiler(pile P, int v) {
    pile Q = malloc(sizeof(noeud));
    Q->val = v;
    Q->suiv = P;
    return Q;
}

// Une fonction qui retourne le sommet et le supprime de la pile
int depiler(pile* P) {
    if (estVide(*P)) {
        printf("Erreur dans la fonction depiler : La pile est vide");
        exit(0);
    }
    int v = (*P)->val;
    pile Q = *P;
    (*P) = (*P)->suiv;
    free(Q);
    return v;
}

/*
pile depiler(pile P, int* v) {
    if (estVide(P)) {
        printf("Erreur dans la fonction depiler : La pile est vide");
        exit(0);
    }
    *v = P->val;
    pile q = P;
    P = P->suiv;
    free(q);
    return P;
}

void afficher(pile P) {
    pile q = p;
    while (q != NULL) {
        printf("%d\n", q->val);
        q = q->suiv;
    }
}

pile afficher(pile P) {
    if (estVide(P)) {
        printf("Rien a afficher, la pile est vide\n");
    }
    else {
        int x;
        pile Q = NULL;
        while (!estVide(P)) {
            x = depiler(&P);
            printf("%d\n", x);
            Q = empiler(Q, x);
        }
        while (!estVide(Q)) {
            x = depiler(&Q);
            P = empiler(P, x);
        }
    }
    return P;
}
*/

void afficher(pile *P) {
    if (estVide(*P)) {
        printf("Rien a afficher, la pile est vide\n");
    }
    else {
        int x;
        pile Q = NULL;
        while (!estVide(*P)) {
            x = depiler(P);
            printf("%d\n", x);
            Q = empiler(Q, x);
        }
        while (!estVide(Q)) {
            x = depiler(&Q);
            (*P) = empiler((*P), x);
        }
    }
}

int main()
{
    pile P = NULL;
    P = empiler(P, 5);
    P = empiler(P, 7);
    P = empiler(P, 3);
    afficher(&P);
    int x = sommet(P);
    printf("Le premier element dans la pile est %d\n", x);
    x = depiler(&P);
    printf("L'element depile est est %d\n", x);
    printf("La pile apres l'operation depiler\n");
    afficher(&P);
    return 0;
}
