#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Le but de cet exercice est de programmer un petit editeur de texte.
        - Le programme doit lire plusieurs lignes (les enregistrer dans un tableau
          ou une liste).
        - Si l'utilisateur écrit "SAVE" le programme demande le nom de fichier
          sur lequel il faut enregistrer.
*/

int main() {
    char lignes[100][100];
    for (int i = 0; i < 100; i++) {
        gets(lignes[i]); // Lire chaque ligne
        if (!strcmp(lignes[i], "SAVE")) break; // Terminer si l'utilisateur a saisi "SAVE"
    }
    char nomFichier[50];
    printf("Veuillez saisir le nom de fichier a enregistrer : ");
    gets(nomFichier); // Lire le nom du fichier
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier) {
        for (int i = 0; i < 100; i++) {
            if (strcmp(lignes[i], "SAVE") == 0) break;
            else {
                fprintf(fichier, "%s\n", lignes[i]); // Enregistrer toutes les lignes
            }
        }
        printf("Le fichier a bien ete enregistre");
    }
    else {
        printf("Impossible d'ouvrir le fichier %s pour ecriture", nomFichier);
    }
    return 0;
}
