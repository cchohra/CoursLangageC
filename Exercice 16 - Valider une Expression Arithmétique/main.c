#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nous allons �crire une fonction permettant de valider le parenth�ses, crochets
    et accolades dans une expression arithm�tique.
        - La fonction doit assurer que chaque parenthese '(', crochet '[' ou accolade '{' ouvert
          est ferm� dans le bon ordre.
        - L'expression arithm�tique est pass�e sous forme d'une cha�ne de caract�res
          contenant des valeurs, des variables, des op�rations arithm�tique et des op�rateurs
          (notre objectif est de v�rifier si les parentheses sont valides seulement
          et non pas de v�rifier que l'expression est bien form�e).
*/

#define n 150

typedef struct pile {
    char tab[n];
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
char sommet(pile P) {
    if (estVide(P)) {
        printf("Erreur dans la fonction sommet : La pile est vide");
        exit(0);
    }
    else {
        return P.tab[P.sommet];
    }
}

// Une fonction qui ajoute un �l�ment au dessus des autres �l�ment dans la pile
void empiler(pile *P, char v) {
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
char depiler(pile *P) {
    if (estVide(*P)) {
        printf("Erreur dans la fonction depiler : La pile est vide");
        exit(0);
    }
    else {
        char v = (*P).tab[(*P).sommet];
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
        char x;
        while (!estVide(P)) {
            x = depiler(&P);
            printf("%c\n", x);
            empiler(&Q, x);
        }
        while (!estVide(Q)) {
            x = depiler(&Q);
            empiler(&P, x);
        }
    }
}

void verifierParentheses(char *S) {
    pile P = initialeserPileVide();
    int i = 0;
    // Tant qu'on a pas atteint la fin d'une cha�ne de caract�res
    while (S[i]!= '\0') {
        // Empiler les parentheses, accolades et crochets ouverts
        if (S[i] == '(' || S[i] == '{' || S[i] == '[') {
            empiler(&P, S[i]);
        }
        // Si une parenth�se ferm�e est trouv�e, v�rifier la derni�re valeur empil�e
        else if (S[i] == ')') {
            if (estVide(P) || sommet(P) != '(') {
                printf("Erreur : parenthese fermee qui n'a pas ete ouverte\n");
                exit(0);
            }
            else {
                depiler(&P);
            }
        }
        // Si une accolade ferm�e est trouv�e, v�rifier la derni�re valeur empil�e
        else if (S[i] == '}') {
            if (estVide(P) || sommet(P) != '{') {
                printf("Erreur : accolade fermee qui n'a pas ete ouverte\n");
                exit(0);
            }
            else {
                depiler(&P);
            }
        }
        // Si un crochet ferm� est trouv�, v�rifier la derni�re valeur empil�e
        else if (S[i] == ']') {
            if (estVide(P) || sommet(P) != '[') {
                printf("Erreur : crochet ferme qui n'a pas ete ouvert\n");
                exit(0);
            }
            else {
                depiler(&P);
            }
        }
        i = i + 1;
    }
    // Si la pile n'est pas vide, �a signifie que des parenth�ses (ou autre) ouverts
    // n'ont pas �t� ferm�s.
    if (!estVide(P)) {
        printf("%c ouvert(e) est pas ferme(e)", sommet(P));
        exit(0);
    }
    else {
        printf("Tous les parentheses, crochets et accolades sont justes\n");
    }
}

int main() {
    char S[100];
    printf("Veuillez saisir une expression arithmetique : ");
    gets(S);
    verifierParentheses(S);
    return 0;
}
