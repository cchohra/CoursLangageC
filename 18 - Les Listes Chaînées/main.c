#include <stdio.h>
#include <stdlib.h>

/*
    Une collection de donn�es ayant le m�me type
        - Oui c'est la m�me d�finition que j'ai utilis�e pour les tableaux.
        - Mais l'organisation des donn�es est plus flexible.
        - Pas besoin de sp�cifier la taille de la liste � l'avance.
        - Possibilit� d'ins�rer ou supprimer les �l�ment
          � n'importe quelle position.
        - Les noeuds de la liste sont reli�s entre eux avec des pointeurs.
        - Chaque noeud est une enregistrement qui contient :
            * Les donn�es (un ou plusieurs champs).
            * Un pointeur sur le noeud suivant.
        - Une liste est d�finie par l'adresse de (un pointeur sur) son premier noeud.
        - On atteint la fin de la liste quand le pointeur (cens� �tre) sur
          l'�l�ment suivant est NULL.
*/

typedef struct noeud noeud; // Pour que le type "noeud" soit reconnu par le type liste.

typedef noeud *liste; // Une liste est un pointeur sur un noeud (tr�s simplement)

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

// Une fonction qui affiche r�cursivement les �l�ments d'une liste
// - Cas �l�mentaire : si la liste est vide (L == NULL) alors ne rien faire.
// - Cas de r�currence : sinon :
//      1. Afficher le premier �l�ment.
//      2. Appel r�cursif avec le reste des �l�ments.
void afficherRec(liste L) {
    if (L != NULL) {
        printf("%d\n", L->val); // Afficher le premier �l�ment.
        afficherRec(L->suiv); // Appel r�cursif avec le reste des �l�ments (L->suiv).
    }
}

// Une fonction qui affiche r�cursivement les �l�ments d'une liste dans l'ordre inverse
// - Cas �l�mentaire : si la liste est vide (L == NULL) alors ne rien faire.
// - Cas de r�currence : sinon :
//      1. Appel r�cursif avec le reste des �l�ments.
//      2. Lorsque tous les �l�ments suivants sont affich�s, on affiche le premier �l�ment.
void afficherRecInverse(liste L) {
    if (L != NULL) {
        afficherRec(L->suiv);
        printf("%d\n", L->val); // Afficher le premier �l�ment apr�s l'appel r�cursif cette fois.
    }
}

// Insere l'�l�ment "v" � la t�te de la liste "L" et retourne le r�sultat
liste insererTete(liste L, int v) {
    liste p = malloc(sizeof(noeud)); // Cr�er un nouveau noeud
    p->val = v;  // Donner la valeur "v" pass�e comme param�tre
    p->suiv = L; // Le suivant du nouveau noeud cr�� devient l'ancienne liste "L".
                 // La liste "p" contient maintenant tout les �l�ments de "L"
                 // avec l'�l�ment de "v" ins�r� avant.
    return p;    // Retourner "p" la nouvelle liste.
}

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

// Insertion � la (version r�cursive)
liste insererQueueRec(liste L, int v) {
    if (L == NULL) {
        // Insertion � la t�te
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        return p;
    }
    else {
        // L'insertion � la fin de la liste "L" revient � l'insertion � la fin de son "suiv"
        L->suiv = insererQueueRec(L->suiv, v);
        return L;
    }
}

