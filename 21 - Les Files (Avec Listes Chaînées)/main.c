#include <stdio.h>
#include <stdlib.h>

/*
    Le but de ce projet et de déclarer le type "File" en utilisant les listes chaînées.
        - Définir la structure du type "File".
        - Déclarer les fonctions :
            * enfiler.
            * défiler.
            * estVide.
            * tete.
        - Nous n'avons pas besoin de déclarer la fonction "estPleine" car les listes
          chaînées n'ont pas de limitation sur le nombre d'éléments.

    Par la suite nous déclarer une fonction qui affiche les éléments d'une File, et tester
    les diffrentes fonctions dans le programme principal.
*/

typedef struct noeud noeud;

typedef noeud *file;

typedef struct noeud {
    int val;
    file suiv;
} noeud;

// Une fonction qui teste si la file est vide
int estVide(file F) {
    return F == NULL;
}

// Une fonction qui retourne l'element à la tête d'une file
int tete(file F) {
    if (estVide(F)) {
        printf("Erreur : La file est vide");
        exit(0);
    }
    else {
        return F->val;
    }
}

// Une fonction qui ajoute un élément à la fin d'une file
void enfiler(file *F, int v) {
    if ((*F) == NULL) {
        (*F) = malloc(sizeof(noeud));
        (*F)->val = v;
        (*F)->suiv = NULL;
    }
    else {
        enfiler(&((*F)->suiv), v);
    }
}

// Une fonction qui retourne la tête et la supprime de la file
int defiler(file* F) {
    if (estVide(*F)) {
        printf("Erreur : La file est vide");
        exit(0);
    }
    else {
        file F1 = *F;
        int v = F1->val;
        *F = (*F)->suiv;
        free(F1);
        return v;
    }
}

// Une fonction qui affiche les éléments d'une file
void afficher(file* F) {
    file F1 = NULL;
    while (!estVide(*F)) {
        int x = defiler(F);
        printf("%d\n", x);
        enfiler(&F1, x);
    }
    while (!estVide(F1)) {
        int x = defiler(&F1);
        enfiler(F, x);
    }
}

int main()
{
    file F = NULL;
    enfiler(&F, 5);
    enfiler(&F, 8);
    enfiler(&F, 7);
    enfiler(&F, 6);
    enfiler(&F, 2);
    printf("La file apres insertion\n");
    afficher(&F);
    printf("La tete de la file est %d\n", tete(F));
    int x = defiler(&F);
    printf("L'element defile est %d\n", x);
    printf("La file apres avoir defile\n");
    afficher(&F);
    return 0;
}
