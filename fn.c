#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "fn.h"
#include <stdlib.h>
int verifier(struct user a)
{
struct user b;
int k=0;
int r;
FILE*f;
f=fopen("user","r");

while(fscanf(f,"%s %s %d ",b.login,b.password,&b.role)!=EOF)

{ 
     if ( strcmp(b.login,a.login)==0 && strcmp(a.password,b.password)==0) 
           
        r=b.role;

{
}
}
return r;
}

void ajouter_personne(personne p)
{

	FILE *f;
	f=fopen("client.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f,"%s %s %s %d %s %d %s %s \n",p.cin, p.nom, p.prenom,p.d.jour, p.d.mois, p.d.annee,p.adresse, p.sexe);
	fclose(f);
	}
}

enum
{
		CIN,
		NOM,
		PRENOM,
		JOUR,
		MOIS,
		ANNEE,
		ADRESSE,
		SEXE,
		COLUMNS,
};


void afficher_personne(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char cin[30];
	char nom[30];
	char prenom[30];
	char jour[30];
        char mois[30];
        char annee[30];
	char adresse[30];
	char sexe[30]; 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("client.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("client.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin, nom, prenom, jour, mois, annee, adresse, sexe)!=EOF)
			{
		gtk_list_store_append (store,&iter);

		gtk_list_store_set (store, &iter, CIN,cin, NOM, nom, PRENOM, prenom, JOUR,jour,  MOIS,mois, ANNEE,annee, ADRESSE, adresse, SEXE,sexe, -1 );
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}}

/************************************************************************************/
personne rechercher (char cin[20])
{
    FILE*f;

personne p;
    

    f=fopen("client.txt","r");
if(f!=NULL){
    while((fscanf(f,"%s %s %s %d %s %d %s %s \n",p.cin, p.nom, p.prenom,&p.d.jour, p.d.mois, &p.d.annee,p.adresse, p.sexe)!=EOF))
    {
        if((strcmp(p.cin,cin)==0))
        {
	 printf("ok \n");
	return p;
fclose(f);
	}
        
		strcpy(p.cin,"error");
		strcpy(p.nom,"error");
		strcpy(p.prenom,"error");
               
                
                

			    
    }
	
    fclose (f);}
    return p;

}
/************************************************************************************/

/************************************************************************************/

void modifier_personne(personne p1)
{
    FILE*f;
    FILE*e;
    personne p;
    char cin[20];
    f=fopen("client.txt","r");
    e=fopen("tmp.txt","a+");

    
    if(f!=NULL)
    { if(e!=NULL)
    { 
        while(fscanf(f,"%s %s %s %d %s %d %s %s  \n",p.cin, p.nom, p.prenom, &p.d.jour, p.d.mois, &p.d.annee, p.adresse, p.sexe)!=EOF)
        {
		printf("\n %s \n",p1.cin);
            if(strcmp(p.cin,p1.cin)!=0)
            {
                fprintf(e,"%s %s %s %d %s %d %s %s  \n",p.cin, p.nom, p.prenom, p.d.jour, p.d.mois, p.d.annee, p.adresse, p.sexe);	
			printf("\n oki \n");

            }
            else
            { printf("\n oki1 \n");



                fprintf(e,"%s %s %s %d %s %d %s %s  \n",p1.cin, p1.nom, p1.prenom, p1.d.jour, p1.d.mois, p1.d.annee, p1.adresse, p1.sexe);
            }
        }
        fclose(f);
        fclose(e);
remove("client.txt");
rename("tmp.txt","client.txt");

    }}

}




int date_entier(char ch[100])
{int i;
  char *tab[12]={"janvier","février","mars","avril","mai","juin",
"juillet","août","septembre","Octobre","Novembre","Décembre"};
for(i=0;i<11;i++)
{
  if(strcmp((tab[i]) ,ch)==0)
  {return i;}

}

}



int supprimer_personne(personne p,char cin[100])
{
    FILE*f;
    FILE*c;
    int suppri=0;
    //printf("donner le nom qui veut supprimet : ");
    //scanf("%s",CIN);
    f=fopen("client.txt","r+");
    c=fopen("tmp.txt","w+");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %s %s  \n",p.cin, p.nom, p.prenom, &p.d.jour, p.d.mois, &p.d.annee, p.adresse, p.sexe)!=EOF)
        {

            if ((strcmp(p.cin,cin)!=0))
            {               
                fprintf(c,"%s %s %s %d %s %d %s %s  \n",p.cin, p.nom, p.prenom, p.d.jour, p.d.mois, p.d.annee, p.adresse, p.sexe);                
            }
            else
            {
              suppri=1;
            }
        }
    }
fclose(f);
fclose(c);
remove("client.txt");
rename("tmp.txt","client.txt");
return suppri;
}

