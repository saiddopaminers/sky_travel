#include <gtk/gtk.h>

typedef struct
{
char id_client[30];
char sujet[30];
char reclamation[30];

} rec;

void ajouter_rec(rec recla);
void afficher_rec(GtkWidget *liste);
void delete(int *a);
