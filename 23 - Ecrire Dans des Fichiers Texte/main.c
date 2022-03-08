#include <stdio.h>
#include <stdlib.h>

/*
    Manipulation des fichiers texte.
        - Ouvrir le fichier : fopen.
            - FILE* monFichier = fopen("cheminduficher", "r")
                        - ouvrir le fichier pour lecture (le fichier doit exister).
            - FILE* monFichier = fopen("cheminduficher", "w")
                        - ouvrir le fichier pour ecriture (le contenu du fichier est supprimé).
            - FILE* monFichier = fopen("cheminduficher", "a")
                        - ouvrir le fichier pour ecriture sans supprimer son contenu.
        - Ecrire dans un fichier texte : fputc, fputs, fprintf.
            - fputc(c, monFichier) : ecrire un caractère dans un fichier.
            - fputs(s, monFichier) : ecrire une chaine (tableau) de caractères dans un fichier.
            - fprintf(monFichier, f, var1, var2 ... etc)
                        - Similaire à la fonction "printf"
        - Lire d'un fichier texte : fgetc, fgets, fscanf.
            - fgetc(monFichier) : lire un caractère d'un fichier texte.
            - fgets(s, nb, monFichier) : lire une chaine de taille "nb" d'un fichier texte.
                        (ne pas dépasser la ligne)
            - fscanf(monFichier, f, &var1, &var2 ... etc)
                        - Similaire à la fonction "scanf"
        - Fermer le fichier : fclose.
*/

int main()
{
    FILE *monFichier = fopen("test2.txt", "a"); // Ouvrir le fichier
//    if (monFichier != NULL) {
    if (monFichier) { // Tester que le fichier a bien été ouvert
        int x = 5;
        float y = 2.5;
        fputc('a', monFichier); // Ecrire un seul caractère
        fputc('b', monFichier);
        fputs("Hello world!\n", monFichier); // Ecrire une chaine
        fputs("Bonjour3\n", monFichier);

        // Ecrire une chaine formatée
        fprintf(monFichier, "la valeur de x est %d, la valeur de y est %f\n", x, y);
        fclose(monFichier); // Fermer le fichier
    }
    else {
        printf("Erreur, impossible d'ouvrir le ficher");
    }
    return 0;
}
