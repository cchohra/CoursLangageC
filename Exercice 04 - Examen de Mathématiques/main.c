#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
L'objectif est de simuler un examen de mathématiques automatisé.
Le programme génère aléatoirement dix opérations (*, -, +),
puis l'utilisateur répond à chacune des opérations.
Chaque réponse est notée sur deux points :
    - Si la réponse est juste on obtient 2 / 2.
    - Si la réponse est proche du bon résultat (différence inférieure à 2)
      on obtient 1 / 2.
    - Sinon la réponse est ratée et on obtient 0 / 2.
La note finale (sur 20) est donnée par la somme des notes obtenues pour chaque réponse.
A la fin le programme doit afficher une note, et donner une mention à l'utilisateur :
    - Insuffisant : pour note finale < 10.
    - Passable : 10 <= note finale < 12.
    - Assez Bien : 12 <= note finale < 14.
    - Bien : 14 <= note finale < 16.
    - Très Bien : 16 <= note finale < 18.
    - Excélent : note finale >= 18.
*/

int main()
{
    srand(time(NULL)); // Initialiser la fonction rand()
    int S = 0;         // Initialiser la note finale par 0
    for (int i = 1; i <= 10; i++) {
        int resultat, reponse;
        int a = (rand() % 40) - 20; // a est un nombre aléatoire entre -20 et 20
        int b = (rand() % 40) - 20; // b est un nombre aléatoire entre -20 et 20
        int op = rand() % 3;        // Choisir une opération aléatoire (*, -, +)
        switch (op) { // Tester les opérations possibles
        case 0 : // 0 pour la multiplication
            resultat = a * b; // Calculer le bon résultat
            printf("(%d) * (%d) = ", a, b); // Afficher l'opération à effectuer
            break;
        case 1 : // 1 pour la soustraction
            resultat = a - b; // Calculer le bon résultat
            printf("(%d) - (%d) = ", a, b); // Afficher l'opération à effectuer
            break;
        case 2 : // 2 pour l'addition
            resultat = a + b; // Calculer le bon résultat
            printf("(%d) + (%d) = ", a, b); // Afficher l'opération à effectuer
            break;
        }
        scanf("%d", &reponse); // Lire la réponse de l'utilisateur
        if (reponse == resultat) { // C'est la réponse est juste
            printf("Bonne reponse : (2 / 2)\n");
            S = S + 2; // On obtient deux points
        }
        // Si la réponse est proche du bon résultat
        else if ((reponse - resultat <= 2) || (resultat - reponse <= 2)) {
            printf("Presque, la bonne reponse est %d : (1 / 2)\n", resultat);
            S = S + 1; // On obtient un seul point
        }
        else { // Si la réponse est mauvaise
            printf("Mauvaise reponse, la bonne reponse est %d : (0 / 2)\n", resultat);
        }
    }
    printf("Fin de l'examen\n");
    printf("Votre note est de %d / 20\n", S); // Affichage de la note finale

    // Tester est afficher la mention
    if (S < 10) {
        printf("Mention : Insuffisant\n");
    }
    else if (S < 12) {
        printf("Mention : Passable\n");
    }
    else if (S < 14) {
        printf("Mention : Assez bien\n");
    }
    else if (S < 16) {
        printf("Mention : Bien\n");
    }
    else if (S < 18) {
        printf("Mention : Tres bien\n");
    }
    else {
        printf("Mention : Excellent\n");
    }

    return 0;
}