// Insere l'�l�ment "v" � la position "k" de la liste "L" et retourne le r�sultat
liste insererPos(liste L, int v, int k) {
    if (k < 1) { // Si la position donn�e est inf�rieur � 1, il est impossible d'ins�rer l'�l�ment
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else if (k == 1) { // L'insertion � la premi�re position
        return insererTete(L, v);
    }
    else {
        liste p = malloc(sizeof(noeud));
        p->val = v;
        liste q = L;
        int pos = 1; // La position du pointeur "q" dans la liste
        while ((pos < k - 1) && (q != NULL)) { // Passer � la position "k - 1"
            q = q->suiv;
            pos = pos + 1;
        }
        if (q == NULL) { // Si la position d'insertion est sup�rieure � la taille de la liste + 1
                         // alors il est impossible d'ins�rer l'�l�ment
            printf("Impossible d'inserer la valeur %d \n", v);
            return L;
        }
        // Ins�rer le neoud r�f�renc� par "p" entre les �l�ment aux positions
        // "k - 1" et "k" ("k + 1" apr�s insertion)
        p->suiv = q->suiv;
        q->suiv = p;
        return L;
    }
}

// Insertion � la position "k" (version r�cursive)
liste insererPosRec(liste L, int v, int k) {
    if (k < 1) {
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else if (k == 1) {
        return insererTete(L, v);
    }
    else if (L == NULL) { // Si on arrive r�cursivement ou directement � une situation ou
                          // il faut ins�rer un �l�ment � une position sup�rieure � 1
                          // dans une liste vide, alors il est impossible d'ins�rer cet �l�ment.
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else {
        // Position "k" dans "L" -> position "k - 1" dans "L->suiv".
        L->suiv = insererPosRec(L->suiv, v, k - 1);
        return L;
    }
}

// Supprimer le premier �l�ment de la liste
liste supprimerTete(liste L) {
    if (L == NULL) { // Si la liste est vide, il n'y a rien � supprimer
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L; // Le pointeur "p" est utilis� pour lib�rer le premier �l�ment de la liste
        L = L->suiv; // La liste passe au deuxi�me �l�ment
        free(p);     // Le premier �l�ment est lib�r�
        return L;
    }
}

// Supprimer le dernier �l�ment de la liste
liste supprimerQueue(liste L) {
    if (L == NULL) {
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L;
        // Si la liste est vide, on fait la m�me chose que la suppression au d�but
        if (p->suiv == NULL) {
            L = NULL;
            free(p);
            return L;
        }
        // Sinon, nous allons parcourir la liste jusqu'� la fin
        else {
            liste q = p->suiv; // Le pointeur "q" doit atteindre le dernier �l�ment de la liste
            while (q->suiv != NULL) { // Tant qu'on a pas atteint le dernier �l�ment
                p = q;                // On fait avancer "p"
                q = q->suiv;          // et "q"
            }
            p->suiv = NULL; // Le suivant de l'avant dernier �l�ment devient "NULL"
            free(q);        // Le dernier �l�ment est lib�r�
            return L;
        }
    }
}

// Supprimer le dernier �l�ment de la liste (Version R�cursive)
liste supprimerQueueRec(liste L) {
    if (L == NULL) { // Cas �l�mentaire 1 : la liste est vide
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else if (L->suiv == NULL) { // Cas �l�mentaire 2 : la liste contient un seul �l�ment
        liste p = L;
        free(p);
        L = NULL;
        return L;
    }
    else { // Relation de r�currence
        // La suppression de la fin de la liste "L" revient � la suppression de la fin de son suivant
        L->suiv = supprimerQueueRec(L->suiv);
        return L;
    }
}

// Supprimer l'�l�ment � la position "k"
liste supprimerPos(liste L, int k) {
    if (k < 1) { // Si la position est inf�rieur � "1" il est impossible de supprimer l'�l�ment
        printf("Impossible de supprimer de la position %d \n", k);
        return L;
    }
    else if (L == NULL) { // Si la liste est vide alors rien � supprimer
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L;
        if (k == 1) { // Si nous voulons supprimer le premier �l�ment
            L = L->suiv;
            free(p);
            return L;
        }
        else {
            liste q = p->suiv; // Placer "q" sur la deuxi�me position
            int pos = 2;       // Garder la position de "q" dans cette variable
            while ((pos < k) && (q != NULL)) { // Passer � l'�l�ment suivant jusqu'� ce que
                                               // On atteint la position de l'�l�ment � supprimer
                                               // Ou "q" est "NULL"
                p = q;
                q = q->suiv;
                pos = pos + 1;                 // Incr�menter la position � chaque it�ration
            }
            if (q != NULL) {                   // Si "q" n'est pas "NULL", supprimer le neoud
                                               // r�f�renc� par "q"
                p->suiv = q->suiv;             // R�organiser l'enchainement de la liste
                free(q);
                return L;
            }
            else { // Si "q" est "NULL" alors la position de l'�l�ment � supprimer est sup�rieure
                   // � la taille de la liste
                printf("Impossible de supprimer l'element a cette position\n");
                return L;
            }
        }
    }
}

// Supprimer l'�l�ment � la position "k" (Version R�cursive)
liste supprimerPosRec(liste L, int k) {
    if (k < 1) { // Impossible de supprimer si "k < 1"
        printf("Impossible de supprimer de la position %d \n", k);
        return L;
    }
    else if (L == NULL) { // Cas �l�mentaire : Si la liste est vide, rien � supprimer
        printf("Impossible de supprimer l'element a cette position\n");
        return L;
    }
    else if (k == 1) { // Cas �l�mentaire 2 : Si "k == 1" alors supprimer la t�te
        return supprimerTete(L);
    }
    else { // Relation de recurrence : Suppression � la position "k" dans la liste "L"
           // revient � ins�rer � la posirion "k - 1" dans "L->suiv"
        L->suiv = supprimerPosRec(L->suiv, k - 1);
        return L;
    }
}

int main() {
    liste L = NULL;
    L = insererTete(L, 5);      // 5
    L = insererTete(L, 1);      // 1 5
    L = insererQueueRec(L, 2);  // 1 5 2
    L = insererTete(L, 3);      // 3 1 5 2
    L = insererQueueRec(L, 4);  // 3 1 5 2 4
    L = insererPosRec(L, 6, 3); // 3 1 6 5 2 4
    L = insererPosRec(L, 7, 1); // 7 3 1 6 5 2 4
    L = insererPosRec(L, 8, 8); // 7 3 1 6 5 2 4 8
    L = supprimerTete(L);       // 3 1 6 5 2 4 8
    L = supprimerQueueRec(L);   // 3 1 6 5 2 4
    L = supprimerPosRec(L, 3);  // 3 1 5 2 4
    L = supprimerPosRec(L, 1);  // 1 5 2 4
    L = supprimerPosRec(L, 4);  // 1 5 2
    afficher(L);
    return 0;
}
