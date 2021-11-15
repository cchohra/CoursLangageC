#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nous allons écrire un programme qui fait la gestion d'un parc automobile
    Chaque voiture est caractérisée par :
        - Une marque.
        - Un modèle.
        - Une couleur.
        - Un matricule.
        - Nombre de places.
        - Puissance fiscale.
    Nous supposons que le parc contient n (=5) voitures. Le programme
    doit permettre la saisi des n voitures, puis établir la liste
    des voitures pour une couleur donnée par l'utilisateur.
*/

// Taille du tableau
#define n 5

// Enregistrement pour déclarer le type voiture
typedef struct voiture {
    char marque[50], modele[50], couleur[20], matricule[20];
    int places, puissance;
} voiture;

int main()
{
    voiture voitures[n]; // Déclaration d'un tableau de voitures
    printf("Veuillez saisir les informations des voitures dans le parc\n");
    for (int i = 0; i < n; i++) { // Une boucle pour lire les informations de chaque voiture
        printf("La voiture %d\n", i + 1);
        printf("La marque : ");
        gets(voitures[i].marque); // Gets est utilisée pour lire des chaines de caractères
        printf("Le modele : ");
        gets(voitures[i].modele);
        printf("La couleur : ");
        gets(voitures[i].couleur);
        printf("La matricule : ");
        gets(voitures[i].matricule);
        printf("La nombre de places : ");
        scanf("%d", &voitures[i].places);
        printf("La puissance fiscale : ");
        scanf("%d", &voitures[i].puissance);
        getchar();  // A utiliser pour éviter les problème de lecture d'une chaine de caractere apres
                    // L'appel à la fonction "scanf"
    }
    int existe = 0; // Utilser pour tester si la couleur recherchée existe (supposée inexistante par défaut)
    char couleur[20];
    printf("Veuillez saisir une couleur : ");
    gets(couleur);
    printf("Affichage des voitures ayant la couleur %s\n", couleur);
    for (int i = 0; i < n; i++) { // Une boucle pour tester toutes les voitures
        // Si on trouve la couleur qu'on cherche
        if (strcmp(voitures[i].couleur, couleur) == 0) {
            existe = 1; // La couleur existe, donc la variable prend la valeur "1"
            printf("Marque : %s\n", voitures[i].marque);
            printf("Modele : %s\n", voitures[i].modele);
            printf("Matricule : %s\n", voitures[i].matricule);
            printf("Nombre de places : %d\n", voitures[i].places);
            printf("Puissance fiscale : %d\n", voitures[i].puissance);
            printf("\n");
        }
    }
    if (!existe) { // Si la couleur n'existe pas, alors afficher un petit message d'explication
        printf("Nous n'avons trouvé aucune voiture de couleur : %s\n", couleur);
    }
    return 0;
}
