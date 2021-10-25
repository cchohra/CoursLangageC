#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
L'objectif est de simuler un examen de math�matiques automatis�.
Le programme g�n�re al�atoirement dix op�rations (*, -, +),
puis l'utilisateur r�pond � chacune des op�rations.
Chaque r�ponse est not�e sur deux points :
    - Si la r�ponse est juste on obtient 2 / 2.
    - Si la r�ponse est proche du bon r�sultat (diff�rence inf�rieure � 2)
      on obtient 1 / 2.
    - Sinon la r�ponse est rat�e et on obtient 0 / 2.
La note finale (sur 20) est donn�e par la somme des notes obtenues pour chaque r�ponse.
A la fin le programme doit afficher une note, et donner une mention � l'utilisateur :
    - Insuffisant : pour note finale < 10.
    - Passable : 10 <= note finale < 12.
    - Assez Bien : 12 <= note finale < 14.
    - Bien : 14 <= note finale < 16.
    - Tr�s Bien : 16 <= note finale < 18.
    - Exc�lent : note finale >= 18.
*/

int main()
{
    srand(time(NULL)); // Initialiser la fonction rand()
    int S = 0;         // Initialiser la note finale par 0
    for (int i = 1; i <= 10; i++) {
        int resultat, reponse;
        int a = (rand() % 40) - 20; // a est un nombre al�atoire entre -20 et 20
        int b = (rand() % 40) - 20; // b est un nombre al�atoire entre -20 et 20
        int op = rand() % 3;        // Choisir une op�ration al�atoire (*, -, +)
        switch (op) { // Tester les op�rations possibles
        case 0 : // 0 pour la multiplication
            resultat = a * b; // Calculer le bon r�sultat
            printf("(%d) * (%d) = ", a, b); // Afficher l'op�ration � effectuer
            break;
        case 1 : // 1 pour la soustraction
            resultat = a - b; // Calculer le bon r�sultat
            printf("(%d) - (%d) = ", a, b); // Afficher l'op�ration � effectuer
            break;
        case 2 : // 2 pour l'addition
            resultat = a + b; // Calculer le bon r�sultat
            printf("(%d) + (%d) = ", a, b); // Afficher l'op�ration � effectuer
            break;
        }
        scanf("%d", &reponse); // Lire la r�ponse de l'utilisateur
        if (reponse == resultat) { // C'est la r�ponse est juste
            printf("Bonne reponse : (2 / 2)\n");
            S = S + 2; // On obtient deux points
        }
        // Si la r�ponse est proche du bon r�sultat
        else if ((reponse - resultat <= 2) || (resultat - reponse <= 2)) {
            printf("Presque, la bonne reponse est %d : (1 / 2)\n", resultat);
            S = S + 1; // On obtient un seul point
        }
        else { // Si la r�ponse est mauvaise
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
