#include <stdio.h>
#include <stdlib.h>

/*
    Ecrire un programme permettant d'ins�rer des �l�ments dans une liste tri�e
        - Commancer par la d�claration de la fonction "insererTriee(L, v)".
        - D�clarer une liste L, et ins�rer des �l�ments dans un ordre al�atoire.
        - Afficher la liste � la fin pour v�rifier si elle est tri�e.
*/

typedef struct noeud *liste; // Une liste est un pointeur sur un noeud (tr�s simplement)

typedef struct noeud { // Un noeud est une enregistrement qui contient :
    int val;           // Une valeur.
    liste suiv;        // Une liste (pointeur sur un autre noeud).
} noeud;

// Une fonction qui affiche tous les �l�ments d'une liste "L"
void afficher(liste L) {
    liste p = L; // D�finir une liste (pointeur) qui r�f�rence le premier
                 // noeud de "L"
                 // Attention : il ne faut pas utiliser la t�te de la liste
                 // pour parcourir ses �l�ments, on ne peut parcourir la liste
                 // que dans un sens. Il serait possible dans certains cas
                 // de perdre les �l�ments de la liste si vous d�placez la t�te.
    while (p != NULL) { // Tant qu'on n'a pas atteint la fin de la liste
        printf("%d\n", p->val); // Officher l'�l�ment dans le noeud actuel.
        p = p->suiv; // Donner � "p" l'adresse du noeud suivant.
                     // Si le noeud suivant n'existe pas, "p" va recevoir
                     // la valeur "NULL".
    }
}

// Ins�rer un �l�ment dans une liste tri�e
liste insererTriee(liste L, int v) {
    liste p = malloc(sizeof(noeud));
    p->val = v;
    p->suiv = NULL;
    if (L == NULL || v < L->val) { // Si la liste est vide, ou si l'�l�ment � ins�rer
                                   // est inf�rieur au premier �l�ment de la liste
        p->suiv = L;               // Insertion � la t�te
        return p;
    }
    else {                         // Sinon, placer l'�lement � ins�rer juste avant
                                   // le premier �l�ment sup�rieur
        liste q = L;               // Ou � la fin de la liste s'il est sup�rieur
        liste r = L->suiv;         // � tous les �l�ments.
        while (r != NULL && r->val < v) {
            r = r->suiv;
            q = q->suiv;
        }
        q->suiv = p;
        p->suiv = r;
        return L;
    }
}

// Ins�rer un �l�ment dans une liste tri�e r�cursivement
liste insererTrieeRec(liste L, int v) {
    if (L == NULL || v < L->val) { // Cas �l�mentaire
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = L;
        return p;
    }
    else { // Relation de r�currence
        L->suiv = insererTrieeRec(L->suiv, v);
        return L;
    }
}

int main() {
    liste L = NULL; // Initialiser une liste vide
    L = insererTriee(L, 10);
    L = insererTriee(L, 15);
    L = insererTriee(L, 7);
    L = insererTriee(L, 2);
    L = insererTriee(L, 4);
    afficher(L);    // Afficher la liste L
}
