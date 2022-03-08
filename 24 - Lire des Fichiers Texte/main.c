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
    FILE *monFichier = fopen("test.txt", "r");
    // if (monFichier != NULL) {
    if (monFichier) {
/*
        char c;
        c = fgetc(monFichier); // Lire un caractère
        printf("%c", c);
        c = fgetc(monFichier);
        printf("%c", c);
        fclose(monFichier);
*/
/*
        char s[100];
        fgets(s, 100, monFichier); // Lire une chaine
        printf("%s", s);
        fgets(s, 100, monFichier);
        printf("%s", s);
*/
/*
        int j, m, a;
        fscanf(monFichier, "%d/%d/%d", &j, &m, &a); // Lire des variables avec un format spécifique
        printf("j = %d, m = %d, a = %d\n", j, m, a);
*/
        char s[100];
        while (!feof(monFichier)) { // Tester la fin du fichier
            fgets(s, 100, monFichier);
            printf("%s\n")
        }
        close(monFichier);
    }
    else {
        printf("Impossible d'ouvrir le fichier");
    }
    return 0;
}
