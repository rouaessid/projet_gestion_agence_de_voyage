
struct resultat {
    int num_voyage;        // numéro de voyage
    int nbr_reservation;   // nombre de réservations
};
typedef struct resultat RESULTAT;
typedef struct resultat RESULTAT;
struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct client
{
    int id;             // identifiant du client
    char nom_c[20];     // nom du client// prénom du client
    char telephone[20];
};
typedef struct client CLIENT;

struct reservation
{
    int idr;             // identifiant de la réservation
    char nom_h[50];      // nom de l’hôtel
    float prix;
    int nbc;             // nombre de clients
    CLIENT *client;
};
typedef struct reservation RESERVATION;

struct voyage
{
    int num;            // numéro de voyage
    char destination[50];
    DATE dv;            // date du voyage (utilisation de la structure DATE)
    int nbr;            // nombre de réservations
    RESERVATION *reservation;
};
typedef struct voyage VOYAGE;



