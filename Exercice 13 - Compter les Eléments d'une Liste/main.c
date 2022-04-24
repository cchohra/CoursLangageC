#include <stdio.h>
#include <stdlib.h>

/*
    Ecrire un programme qui demande à l'utilisatuer de saisir les éléments d'une listes chaînées
    après chaque saisi et insertion, le programme demande à l'utilisateur s'il doit lire d'autres éléments.
    Par la suite le programme doit :
        - Calculer et afficher la taille de la liste.
        - Afficher le nombre d'occurences d'une valeur saisie par l'utilisateur.
        - Dire si les éléments de la liste sont triés (dans un ordre croissant).
*/

typedef struct noeud *liste; // Une liste est un pointeur sur un noeud (très simplement)

typedef struct noeud { // Un noeud est une enregistrement qui contient :
    int val;           // Une valeur.
    liste suiv;        // Une liste (pointeur sur un autre noeud).
} noeud;

// Insere l'élément "v" à la fin de la liste "L" et retourne le résultat
liste insererQueue(liste L, int v) {
    if (L == NULL) {
        // return insererTete(L, v);
        // C'est la même chose que l'insertion à la tête de la liste
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        return p;
    }
    else {
        // Créer le noeud
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        liste q = L; // Utiliser "q" pour parcourir la liste
        while (q->suiv != NULL) { // Jusqu'à ce que q->suiv == NULL
            q = q->suiv;
        }
        q->suiv = p; // Lier le noeud créé dans "p" à la fin de la liste
        return L;
    }
}

// Une fonction qui renvoie la taille d'une liste
int taille(liste L) {
    int t = 0; // Compteur pour les éléments de la liste
    liste p = L; // La variable "p" est utilisée pour parcourir la liste
    while (p != NULL) {
        p = p->suiv;
        t = t + 1; // Incrémentation du compteur pour chaque élément non nulle
    }
    return t;
}

// Une fonction qui renvoie la taille d'une liste (version récursive)
int tailleRec(liste L) {
    if (L == NULL) return 0; // Cas élémentaire : Une liste vide est de taille "0"
    else return 1 + tailleRec(L->suiv); // Relation de récurrence :
                                        // La taille de la liste "L" est 1 + la taille de "L->suiv"
}

// Une fonction qui renvoie le nombre d'occurences d'un élément dans une liste
int nbreOcc(liste L, int v) {
    int t = 0; // Compteur pour les éléments
    liste p = L;
    while (p != NULL) {
        if (p->val == v) { // Nous allons incrémenter "t" seulement quand "p->val == v"
            t = t + 1;
        }
        p = p->suiv;
    }
    return t;
}

// Une fonction qui renvoie le nombre d'occurences d'un élément dans une liste (version récursive)
int nbreOccRec(liste L, int v) {
    if (L == NULL) return 0; // Cas élémentaire : une liste vide ne contient aucune occurence
    else if (L->val == v) return 1 + nbreOcc(L->suiv, v); // Une occurence déjà trouvée
                                                          // plus les occurences dans le reste de la liste
    else return nbreOcc(L->suiv, v); // L'élément actuel est différent, donc il faut calculer
                                     // les occurences dans le reste de la liste
}

// Une fonction qui teste si une liste est triée
int estTrie(liste L) {
    if (L == NULL) return 1; // Si la liste est vide elle est considérée comme une liste triée
                             // ça peut changer selon l'énoncé de l'exercice ou les besoins de l'application
    else {
        liste p = L;
        if (p->suiv == NULL) return 1; // Si la liste contient un seul élément elle est considérée comme une
                                       // liste triée ça peut changer selon l'énoncé de l'exercice
                                       // ou les besoins de l'application
        else {
            liste q = p->suiv;
            int t = 1; // Si la liste est triée, "t" garde la valeur "1"
            while ((q != NULL) && (t == 1)) {
                if (p->val > q->val) t = 0; // Si on trouve un contre exemple, "t" prend "0"
                p = q;
                q = q->suiv;
            }
            return t;
        }
    }
}

// Une fonction qui teste si une liste est triée (version récursive)
int estTrieRec(liste L) {
    if (L == NULL) return 1; // Cas élémentaire 1
    else if (L->suiv == NULL) return 1; // Cas élémentaire 2
    else { // Récurrence
        liste p = L->suiv;
        if (L->val > p->val) return 0; // Cas élémentaire 3 : un contre exemple est trouvé
        else return estTrie(L->suiv); // Relation de récurrence pour tester le reste de la liste
    }
}

int main() {
    liste L = NULL;
    char reponse;
    printf("Voulez vous saisir un autre element ? (o/n) : ");
    scanf(" %c", &reponse);
    while (reponse == 'o') {
        int v;
        printf("Veuillez saisir la valeur a inserer : ");
        scanf("%d", &v);
        L = insererQueue(L, v);
        printf("Voulez vous saisir un autre element ? (o/n) : ");
        scanf(" %c", &reponse);
    }
    int t1 = taille(L);
    int t2 = tailleRec(L);
    printf("La taille de la liste est %d (version iterative)\n", t1);
    printf("La taille de la liste est %d (version recursive)\n", t2);
    int oc;
    printf("Veuillez saisir une valeur pour calculer ses occurences : ");
    scanf("%d", &oc);
    int oc1 = nbreOcc(L, oc);
    int oc2 = nbreOccRec(L, oc);
    printf("Le nombre d'occurences de la valeur %d dans la liste est %d (version iterative)\n", oc, oc1);
    printf("Le nombre d'occurences de la valeur %d dans la liste est %d (version recursive)\n", oc, oc2);
    if (estTrie(L)) printf("Les elements de la liste sont tries dans un ordre croissant (version iterative)\n");
    else printf("Les elements de la liste ne sont pas tries dans un ordre croissant (version iterative)\n");
    if (estTrieRec(L)) printf("Les elements de la liste sont tries dans un ordre croissant (version recursive)\n");
    else printf("Les elements de la liste ne sont pas tries dans un ordre croissant (version recursive)\n");
    return 0;
}
