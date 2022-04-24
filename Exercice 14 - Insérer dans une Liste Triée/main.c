#include <stdio.h>
#include <stdlib.h>

/*
    Ecrire un programme permettant d'insérer des éléments dans une liste triée
        - Commancer par la déclaration de la fonction "insererTriee(L, v)".
        - Déclarer une liste L, et insérer des éléments dans un ordre aléatoire.
        - Afficher la liste à la fin pour vérifier si elle est triée.
*/

typedef struct noeud *liste; // Une liste est un pointeur sur un noeud (très simplement)

typedef struct noeud { // Un noeud est une enregistrement qui contient :
    int val;           // Une valeur.
    liste suiv;        // Une liste (pointeur sur un autre noeud).
} noeud;

// Une fonction qui affiche tous les éléments d'une liste "L"
void afficher(liste L) {
    liste p = L; // Définir une liste (pointeur) qui référence le premier
                 // noeud de "L"
                 // Attention : il ne faut pas utiliser la tête de la liste
                 // pour parcourir ses éléments, on ne peut parcourir la liste
                 // que dans un sens. Il serait possible dans certains cas
                 // de perdre les éléments de la liste si vous déplacez la tête.
    while (p != NULL) { // Tant qu'on n'a pas atteint la fin de la liste
        printf("%d\n", p->val); // Officher l'élément dans le noeud actuel.
        p = p->suiv; // Donner à "p" l'adresse du noeud suivant.
                     // Si le noeud suivant n'existe pas, "p" va recevoir
                     // la valeur "NULL".
    }
}

// Insérer un élément dans une liste triée
liste insererTriee(liste L, int v) {
    liste p = malloc(sizeof(noeud));
    p->val = v;
    p->suiv = NULL;
    if (L == NULL || v < L->val) { // Si la liste est vide, ou si l'élément à insérer
                                   // est inférieur au premier élément de la liste
        p->suiv = L;               // Insertion à la tête
        return p;
    }
    else {                         // Sinon, placer l'élement à insérer juste avant
                                   // le premier élément supérieur
        liste q = L;               // Ou à la fin de la liste s'il est supérieur
        liste r = L->suiv;         // à tous les éléments.
        while (r != NULL && r->val < v) {
            r = r->suiv;
            q = q->suiv;
        }
        q->suiv = p;
        p->suiv = r;
        return L;
    }
}

// Insérer un élément dans une liste triée récursivement
liste insererTrieeRec(liste L, int v) {
    if (L == NULL || v < L->val) { // Cas élémentaire
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = L;
        return p;
    }
    else { // Relation de récurrence
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
