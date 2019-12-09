#include <stdio.h>
#include <string.h>
#include "rec.h"
#include <gtk/gtk.h>
#include <stdlib.h>


enum
{                RECLAMATION,
                 ID_CLIENT,
                 SUJET,
	         COLUMNS
};

void ajouter_rec(rec recla)
{

	FILE *f;
	f=fopen("/home/amira/Projects/final/success/src/rec.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f,"%s %s %s\n",recla.id_client,recla.sujet,recla.reclamation);
	 fclose(f);
	}
}

void afficher_rec(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id_client[30];
	char sujet[30];
	char reclamation[30];
        char id[30];
	store=NULL;

	FILE *f;
FILE *f1;
f1=fopen("/home/amira/Projects/final/success/src/useract.txt","a+");
//fprintf(f1,"%s \n",14);
fscanf(f1,"%s \n",id);
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id_client",renderer, "text",ID_CLIENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("sujet",renderer, "text",SUJET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation",renderer, "text",RECLAMATION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("/home/amira/Projects/final/success/src/rec.txt","r");


		if(f==NULL)
		{
			return;
		}
		else
		{
			while(fscanf(f,"%s %s %s \n",id_client,sujet,reclamation)!=EOF)

			{if(strcmp(id,id_client)==0){
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, ID_CLIENT,id_client, SUJET, sujet,RECLAMATION,reclamation,  -1);
			}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}
}

void delete(int *a){


char id_client[30];
	char sujet[30];
	char reclamation[30];
        char id[30];
	int b;
	b=1;

	FILE *f;
FILE *f1;
FILE *ftemp;
f1=fopen("/home/amira/Projects/final/success/src/useract.txt","a+");
fscanf(f1,"%s \n",id);
f = fopen("/home/amira/Projects/final/success/src/rec.txt","r");
ftemp = fopen("/home/med/Desktop/success/src/temp.txt","a+");
if(f==NULL)
		{
			return;
		}
		else
		{
			while(fscanf(f,"%s %s %s \n",id_client,sujet,reclamation)!=EOF)
			{if(strcmp(id,id_client)==0)
			{if(a!=b)
	{fprintf(ftemp,"%s %s %s \n",id_client,sujet,reclamation);
				b=b+1;}}
		else{fprintf(ftemp,"%s %s %s \n",id_client,sujet,reclamation);}
				}

			

}
fclose(f);
fclose(ftemp);
remove ("/home/amira/Projects/final/success/src/rec.txt");
rename ("/home/amira/Projects/final/success/src/temp.txt","/home/amira/Projects/final/success/src/rec.txt");

}























