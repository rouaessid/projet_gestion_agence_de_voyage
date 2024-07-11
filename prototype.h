#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "mabib.h"
VOYAGE* allouer_voyages(int );
RESERVATION* allouer_reservations(int );
CLIENT* allouer_clients(int );
void saisie_voyages(VOYAGE* , int );
void saisie_reservations(RESERVATION* , int );
void saisie_clients(CLIENT* , int );
void affichage_voyages(VOYAGE* , int );
void affichage_reservations(RESERVATION* , int );
void affichage_clients(CLIENT* , int );
void afficherDestinations(VOYAGE* , int );
int nombreClientsInscrits(VOYAGE* , int , int );
float prixPlusBas(VOYAGE* , int , char );
void afficherClientsPourHotel(VOYAGE* , int , char ) ;
void voyagesPlusDemandes(VOYAGE* , int );
VOYAGE* ajouter_voyage(VOYAGE* , int* );
RESULTAT** genererResultat(VOYAGE*, int );
void afficherResultat(RESULTAT* );
void afficherTableauResultat(RESULTAT** , int );
void creerFichiers(FILE**, FILE**);
void ecrire_reservation_dansfichier(FILE* , RESERVATION* );
void remplir_fichiers(FILE* , FILE* , VOYAGE* , int );
RESERVATION* lire_reservation_dufichier(FILE* , RESERVATION* );
void afficherFichiers(FILE* , FILE* );
void afficher_reservation_a_position(FILE* , FILE* , int );
void modifier_reservation_a_position(FILE* , int );
#endif // PROTOTYPES_H
