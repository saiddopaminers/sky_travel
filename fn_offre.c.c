#include <stdio.h>
#include <string.h>
#include "offre.h"
#include <gtk/gtk.h>
#include <stdlib.h>
enum
{
	ID,
	TITRE,
	JOUR1,
	MOIS1,
	AN1,
	JOUR2,
	MOIS2,
	AN2,
	HOTEL,
	CATEG,
	DETAIL,
	PRIX,
	COLUMNS
};
void afficher1(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;

 char id[30];
 char titre[30];
 char jour1[5];
 char mois1[5];
 char an1[5];
 char jour2[5];
 char mois2[5];
 char an2[5];
 char hotel[10];
 char categ[4];
 char detail[30];
 char prix[20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Idoffre", renderer, "text",ID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Titre", renderer, "text",TITRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour1 ", renderer, "text",JOUR1, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois1", renderer, "text",MOIS1, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Annee1 ", renderer, "text",AN1, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour2", renderer, "text",JOUR2, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois2", renderer, "text",MOIS2, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee2", renderer, "text",AN2, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Hotel", renderer, "text",HOTEL, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Categorie", renderer, "text",CATEG, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Détails du vols", renderer, "text",DETAIL, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tarif", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		
	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("offre.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("offre.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",id,titre,jour1,mois1,an1,jour2,mois2,an2,hotel,categ,detail,prix)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store, &iter,ID,id,TITRE,titre,JOUR1,jour1,MOIS1,mois1,AN1,an1,JOUR2,jour2,MOIS2,mois2,AN2,an2,HOTEL,hotel,CATEG,categ,DETAIL,detail,PRIX,prix,-1);

}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	


}



void sup_offre(char chaine[30],FILE *f)
{
char id[30];
 char titre[30];
 char jour1[5];
 char mois1[5];
 char an1[5];
 char jour2[5];
 char mois2[5];
 char an2[5];
 char hotel[10];
 char categ[4];
 char detail[30];
 char prix[20];
FILE *pf;
f=fopen("offre.txt","r");
pf=fopen("offresup.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",id,titre,jour1,mois1,an1,jour2,mois2,an2,hotel,categ,detail,prix)!=EOF)
{
	if(strcmp(id,chaine)!=0)	
	{fprintf(pf,"%s %s %s %s %s %s %s %s %s %s %s %s \n",id,titre,jour1,mois1,an1,jour2,mois2,an2,hotel,categ,detail,prix);}
}
fclose(pf);
fclose(f);

pf=fopen("offresup.txt","r");
f=fopen("offre.txt","w+");
while(fscanf(pf,"%s %s %s %s %s %s %s %s %s %s %s %s ",id,titre,jour1,mois1,an1,jour2,mois2,an2,hotel,categ,detail,prix)!=EOF)
{
		
	{fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",id,titre,jour1,mois1,an1,jour2,mois2,an2,hotel,categ,detail,prix);}
}
fclose(f);
fclose(pf);



}


























