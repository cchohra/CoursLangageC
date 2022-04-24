#include <stdio.h>
#include <stdlib.h>

/*
    Ecrire un programme qui demande � l'utilisatuer de saisir les �l�ments d'une listes cha�n�es
    apr�s chaque saisi et insertion, le programme demande � l'utilisateur s'il doit lire d'autres �l�ments.
    Par la suite le programme doit :
        - Calculer et afficher la taille de la liste.
        - Afficher le nombre d'occurences d'une valeur saisie par l'utilisateur.
        - Dire si les �l�ments de la liste sont tri�s (dans un ordre croissant).
*/

typedef struct noeud *liste; // Une liste est un pointeur sur un noeud (tr�s simplement)

typedef struct noeud { // Un noeud est une enregistrement qui contient :
    int val;           // Une valeur.
    liste suiv;        // Une liste (pointeur sur un autre noeud).
} noeud;

// Insere l'�l�ment "v" � la fin de la liste "L" et retourne le r�sultat
liste insererQueue(liste L, int v) {
    if (L == NULL) {
        // return insererTete(L, v);
        // C'est la m�me chose que l'insertion � la t�te de la liste
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        return p;
    }
    else {
        // Cr�er le noeud
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        liste q = L; // Utiliser "q" pour parcourir la liste
        while (q->suiv != NULL) { // Jusqu'� ce que q->suiv == NULL
            q = q->suiv;
        }
        q->suiv = p; // Lier le noeud cr�� dans "p" � la fin de la liste
        return L;
    }
}

// Une fonction qui renvoie la taille d'une liste
int taille(liste L) {
    int t = 0; // Compteur pour les �l�ments de la liste
    liste p = L; // La variable "p" est utilis�e pour parcourir la liste
    while (p != NULL) {
        p = p->suiv;
        t = t + 1; // Incr�mentation du compteur pour chaque �l�ment non nulle
    }
    return t;
}

// Une fonction qui renvoie la taille d'une liste (version r�cursive)
int tailleRec(liste L) {
    if (L == NULL) return 0; // Cas �l�mentaire : Une liste vide est de taille "0"
    else return 1 + tailleRec(L->suiv); // Relation de r�currence :
                                        // La taille de la liste "L" est 1 + la taille de "L->suiv"
}

// Une fonction qui renvoie le nombre d'occurences d'un �l�ment dans une liste
int nbreOcc(liste L, int v) {
    int t = 0; // Compteur pour les �l�ments
    liste p = L;
    while (p != NULL) {
        if (p->val == v) { // Nous allons incr�menter "t" seulement quand "p->val == v"
            t = t + 1;
        }
        p = p->suiv;
    }
    return t;
}

// Une fonction qui renvoie le nombre d'occurences d'un �l�ment dans une liste (version r�cursive)
int nbreOccRec(liste L, int v) {
    if (L == NULL) return 0; // Cas �l�mentaire : une liste vide ne contient aucune occurence
    else if (L->val == v) return 1 + nbreOcc(L->suiv, v); // Une occurence d�j� trouv�e
                                                          // plus les occurences dans le reste de la liste
    else return nbreOcc(L->suiv, v); // L'�l�ment actuel est diff�rent, donc il faut calculer
                                     // les occurences dans le reste de la liste
}

// Une fonction qui teste si une liste est tri�e
int estTrie(liste L) {
    if (L == NULL) return 1; // Si la liste est vide elle est consid�r�e comme une liste tri�e
                             // �a peut changer selon l'�nonc� de l'exercice ou les besoins de l'application
    else {
        liste p = L;
        if (p->suiv == NULL) return 1; // Si la liste contient un seul �l�ment elle est consid�r�e comme une
                                       // liste tri�e �a peut changer selon l'�nonc� de l'exercice
                                       // ou les besoins de l'application
        else {
            liste q = p->suiv;
            int t = 1; // Si la liste est tri�e, "t" garde la valeur "1"
            while ((q != NULL) && (t == 1)) {
                if (p->val > q->val) t = 0; // Si on trouve un contre exemple, "t" prend "0"
                p = q;
                q = q->suiv;
            }
            return t;
        }
    }
}

// Une fonction qui teste si une liste est tri�e (version r�cursive)
int estTrieRec(liste L) {
    if (L == NULL) return 1; // Cas �l�mentaire 1
    else if (L->suiv == NULL) return 1; // Cas �l�mentaire 2
    else { // R�currence
        liste p = L->suiv;
        if (L->val > p->val) return 0; // Cas �l�mentaire 3 : un contre exemple est trouv�
        else return estTrie(L->suiv); // Relation de r�currence pour tester le reste de la liste
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
