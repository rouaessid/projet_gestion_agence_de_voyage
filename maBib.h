
struct resultat {
    int num_voyage;        // num�ro de voyage
    int nbr_reservation;   // nombre de r�servations
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
    char nom_c[20];     // nom du client// pr�nom du client
    char telephone[20];
};
typedef struct client CLIENT;

struct reservation
{
    int idr;             // identifiant de la r�servation
    char nom_h[50];      // nom de l�h�tel
    float prix;
    int nbc;             // nombre de clients
    CLIENT *client;
};
typedef struct reservation RESERVATION;

struct voyage
{
    int num;            // num�ro de voyage
    char destination[50];
    DATE dv;            // date du voyage (utilisation de la structure DATE)
    int nbr;            // nombre de r�servations
    RESERVATION *reservation;
};
typedef struct voyage VOYAGE;



