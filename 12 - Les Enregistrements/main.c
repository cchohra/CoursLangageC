#include <stdio.h>
#include <stdlib.h>

/*
    - Type de donn�es d�fini par le programmeur.
    - Permet de regrouper un nombre de champs dans une seule variable.
    - Les champs d'une enregistrement peuvent avoir des types diff�rents.
    - Pour d�clarer une enregistrement, la syntaxe suivante est utilis�e :
        struct nomType {
            type1 champs1;
            type2 champs2;
            ...
            type3 champs3;
        }
    - Pour d�clarer une variable de type enregistrement, nous �crivons :
        struct nomType nomVar;
    - Il est possible d'utiliser le mot cl� "typedef" � la d�claration
      pour �viter de r�p�ter le met "struct" � chaque d�claration.
        typedef struct nomType nouveauNom;
        nouveauNom X;

    Exemple :
    Nous allons d�clarer une enregistrement pour structurer les donn�es
    des employ�s d'une entreprise.
    Un employ� est caract�ris� par : nom, pr�nom, identifiant, salaire, poste ... etc.
*/

// D�claration d'une enregistrement pour le type "employ�"
typedef struct employe {
    char nom[50], prenom[50], poste[30];
    int identifiant;
    float salaire;
} employe;

int main() {
    employe e; // D�claration d'une variable de type employ�

    // Lire les champs qui compose l'enregistrement un par un
    printf("Veuillez saisir les informations de l'employe\n");
    printf("Le nom : ");
    scanf(" %s", &e.nom);
    printf("Le prenom : ");
    scanf(" %s", &e.prenom);
    printf("L'identifiant national : ");
    scanf("%d", &e.identifiant);
    printf("Le salaire : ");
    scanf("%f", &e.salaire);
    printf("Le poste : ");
    scanf(" %s", &e.poste);

    // Afficher les informations de l'employ�
    printf("L'employ� %s %s, ayant l'identifiant %d occupe le poste %s et touche %g DA par mois",
           e.nom, e.prenom, e.identifiant, e.poste, e.salaire);

    return 0;
}
