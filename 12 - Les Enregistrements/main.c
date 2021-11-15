#include <stdio.h>
#include <stdlib.h>

/*
    - Type de données défini par le programmeur.
    - Permet de regrouper un nombre de champs dans une seule variable.
    - Les champs d'une enregistrement peuvent avoir des types différents.
    - Pour déclarer une enregistrement, la syntaxe suivante est utilisée :
        struct nomType {
            type1 champs1;
            type2 champs2;
            ...
            type3 champs3;
        }
    - Pour déclarer une variable de type enregistrement, nous écrivons :
        struct nomType nomVar;
    - Il est possible d'utiliser le mot clé "typedef" à la déclaration
      pour éviter de répéter le met "struct" à chaque déclaration.
        typedef struct nomType nouveauNom;
        nouveauNom X;

    Exemple :
    Nous allons déclarer une enregistrement pour structurer les données
    des employés d'une entreprise.
    Un employé est caractérisé par : nom, prénom, identifiant, salaire, poste ... etc.
*/

// Déclaration d'une enregistrement pour le type "employé"
typedef struct employe {
    char nom[50], prenom[50], poste[30];
    int identifiant;
    float salaire;
} employe;

int main() {
    employe e; // Déclaration d'une variable de type employé

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

    // Afficher les informations de l'employé
    printf("L'employé %s %s, ayant l'identifiant %d occupe le poste %s et touche %g DA par mois",
           e.nom, e.prenom, e.identifiant, e.poste, e.salaire);

    return 0;
}
