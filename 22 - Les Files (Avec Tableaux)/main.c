#include <stdio.h>
#include <stdlib.h>

/*
    Le but de ce projet et de déclarer le type "File" en utilisant les tableaux.
        - Définir la structure du type "File".
        - Déclarer les fonctions :
            * enfiler.
            * défiler.
            * estVide.
            * estPleine.
            * tete.

    Par la suite nous déclarer une fonction qui affiche les éléments d'une File, et tester
    les diffrentes fonctions dans le programme principal.
*/

#define n 5

typedef struct file {
    int T[n];
    int tete;
    int fin;
} file;

// Une fonction qui teste si la file est vide
int estVide(file F) {
    return F.tete == F.fin;
}

// Une fonction qui teste si la file est pleine
int estPleine(file F) {
    return F.tete == (F.fin + 1) % n;
}

// Une fonction qui retourne l'element à la tête d'une file
int tete(file F) {
    if (estVide(F)) {
        printf("Erreur : la file est vide");
        exit(0);
    }
    else {
        return F.T[F.tete];
    }
}

// Une fonction qui ajoute un élément à la fin d'une file
void enfiler(file *F, int v) {
    if (estPleine(*F)) {
        printf("Erreur : impossible d'enfiler la file est pleine");
        exit(0);
    }
    else {
        (*F).T[((*F).fin)] = v;
        (*F).fin = ((*F).fin + 1) % n;
    }
}

// Une fonction qui retourne la tête et la supprime de la file
int defiler(file* F) {
    if (estVide(*F)) {
        printf("Erreur : la file est vide");
        exit(0);
    }
    else {
        int x = (*F).T[(*F).tete];
        (*F).tete= ((*F).tete + 1) % n;
        return x;
    }
}

// Une fonction qui initialise une file vide
file initialiserFile() {
    file F;
    F.tete = 0;
    F.fin = 0;
    return F;
}

// Une fonction qui affiche les éléments d'une file
void afficher(file* F) {
    file F1 = initialiserFile();
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
    file F = initialiserFile();
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
