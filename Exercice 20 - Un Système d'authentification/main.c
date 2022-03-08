#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Le but de cet exercice est d'écrire un système d'authentification
    très simplifié.
        - Le programme doit donner deux option à l'utilisateur.
            * Inscription : saisir nom, prenom, email et mot de passe.
            * Les informations saisies doivent être enregistrées
              dans un fichier binaire.
            * Authentification : saisir email et mot de passe.
            * Chercher les informations dans le fichier binaire.
            * Si les informations sont justes, afficher un message d'accueil.
            * Sinon afficher un message d'erreur.
*/

typedef struct {
    char nom[30], prenom[30], email[30], mot[30];
} utilisateur;

int main() {
    int c;
    printf("1 - Vous inscrire\n");
    printf("2 - Vous authentifier\n");
    printf("Veuillez faire un choix : ");
    do {
        scanf("%d", &c);
        getchar();
        if (c != 1 && c != 2) {
            printf("Attention, mauvais choix\n");
            printf("Veuillez faire un choix valide : ");
        }
    } while (c != 1 && c != 2);
    if (c == 1) { // Si l'utilisateur a choisi de s'inscrire
        utilisateur u;
        printf("Veuillez saisir votre nom : ");
        gets(u.nom);
        printf("Veuillez saisir votre prenom : ");
        gets(u.prenom);
        printf("Veuillez saisir votre email : ");
        gets(u.email);
        printf("Veuillez saisir votre mot de passe : ");
        gets(u.mot);
        FILE *fich = fopen("utilisateurs.dat", "ab");
        if (fich) {
            fwrite(&u, sizeof(utilisateur), 1, fich);
            printf("Vous vous etes inscrit avec succes");
        }
        else printf("Erreur interne");
    }
    if (c == 2) { // Si l'utilisateur a choisi de s'authentifier
        char email[30], mot[30];
        printf("Veuillez saisir votre email : ");
        gets(email);
        printf("Veuillez saisir votre mot de passe : ");
        gets(mot);
        FILE *fich = fopen("utilisateurs.dat", "rb");
        if (fich) {
            utilisateur u;
            int trouve = 0;
            while (!feof(fich) && !trouve) { // tant qu'on n'a pas trouvé l'utilisateur
                                             // et on n'a pas atteint la fin du fichier
                fread(&u, sizeof(utilisateur), 1, fich);
                if (!strcmp(u.email, email) && !strcmp(u.mot, mot)) trouve = 1;
            }
            // Si l'email et le mot de passe sont justes
            if (trouve) printf("Bienvenu %s %s", u.nom, u.prenom);
            // Si l'email et le mot de passe sont erronés
            else printf("Erreur, email ou mot de passe incorrect");
        }
        else printf("Erreur interne");
    }
    return 0;
}
