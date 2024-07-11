#include "maBib.h"
VOYAGE* allouer_voyages(int n) {
    VOYAGE* t;
    t = (VOYAGE*)malloc(n * sizeof(VOYAGE));
    if (!t) exit(-1);
    return t;
}

RESERVATION* allouer_reservations(int nbr) {
    RESERVATION* r;
    r = (RESERVATION*)malloc(nbr * sizeof(RESERVATION));
    if (!r) exit(-2);
    return r;
}
CLIENT* allouer_clients(int nbc) {
    CLIENT* c;
    c = (CLIENT*)malloc(nbc * sizeof(CLIENT));
    if (!c)
        exit(-3);
    return c;
}
void saisie_voyages(VOYAGE* t, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n -----------saisir les informations du voyage %d -------------- \n", i + 1);
        printf("\n saisir numero de voyage : ");
        scanf("%d", &(t + i)->num);
        printf("\n saisir la destination : ");
        scanf("%s", &(t + i)->destination);

        do {
            printf("\n saisir date du voyage (jj/mm/aaaa) :  ");
            scanf("%d/%d/%d", &(t + i)->dv.jour, &(t + i)->dv.mois, &(t + i)->dv.annee);

            if ((t + i)->dv.jour < 1 || (t + i)->dv.jour > 31 || (t + i)->dv.mois < 1 || (t + i)->dv.mois > 12 || (t + i)->dv.annee < 1) {
                printf("\n Date invalide. Veuillez saisir une date valide.\n");
            }
        } while ((t + i)->dv.jour < 1 || (t + i)->dv.jour > 31 || (t + i)->dv.mois < 1 || (t + i)->dv.mois > 12 || (t + i)->dv.annee < 1);
        printf("\n saisir le nombre reservation de ce voyage :");
        scanf("%d", &(t + i)->nbr);
        // Allocation de mémoire pour les réservations du voyage
        (t + i)->reservation = allouer_reservations((t + i)->nbr);
        // Appel de la fonction de saisie des réservations
        saisie_reservations((t + i)->reservation, (t + i)->nbr);
    }
}
void saisie_reservations(RESERVATION* r, int nbr) {
    int j;

    for (j = 0; j < nbr; j++) {
        printf("\n --------------saisir les informations du reservation %d :  -------------------\n", j + 1);
        printf("\n saisir l'identifiant de la réservation : ");
        scanf("%d", &(r + j)->idr);
        printf("\n saisir le nom de l'hôtel : ");
        scanf("%s", (r + j)->nom_h);
        printf("\n saisir le prix de la réservation en TND : ");
        scanf("%f", &(r + j)->prix);
        printf("\n saisir le nombre des clients qui ont fait cette réservation : ");
        scanf("%d", &(r + j)->nbc);

        // Allocation de mémoire pour les clients de la réservation
        (r + j)->client = allouer_clients((r + j)->nbc);

        // Appel de la fonction de saisie des clients
        saisie_clients((r + j)->client, (r + j)->nbc);
    }
}

void saisie_clients(CLIENT* c, int nbc) {
    int k;

    for (k = 0; k < nbc; k++) {
        printf("\n ----------------------saisir les informations du client %d  ----------------------\n", k + 1);
        printf("\n saisir l'identifiant du client : ");
        scanf("%d", &(c + k)->id);
        printf("\n saisir le nom et le prénom du client : ");
        scanf("%s", (c + k)->nom_c);
        printf("\n saisir le numéro de téléphone du client (8 chiffres) : ");
        do {
            scanf("%s", (c + k)->telephone);
        } while (strlen((c + k)->telephone) != 8);
    }
}
void affichage_clients(CLIENT* c, int nbc) {
    int k;

    for (k = 0; k < nbc; k++) {
        printf("\n ----------------------Affichage du client numero %d  ----------------------\n", k + 1);
        printf("|%d", (c + k)->id);
        printf("|%s", (c + k)->nom_c);
        printf("| %s", (c + k)->telephone);
        printf("\n************************************************************\n");
    }
}
void affichage_reservations(RESERVATION* r, int nbr) {
    int j;

    for (j = 0; j < nbr; j++) {
        printf("\n --------------Affichage de la reservation %d :  -------------------\n", j + 1);
        printf("|%d", (r + j)->idr);
        printf("| %s", (r + j)->nom_h);
        printf("| %.2f", (r + j)->prix);
        printf("|%d", (r + j)->nbc);
        printf("\n **************************************************************\n ");
        // Appel de la fonction d'affichage des clients
        affichage_clients((r + j)->client, (r + j)->nbc);
    }
}

