#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

int main() {
    int choixPrincipal, choixVoyage, choixFichiers, choixTableauResultat;
    int n;
    FILE *fp = NULL, *fi = NULL;
    VOYAGE *t = NULL;
    RESULTAT **tableauresultat = NULL;

    while (1) {
        // Menu Principal
        printf("\n********** Menu Principal **********\n");
        printf("1. Gestion des voyages\n");
        printf("2. Liste des destinations propos�es par les voyages\n");
        printf("3. Nombre des clients inscrits pour un voyage donn�\n");
        printf("4. Prix le plus bas d'une r�servation\n");
        printf("5. Identifiants des clients qui r�servent dans un h�tel\n");
        printf("6. Num�ros des voyages les plus demand�s\n");
        printf("7. Gestion des fichiers\n");
        printf("8. Gestion du tableau r�sultat\n");
        printf("9. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choixPrincipal);

        switch (choixPrincipal) {
            case 1:
                // Gestion des voyages
                while (1) {
                    // Menu Gestion des Voyages
                    printf("\n********** Gestion des voyages **********\n");
                    printf("1. Remplissage\n");
                    printf("2. Affichage\n");
                    printf("3. Ajouter un autre voyage\n");
                    printf("4. Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixVoyage);

                    switch (choixVoyage) {
                        case 1: {
                            // Remplissage
                            printf("\n Saisir le nombre de voyages de l'agence : ");
                            scanf("%d", &n);
                            t = allouer_voyages(&n);
                            saisie_voyages(t, n);
                            break;
                        }
                        case 2:
                            // Affichage
                            affichage_voyages(t, n);
                            break;
                        case 3:
                            // Ajouter un nouveau voyage
                            ajouter_voyage(&t, &n);
                            break;
                        case 4:
                            // Retour au menu principal
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }

                    if (choixVoyage == 4) {
                        break;  // Sortir de la boucle interne et retourner au menu principal
                    }
                }
                break;

            case 2:
                // Liste des destinations propos�es par les voyages
                afficherDestinations(t, n);
                break;

            case 3:
                // Nombre des clients inscrits pour un voyage donn�
                {
                int numVoyage;
                printf("\n Saisir le num�ro du voyage voulu pour savoir le nombre de clients inscrits : ");
                scanf("%d", &numVoyage);
                int nombreClients = nombreClientsInscrits(t, n, numVoyage);
                printf("\n Nombre de clients inscrits pour le voyage %d : %d\n", numVoyage, nombreClients);
                break;
            }
            case 4:
                // Prix le plus bas d'une r�servation
                {
                char dest[50];
                printf("\n Saisir la destination dont vous voulez savoir le prix accessible : ");
                scanf("%49s", dest);
                float prixMinimum = prixPlusBas(t, n, dest);
                // Utilisez prixMinimum dans votre logique
                break;
            }
            case 5:
                // Identifiants des clients qui r�servent dans un h�tel
                 {
                char hotelRecherche[50];
                printf("\n Saisir le nom de l'h�tel pour afficher les identifiants des clients qui y r�servent : ");
                scanf("%49s", hotelRecherche);
                afficherClientsPourHotel(t, n, hotelRecherche);
                break;
            }

            case 6:
                // Num�ros des voyages les plus demand�s
               printf("\n Les num�ros des voyages les plus demand�s : ");
               voyagesPlusDemandes(t, n);
                break;

            case 7:
    // Gestion des fichiers
    while (1) {
        // Menu Gestion des Fichiers
        printf("\n********** Gestion des fichiers **********\n");
        printf("1. Cr�er et remplir les fichiers\n");
        printf("2. Afficher les fichiers\n");
        printf("3. Modifier une r�servation � une position donn�e\n"); // Nouvelle option
        printf("4. Retour au menu principal\n");
        printf("Choix : ");
        scanf("%d", &choixFichiers);

        switch (choixFichiers) {
            case 1:
                // Cr�er et remplir les fichiers
                creerFichiers(&fp, &fi);
                remplir_fichiers(fp, fi, t, n);
                break;

            case 2:
                // Afficher le fichier Index
                afficherFichiers(fp, fi);
                break;

            case 3:
                // Modifier une r�servation � une position donn�e
                {
                    int position;
                    printf("\n Saisir la position de la r�servation � modifier : ");
                    scanf("%d", &position);
                    modifier_reservation_a_position(fp, position);
                }
                break;

            case 4:
                // Retour au menu principal
                break;

            default:
                printf("Choix invalide.\n");
        }

        if (choixFichiers == 4) {
            break;  // Sortir de la boucle interne et retourner au menu principal
        }
    }
    break;
            case 8:
                // Gestion du tableau r�sultat
                while (1) {
                    // Menu Gestion du Tableau R�sultat
                    printf("\n********** Gestion du tableau r�sultat **********\n");
                    printf("1. G�n�rer le tableau r�sultat\n");
                    printf("2. Afficher le tableau r�sultat\n");
                    printf("3. Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixTableauResultat);

                    switch (choixTableauResultat) {
                        case 1:
                            // G�n�rer le tableau r�sultat
                            if (tableauresultat != NULL) {
                                // Lib�rer la m�moire s'il y a d�j� un tableau r�sultat
                                for (int i = 0; i < n; i++) {
                                    free(tableauresultat[i]);
                                }
                                free(tableauresultat);
                            }
                            tableauresultat = genererResultat(t, n);
                            break;

                        case 2:
                            // Afficher le tableau r�sultat
                            if (tableauresultat != NULL) {
                                afficherTableauResultat(tableauresultat, n);
                            } else {
                                printf("Le tableau r�sultat n'a pas encore �t� g�n�r�.\n");
                            }
                            break;

                        case 3:
                            // Retour au menu principal
                            break;

                        default:
                            printf("Choix invalide.\n");
                    }

                    if (choixTableauResultat == 3) {
                        break;  // Sortir de la boucle interne et retourner au menu principal
                    }
                }
                break;

            case 9:
                // Quitter le programme
                break;

            default:
                printf("Choix invalide.\n");
        }

        if (choixPrincipal == 9) {
            break;  // Sortir de la boucle principale et quitter le programme
        }
    }

    // Lib�rer la m�moire avant de quitter le programme
    if (t != NULL) {
        free(t);
    }

   // Lib�rer la m�moire du tableau r�sultat
    if (tableauresultat != NULL) {
        for (int i = 0; i < n; i++) {
            free(tableauresultat[i]);
        }
        free(tableauresultat);
    }

    // Fermer les fichiers
    if (fp != NULL) {
        fclose(fp);
    }
    if (fi != NULL) {
        fclose(fi);
    }

    return 0;
}




