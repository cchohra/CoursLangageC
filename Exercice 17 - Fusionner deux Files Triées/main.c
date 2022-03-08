#include <stdio.h>
#include <stdlib.h>

/*
    Le but de ce projet et d'écrire une fonction permettant de fusionner
    deux files triées.
        - Demander à l'utilisateur de saisir les valeurs à insérer dans chaque file.
        - Fusionner les files en utilisant la fonction déclarée.
        - Afficher le résultat.
*/

#define n 10

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

// Une fonction qui permet de fusionner deux files triées
file fusionnerTriees(file F1, file F2) {
    file F = initialiserFile();
    while (!estVide(F1) && !estVide(F2)) {
        if (tete(F1) < tete(F2)) {
            int x = defiler(&F1);
            enfiler(&F, x);
        }
        else {
            int x = defiler(&F2);
            enfiler(&F, x);
        }
    }
    if (estVide(F1)) {
        while (!estVide(F2)) {
            int x = defiler(&F2);
            enfiler(&F, x);
        }
    }
    if (estVide(F2)) {
        while (!estVide(F1)) {
            int x = defiler(&F1);
            enfiler(&F, x);
        }
    }
    return F;
}

int main()
{
    file F1 = initialiserFile();
    file F2 = initialiserFile();
    int x;
    char repeter = 'o';
    printf("Veuillez saisir les elements de la file F1\n");
    while (repeter == 'o') {
        printf("Veuillez saisir un element : ");
        scanf("%d", &x);
        enfiler(&F1, x);
        printf("Ajouter une autre valeur (o/n) ? ");
        scanf(" %c", &repeter);
    }
    repeter = 'o';
    printf("Veuillez saisir les elements de la file F2\n");
    while (repeter == 'o') {
        printf("Veuillez saisir un element : ");
        scanf("%d", &x);
        enfiler(&F2, x);
        printf("Ajouter une autre valeur (o/n) ? ");
        scanf(" %c", &repeter);
    }
    file F = fusionnerTriees(F1, F2);
    printf("Le resultat de fusion est : \n");
    afficher(&F);
    return 0;
}