void affichage_voyages(VOYAGE* t, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\n \n ------------------------Affichage du voyage numero %d ---------------------\n\n", i + 1);
        printf("%d |", (t + i)->num);
        printf("%s |", (t + i)->destination);
        printf("%d/%d/%d |", (t + i)->dv.jour, (t + i)->dv.mois, (t + i)->dv.annee);
        printf("%d |", (t + i)->nbr);
        printf("\n **************************************************************\n ");
        // Appel de la fonction d'affichage des réservations
        affichage_reservations((t + i)->reservation, (t + i)->nbr);
    }
}
// traitement 1 :
void afficherDestinations(VOYAGE* t, int n) {
    printf("\n La liste des destinations proposees pour les voyages :\n");
    for (int i = 0; i < n; i++) {
        printf("%d  %s \n", i + 1, (t + i)->destination);
    }
}
//traitement 2 :
int nombreClientsInscrits(VOYAGE* t, int n, int numVoyage) {
    printf("\n Le nombre des clients inscrits pour ce voyage :\n");
    int d = 0;
    for (int i = 0; i < n; i++) {
        if ((t + i)->num == numVoyage) {
            for (int j = 0; j < (t + i)->nbr; j++) {
                d += ((t + i)->reservation + j)->nbc;
            }
        }
    }
    return d;
}
//traitement 3 :
float prixPlusBas(VOYAGE* t, int n, char dest[50]) {
    float min = (t->reservation)->prix;
    for (int i = 0; i < n; i++) {
        if (strcmp((t + i)->destination, dest) == 0) {
            for (int j = 0; j < (t + i)->nbr; j++) {
                if (((t + i)->reservation + j)->prix < min) {
                    min = ((t + i)->reservation + j)->prix;
                }
            }
            printf("\n Le prix le plus bas d'une reservation à la destination %s est : %.2f \n", dest, min);
        }
    }
    return min;
}
//traitement 4 :
void afficherClientsPourHotel(VOYAGE* t, int n, char hotelRecherche[50]) {
    printf("\n Les identifiants des clients qui reservent dans l'hôtel %s sont :\n", hotelRecherche);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (t + i)->nbr; j++) {
            if (strcmp(((t + i)->reservation + j)->nom_h, hotelRecherche) == 0) {
                for (int k = 0; k < ((t + i)->reservation + j)->nbc; k++) {
                    printf("%d\n", (((t + i)->reservation + j)->client + k)->id);
                }
            }
        }
    }
}
//traitement 5 :
void voyagesPlusDemandes(VOYAGE* t, int n) {
    int max = 0;
    int numVoyageDemande[100];
    int numVoyageDemandeCount = 0;

    for (int i = 0; i < n; i++) {
        int nbre = 0;
        for (int j = 0; j < (t + i)->nbr; j++) {
            nbre += ((t + i)->reservation + j)->nbc;
        }

        if (nbre > max) {
            max = nbre;
            numVoyageDemande[0] = (t + i)->num;
            numVoyageDemandeCount = 1;
        } else if (nbre == max) {
            numVoyageDemande[numVoyageDemandeCount++] = (t + i)->num;
        }
    }

    printf("\n Les voyages les plus demandes sont :");
    for (int i = 0; i < numVoyageDemandeCount; i++) {
        printf(" %d |", numVoyageDemande[i]);
    }
    printf(" avec un total de %d clients inscrits.\n", max);
}
/// utilisation de la focntion realloc
void ajouter_voyage(VOYAGE** t, int* n) {
    // realloc pour redimensionner le tableau
    *t = (VOYAGE*)realloc(*t, (*n + 1) * sizeof(VOYAGE));
    if (!(*t))
        exit(-4);

    // Ajout du nouveau voyage à la fin du tableau
    VOYAGE* nouveauVoyage = *t + *n;
    (*n)++;

    // Mise à jour la taille du tableau
    // Saisie des informations du nouveau voyage

    printf("\n \n -----------Ajout d'un nouveau voyage -------------- \n \n");
    printf("\n Saisir numero du nouveau voyage : ");
    scanf("%d", &nouveauVoyage->num);
    printf("\n Saisir la destination du nouveau voyage: ");
    scanf("%s", nouveauVoyage->destination);

    // Saisie de la date du voyage
    do {
        printf("\n Saisir date du nouveau voyage (jj/mm/aaaa) : ");
        scanf("%d/%d/%d", &nouveauVoyage->dv.jour, &nouveauVoyage->dv.mois, &nouveauVoyage->dv.annee);

    if(nouveauVoyage->dv.jour <1|| nouveauVoyage->dv.jour>31||nouveauVoyage->dv.mois<1||nouveauVoyage->dv.mois >12||nouveauVoyage->dv.annee <1) {
            printf("\n Date invalide. Veuillez saisir une date valide.\n");
        }
    } while (nouveauVoyage->dv.jour < 1 || nouveauVoyage->dv.jour > 31 || nouveauVoyage->dv.mois < 1 || nouveauVoyage->dv.mois > 12 || nouveauVoyage->dv.annee < 1);

    printf("\n Saisir le nombre de reservations pour le nouveau voyage : ");
    scanf("%d", &nouveauVoyage->nbr);

    // Allocation de mémoire pour les réservations du nouveau voyage
    nouveauVoyage->reservation = allouer_reservations(nouveauVoyage->nbr);

    // Appel de la fonction de saisie des réservations pour le nouveau voyage
    saisie_reservations(nouveauVoyage->reservation, nouveauVoyage->nbr);
}
RESULTAT** genererResultat(VOYAGE* t, int n) {
    // Allocation dynamique d'un tableau d'adresses de structures RESULTAT
    RESULTAT** tableauresultat = (RESULTAT**)malloc(n * sizeof(RESULTAT*));
    if (!tableauresultat) exit(-6);

    // Allocation de chaque structure RESULTAT et remplissage des champs
    RESULTAT** tab = tableauresultat;  // Utilisation du pointeur tab

    for (int i = 0; i < n; i++) {
        *tab = (RESULTAT*)malloc(sizeof(RESULTAT));
        if (!*tab) exit(-5);

        // Supposons que t est un tableau de structures VOYAGE
        (*tab)->num_voyage = (t + i)->num;
        (*tab)->nbr_reservation = (t + i)->nbr;  // Utilisez le champ approprié

        tab++;  // Avancer le pointeur tab vers le prochain élément
    }

    // les voyages les plus demandés selon le nombre de reservation
    RESULTAT** tab1 = tableauresultat;
    for (int i = 0; i < n - 1; i++) {
        RESULTAT** tab2 = tableauresultat;
        for (int j = 0; j < n - i - 1; j++) {
            if ((*tab2)->nbr_reservation < (*(tab2 + 1))->nbr_reservation) {
                RESULTAT* temp = *tab2;
                *tab2 = *(tab2 + 1);
                *(tab2 + 1) = temp;
            }
            tab2++;
        }
        tab1++;
    }

    return tableauresultat;  // Retourner le tableau d'adresses
}
void afficherResultat(RESULTAT* r) {
    printf("Numéro de voyage : %d, Nombre de réservations : %d\n", r->num_voyage, r->nbr_reservation);
}
void afficherTableauResultat(RESULTAT** tableauresultat, int n) {
    printf("\n Affichage du tableau resultat :\n");
    for (int i = 0; i < n; i++) {
        printf("Résultat %d : ", i + 1);
        afficherResultat(*(tableauresultat + i));
    }
}
void creerFichiers(FILE**fp, FILE**fi)
{
*fp=fopen("c:\\fichier reservation", "wb+");
 if(!*fp) exit(-1);
*fi=fopen("c:\\fichierIndex", "wb+");
if( !*fi) exit(-1);
}
void ecrire_reservation_dansfichier(FILE* fp, RESERVATION* r) {
    fwrite(&(r->idr), sizeof(int), 1, fp);
    fwrite(r->nom_h, sizeof(char), strlen(r->nom_h) + 1, fp);
    for (int k = 0; k < r->nbc; k++) {
        fwrite(&((r->client + k)->id), sizeof(int), 1, fp);
        fwrite((r->client + k)->nom_c, sizeof(char), strlen((r->client + k)->nom_c) + 1, fp);
        fwrite(&((r->client + k)->telephone), sizeof(char), strlen((r->client + k)->telephone) + 1, fp);
    }
}
void remplir_fichiers(FILE* fp, FILE* fi, VOYAGE* t, int n) {
    int position;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (t + i)->nbr; j++) {
            // Mémoriser la position du curseur dans le fichier de réservation
            position = ftell(fp);
            // Écrire la réservation directement dans le fichier de réservation
            fwrite((t + i)->reservation + j, sizeof(RESERVATION), 1, fp);
            // Écrire la position dans le fichier d'index
            fwrite(&position, sizeof(int), 1, fi);
        }
    }
}
RESERVATION* lire_reservation_dufichier(FILE* fp, RESERVATION* res) {
    fread(res, sizeof(RESERVATION), 1, fp);
    return res;
}
void afficherFichiers(FILE* fp, FILE* fi) {
    int position;
    RESERVATION* res = malloc(sizeof(RESERVATION)); // Allouer de la mémoire pour une réservation

    rewind(fp);
    rewind(fi);

    printf("\n--------------------- Affichage du fichier Index ---------------------------\n");
    while (fread(&position, sizeof(int), 1, fi) == 1) {
        printf("\n %d", position);
    }

    rewind(fi);
    printf("\n------------------------- Affichage du fichier reservation ---------------------\n");

    while (fread(&position, sizeof(int), 1, fi) == 1) {
        fseek(fp, position, SEEK_SET);
        res = lire_reservation_dufichier(fp, res);
        printf("|%d", res->idr);
        printf("| %s", res->nom_h);
        printf("| %f", res->prix);
        printf("|%d", res->nbc);
        for (int k = 0; k < res->nbc; k++) {
            printf("%d|", (res->client + k)->id);
            printf("%s|", (res->client + k)->telephone);
            printf("%s|", (res->client + k)->nom_c);
        }
        printf("\n");
    }

    free(res->client); // Libérer la mémoire allouée pour les clients
    free(res); // Libérer la mémoire allouée pour la réservation
}
void afficher_reservation_a_position(FILE* fp, FILE* fi, int position) {
    RESERVATION* res = malloc(sizeof(RESERVATION));

    // Se déplacer à la position spécifiée dans le fichier d'index
    fseek(fi, position, SEEK_SET);

    // Lire la position dans le fichier d'index
    fread(&position, sizeof(int), 1, fi);

    // Se déplacer à la position spécifiée dans le fichier de réservation
    fseek(fp, position, SEEK_SET);

    // Lire la réservation à la position spécifiée
    res = lire_reservation_dufichier(fp, res);

    // Afficher la réservation
    printf("|%d", res->idr);
    printf("| %s", res->nom_h);
    printf("| %f", res->prix);
    printf("|%d", res->nbc);
    for (int k = 0; k < res->nbc; k++) {
        printf("%d|", (res->client + k)->id);
        printf("%s|", (res->client + k)->telephone);
        printf("%s|", (res->client + k)->nom_c);
    }
    printf("\n");

    free(res->client);
    free(res);
}

void modifier_reservation_a_position(FILE* fp, int position) {
    RESERVATION* res = malloc(sizeof(RESERVATION));

    // Se déplacer à la position spécifiée dans le fichier de réservation
    fseek(fp, position, SEEK_SET);
    // Lire la réservation à la position spécifiée
    if (fread(res, sizeof(RESERVATION), 1, fp) == 1) {
        // Modifier la réservation (par exemple, changer le prix)
        printf("\nModifier le prix de la reservation : ");
        scanf("%f", &(res->prix));

        // Se déplacer à la position spécifiée dans le fichier de réservation
        fseek(fp, position, SEEK_SET);

        // Écrire la réservation modifiée dans le fichier de réservation
        if (fwrite(res, sizeof(RESERVATION), 1, fp) == 1) {
            printf("\nRéservation modifiée avec succès.\n");
        } else {
            printf("\nErreur lors de l'écriture de la réservation modifiée dans le fichier.\n");
        }
    } else {
        printf("\nErreur lors de la lecture de la réservation à la position spécifiée.\n");
    }
    free(res->client);
    free(res);
}
