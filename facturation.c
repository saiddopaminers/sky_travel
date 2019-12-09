#include <stdio.h>
#include <string.h>
#include "facturation.h"
#include <gtk/gtk.h>
#include <stdlib.h>



enum
{
	ID,
	CIN,	
	JOUR,
	MOIS,
	AN,
	RESERVATION,
	RIB,
	PRIX,
	COLUMNS
};
void afficher1(GtkWidget *liste)
{	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;

 char id[30];
 char cin[30];
 char jour[15];
 char mois[15];
 char an[15];
 char reservation[15];
 char rib[15];
 char prix[18];

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reservation ", renderer, "text",RESERVATION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee", renderer, "text",AN, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("rib", renderer, "text",RIB, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		

		
	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/siwar/Projects/project16/src/file.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/siwar/Projects/project16/src/file.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  ",id,cin,reservation,jour,mois,an,rib,prix)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store, &iter,ID,id,CIN,cin,RESERVATION,reservation,JOUR,jour,MOIS,mois,AN,an,RIB,rib,PRIX,prix,-1);

}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	





}



void sup_offre(char chaine[30],FILE *f)
{

char id[30];
 char cin[30];
 
 
 char jour[15];
 char mois[15];
 char annee[15];
 char reservation[15];
 char rib[15];
 char prix[18];
FILE *pf;
f=fopen("/home/siwar/Projects/project16/src/file.txt","r");
pf=fopen("/home/siwar/Projects/project16/src/happy.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s ",id,cin,reservation,jour,mois,annee,rib,prix)!=EOF)
{
	if(strcmp(id,chaine)!=0)	
	{fprintf(pf,"%s %s %s %s %s %s %s %s \n" ,id,cin,reservation,jour,mois,annee,rib,prix);}
}
fclose(pf);
fclose(f);

pf=fopen("/home/siwar/Projects/project16/src/happy.txt","r");
f=fopen("/home/siwar/Projects/project16/src/file.txt","w+");
while(fscanf(pf,"%s %s %s %s %s %s %s %s ",id,cin,reservation,jour,mois,annee,rib,prix)!=EOF)
{
		
	{fprintf(f,"%s %s %s %s %s %s %s %s  \n",id,cin,reservation,jour,mois,annee,rib,prix);}
}
fclose(f);
fclose(pf);
}
