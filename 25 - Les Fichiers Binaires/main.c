#include <stdio.h>
#include <stdlib.h>

/*
    Manipulation des fichiers binaires.
        - Ouvrir le fichier : fopen.
            - FILE* monFichier = open("nomdeficher", "rb")
                        - ouvrir le fichier pour lecture (le fichier doit exister).
            - FILE* monFichier = open("nomdeficher", "wb")
                        - ouvrir le fichier pour ecriture (le contenu du fichier est supprimé).
            - FILE* monFichier = open("nomdeficher", "ab")
                        - ouvrir le fichier pour ecriture sans supprimer son contenu.
        - Ecrire dans un fichier binaire : fwrite
            - fwrite(adr, taille, elements, fichier);
        - Lire d'un fichier binaire : fread.
            - fread(adr, taille, elements, fichier);
        - fclose : fermer le fichier.
*/

int main()
{
    /*
    FILE *fichierBinaire = fopen("test.dat", "wb"); // Ouvrir un fichier binaire pour écriture
    if (fichierBinaire) {
        double x[5] = {1, 2, 3, 4, 5};
        fwrite(x, sizeof(double), 5, fichierBinaire); // Ecrire 5 "doubles" dans un fichier binaire
        fclose(fichierBinaire);
    }
    else {
        printf("Impossible d'ouvrir le fichier");
    }
    return 0;
    */
    FILE *fichierBinaire = fopen("test.dat", "rb"); // Ouvrir un fichier binaire pour lecture
    if (fichierBinaire) {
        double y[5] = {0};
        fread(y, sizeof(double), 4, fichierBinaire); // Lire 4 "doubles" d'un fichier binaire
        for (int i = 0; i < 5; i++) {
            printf("%g\n", y[i]);
        }
    }
    else {
        printf("Impossible d'ouvrir le fichier");
    }
}
