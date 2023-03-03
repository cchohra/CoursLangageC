#include <stdio.h>
#include <stdlib.h>

/*
    Une collection de données ayant le même type
        - Oui c'est la même définition que j'ai utilisée pour les tableaux.
        - Mais l'organisation des données est plus flexible.
        - Pas besoin de spécifier la taille de la liste à l'avance.
        - Possibilité d'insérer ou supprimer les élément
          à n'importe quelle position.
        - Les noeuds de la liste sont reliés entre eux avec des pointeurs.
        - Chaque noeud est une enregistrement qui contient :
            * Les données (un ou plusieurs champs).
            * Un pointeur sur le noeud suivant.
        - Une liste est définie par l'adresse de (un pointeur sur) son premier noeud.
        - On atteint la fin de la liste quand le pointeur (censé être) sur
          l'élément suivant est NULL.
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

// Une fonction qui affiche récursivement les éléments d'une liste
// - Cas élémentaire : si la liste est vide (L == NULL) alors ne rien faire.
// - Cas de récurrence : sinon :
//      1. Afficher le premier élément.
//      2. Appel récursif avec le reste des éléments.
void afficherRec(liste L) {
    if (L != NULL) {
        printf("%d\n", L->val); // Afficher le premier élément.
        afficherRec(L->suiv); // Appel récursif avec le reste des éléments (L->suiv).
    }
}

// Une fonction qui affiche récursivement les éléments d'une liste dans l'ordre inverse
// - Cas élémentaire : si la liste est vide (L == NULL) alors ne rien faire.
// - Cas de récurrence : sinon :
//      1. Appel récursif avec le reste des éléments.
//      2. Lorsque tous les éléments suivants sont affichés, on affiche le premier élément.
void afficherRecInverse(liste L) {
    if (L != NULL) {
        afficherRec(L->suiv);
        printf("%d\n", L->val); // Afficher le premier élément après l'appel récursif cette fois.
    }
}

// Insere l'élément "v" à la tête de la liste "L" et retourne le résultat
liste insererTete(liste L, int v) {
    liste p = malloc(sizeof(noeud)); // Créer un nouveau noeud
    p->val = v;  // Donner la valeur "v" passée comme paramètre
    p->suiv = L; // Le suivant du nouveau noeud créé devient l'ancienne liste "L".
                 // La liste "p" contient maintenant tout les éléments de "L"
                 // avec l'élément de "v" inséré avant.
    return p;    // Retourner "p" la nouvelle liste.
}

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

// Insertion à la (version récursive)
liste insererQueueRec(liste L, int v) {
    if (L == NULL) {
        // Insertion à la tête
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        return p;
    }
    else {
        // L'insertion à la fin de la liste "L" revient à l'insertion à la fin de son "suiv"
        L->suiv = insererQueueRec(L->suiv, v);
        return L;
    }
}

// Insere l'élément "v" à la position "k" de la liste "L" et retourne le résultat
liste insererPos(liste L, int v, int k) {
    if (k < 1) { // Si la position donnée est inférieur à 1, il est impossible d'insérer l'élément
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else if (k == 1) { // L'insertion à la première position
        return insererTete(L, v);
    }
	else {
		liste q = L;
		int pos = 1;
		while ((pos < k - 1) && (q != NULL)) {
			q = q->suivant;
			pos = pos + 1;
		}
		if (q == NULL) {
            printf("Impossible d'inserer la valeur %d \n", v);
			return L;
		}
		liste p = malloc(sizeof(noeud));
		p->valeur = v;
		p->suivant = q->suivant;
		q->suivant = p;
		return L;
	}
}

// Insertion à la position "k" (version récursive)
liste insererPosRec(liste L, int v, int k) {
    if (k < 1) {
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else if (k == 1) {
        return insererTete(L, v);
    }
    else if (L == NULL) { // Si on arrive récursivement ou directement à une situation ou
                          // il faut insérer un élément à une position supérieure à 1
                          // dans une liste vide, alors il est impossible d'insérer cet élément.
        printf("Impossible d'inserer la valeur %d \n", v);
        return L;
    }
    else {
        // Position "k" dans "L" -> position "k - 1" dans "L->suiv".
        L->suiv = insererPosRec(L->suiv, v, k - 1);
        return L;
    }
}

// Supprimer le premier élément de la liste
liste supprimerTete(liste L) {
    if (L == NULL) { // Si la liste est vide, il n'y a rien à supprimer
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L; // Le pointeur "p" est utilisé pour libérer le premier élément de la liste
        L = L->suiv; // La liste passe au deuxième élément
        free(p);     // Le premier élément est libéré
        return L;
    }
}

// Supprimer le dernier élément de la liste
liste supprimerQueue(liste L) {
    if (L == NULL) {
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L;
        // Si la liste est vide, on fait la même chose que la suppression au début
        if (p->suiv == NULL) {
            L = NULL;
            free(p);
            return L;
        }
        // Sinon, nous allons parcourir la liste jusqu'ç la fin
        else {
            liste q = p->suiv; // Le pointeur "q" doit atteindre le dernier élément de la liste
            while (q->suiv != NULL) { // Tant qu'on a pas atteint le dernier élément
                p = q;                // On fait avancer "p"
                q = q->suiv;          // et "q"
            }
            p->suiv = NULL; // Le suivant de l'avant dernier élément devient "NULL"
            free(q);        // Le dernier élément est libéré
            return L;
        }
    }
}

// Supprimer le dernier élément de la liste (Version Récursive)
liste supprimerQueueRec(liste L) {
    if (L == NULL) { // Cas élémentaire 1 : la liste est vide
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else if (L->suiv == NULL) { // Cas élémentaire 2 : la liste contient un seul élément
        liste p = L;
        free(p);
        L = NULL;
        return L;
    }
    else { // Relation de récurrence
        // La suppression de la fin de la liste "L" revient à la suppression de la fin de son suivant
        L->suiv = supprimerQueueRec(L->suiv);
        return L;
    }
}

// Supprimer l'élément à la position "k"
liste supprimerPos(liste L, int k) {
    if (k < 1) { // Si la position est inférieur à "1" il est impossible de supprimer l'élément
        printf("Impossible de supprimer de la position %d \n", k);
        return L;
    }
    else if (L == NULL) { // Si la liste est vide alors rien à supprimer
        printf("La liste est vide, rien a supprimer\n");
        return L;
    }
    else {
        liste p = L;
        if (k == 1) { // Si nous voulons supprimer le premier élément
            L = L->suiv;
            free(p);
            return L;
        }
        else {
            liste q = p->suiv; // Placer "q" sur la deuxième position
            int pos = 2;       // Garder la position de "q" dans cette variable
            while ((pos < k) && (q != NULL)) { // Passer à l'élément suivant jusqu'à ce que
                                               // On atteint la position de l'élément à supprimer
                                               // Ou "q" est "NULL"
                p = q;
                q = q->suiv;
                pos = pos + 1;                 // Incrémenter la position à chaque itération
            }
            if (q != NULL) {                   // Si "q" n'est pas "NULL", supprimer le neoud
                                               // référencé par "q"
                p->suiv = q->suiv;             // Réorganiser l'enchainement de la liste
                free(q);
                return L;
            }
            else { // Si "q" est "NULL" alors la position de l'élément à supprimer est supérieure
                   // à la taille de la liste
                printf("Impossible de supprimer l'element a cette position\n");
                return L;
            }
        }
    }
}

// Supprimer l'élément à la position "k" (Version Récursive)
liste supprimerPosRec(liste L, int k) {
    if (k < 1) { // Impossible de supprimer si "k < 1"
        printf("Impossible de supprimer de la position %d \n", k);
        return L;
    }
    else if (L == NULL) { // Cas élémentaire : Si la liste est vide, rien à supprimer
        printf("Impossible de supprimer l'element a cette position\n");
        return L;
    }
    else if (k == 1) { // Cas élémentaire 2 : Si "k == 1" alors supprimer la tête
        return supprimerTete(L);
    }
    else { // Relation de recurrence : Suppression à la position "k" dans la liste "L"
           // revient à insérer à la posirion "k - 1" dans "L->suiv"
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
