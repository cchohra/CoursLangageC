#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Ecrire une fonction qui permet de vérifier si un mot est palindrome.
    Une mot palindrome est un mot qui peut se lire de gauche à droite ou de droite à gauche.
        - Ecrire la fonction "estPalindrome"
            * Prend comme entrée une chaine de caracteres.
            * Retourne 1 si le mot donné est palindrome et 0 sinon.
            * La fonction doit utiliser une pile est une file.
        - Ecrire un programme principal
            * Qui lit une chaine saisie par l'utilisateur.
            * Affiche si le mot saisi est palindrome ou pas.

        - Exemple de mots palindromes : non, radar, coloc, elle, tot, kayak
*/

#define n 50

typedef struct file {
    char T[n];
    int tete;
    int fin;
} file;

typedef struct pile {
    char T[n];
    int sommet;
} pile;

// Une fonction qui initialise une file vide
file initialiserFile() {
    file F;
    F.tete = 0;
    F.fin = 0;
    return F;
}

// Une fonction qui teste si la file est vide
int fileVide(file F) {
    return F.tete == F.fin;
}

// Une fonction qui teste si la file est pleine
int filePleine(file F) {
    return F.tete == (F.fin + 1) % n;
}

// Une fonction qui retourne l'element à la tête d'une file
char tete(file F) {
    if (fileVide(F)) {
        printf("Erreur : la file est vide");
        exit(0);
    }
    else {
        return F.T[F.tete];
    }
}

// Une fonction qui ajoute un élément à la fin d'une file
void enfiler(file *F, char v) {
    if (filePleine(*F)) {
        printf("Erreur : impossible d'enfiler la file est pleine");
        exit(0);
    }
    else {
        (*F).T[((*F).fin)] = v;
        (*F).fin = ((*F).fin + 1) % n;
    }
}

// Une fonction qui retourne la tête et la supprime de la file
char defiler(file* F) {
    if (fileVide(*F)) {
        printf("Erreur : la file est vide");
        exit(0);
    }
    else {
        char x = (*F).T[(*F).tete];
        (*F).tete= ((*F).tete + 1) % n;
        return x;
    }
}

// Une fonction qui initialise une pile vide
pile initialeserPileVide() {
    pile P;
    P.sommet = -1;
    return P;
}

// Une fonction qui teste si la pile est vide
int pileVide(pile P) {
    return (P.sommet == -1);
}

// Une fonction qui teste si la pile est pleine
int pilePleine(pile P) {
    return (P.sommet == n-1);
}

// Une fonction qui retourne le sommet de la pile
char sommet(pile P) {
    if (pileVide(P)) {
        printf("Erreur dans la fonction sommet : La pile est vide");
        exit(0);
    }
    else {
        return P.T[P.sommet];
    }
}

// Une fonction qui ajoute un élément au dessus des autres élément dans la pile
void empiler(pile *P, char v) {
    if (pilePleine(*P)) {
        printf("Erreur dans la fonction empiler : La pile est pleine, impossible d'empiler");
        exit(0);
    }
    else {
        (*P).sommet = (*P).sommet + 1;
        (*P).T[(*P).sommet] = v;
    }
}

// Une fonction qui retourne le sommet et le supprime de la pile
char depiler(pile *P) {
    if (pileVide(*P)) {
        printf("Erreur dans la fonction depiler : La pile est vide");
        exit(0);
    }
    else {
        char v = (*P).T[(*P).sommet];
        (*P).sommet = (*P).sommet - 1;
        return v;
    }
}

// une fonction qui teste si un mot donné est palindrome
int palindrome(char* S) {
    pile P = initialeserPileVide();
    file F = initialiserFile();
    int i = 0;
    while (S[i] != '\0') {
        empiler(&P, S[i]);
        enfiler(&F, S[i]);
        i = i + 1;
    }
    char c1, c2;
    while (!pileVide(P) && !fileVide(F)) {
        c1 = depiler(&P);
        c2 = defiler(&F);
        if (c1 != c2) return 0;
    }
    return 1;
}

int main()
{
    char S[50];
    printf("Veuillez saisir un mot : ");
    gets(S); // scanf("%s", &S);
    if (palindrome(S)) {
        printf("Le mot %s est palindrome\n", S);
    }
    else {
        printf("Le mot %s n'est pas palindrome\n", S);
    }
    return 0;
}
