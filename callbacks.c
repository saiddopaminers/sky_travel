#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>
#include "facturation.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input7;
GtkWidget *input9;
GtkWidget *input10;

FILE *f;
char a[30],b[30],j[30],l[30],m[30]; int c,d,e;


input1=lookup_widget(objet,"identifiant");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(objet,"cin");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));


input7=lookup_widget(objet, "combobox2");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

input3=lookup_widget(objet,"jour");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

input4=lookup_widget(objet,"mois");
d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

input5=lookup_widget(objet,"annee");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));

input9=lookup_widget(objet,"rib");
strcpy(l,gtk_entry_get_text(GTK_ENTRY(input9)));

input10=lookup_widget(objet,"prix");
strcpy(m,gtk_entry_get_text(GTK_ENTRY(input10)));

f=fopen("/home/siwar/Projects/project16/src/file.txt","a+");
	if(f!=NULL)
	{
   		fprintf(f," %s %s %s %d %d %d %s %s \n",a,b,j,c,d,e,l,m); 
   

	}
	fclose(f);

}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *notebook;
GtkWidget *window1;
window1=lookup_widget(objet,"window1");
notebook=lookup_widget(window1,"notebook1");
treeview1=lookup_widget(window1,"treeview1");
afficher1(treeview1);
}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
char a[30];
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30];
GtkWidget *entrysupclient;
GtkWidget *output2;
FILE *f;
output2=lookup_widget(objet,"label");

entrysupclient=lookup_widget(objet,"id");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrysupclient)));

int n=0;

f=fopen("/home/siwar/Projects/project16/src/file.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s  ",a1,a2,a3,a4,a5,a6,a7)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);
if(n!=0) {gtk_label_set_text(GTK_LABEL(output2),"suppression réussite");
sup_offre(a,f);}
else gtk_label_set_text(GTK_LABEL(output2),"Id client inexistant");


}


void
on_afficher_donner_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
GtkWidget *entryid2;
GtkWidget *ancienn,*ancienp,*ancienc,*anciens,*ancienj,*ancienm,*ancienl;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30];
char a[30];

entryid2=lookup_widget(objet,"nnidentifiant");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryid2)));

ancienn=lookup_widget(objet,"an1");
ancienp=lookup_widget(objet,"an2");
ancienc=lookup_widget(objet,"an3");
anciens=lookup_widget(objet,"an4");
ancienj=lookup_widget(objet,"an5");
ancienm=lookup_widget(objet,"an6");
ancienl=lookup_widget(objet,"an7");







f = fopen("/home/siwar/Projects/project16/src/file.txt", "r");
while(fscanf(f,"%s %s %s %s %s %s %s %s  ",a1,a2,a3,a4,a5,a6,a7,a8)!=EOF)
{
if(strcmp(a,a1)==0)
{gtk_label_set_text(GTK_LABEL(ancienn),a2);
gtk_label_set_text(GTK_LABEL(ancienp),a3);
gtk_label_set_text(GTK_LABEL(ancienc),a4);
gtk_label_set_text(GTK_LABEL(anciens),a5);
gtk_label_set_text(GTK_LABEL(ancienj),a6);
gtk_label_set_text(GTK_LABEL(ancienm),a7);
gtk_label_set_text(GTK_LABEL(ancienl),a8);


}


}
}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *entryid2;
GtkWidget *entrycin,*entryjour,*entrymois,*entryannee,*entryreservation,*entryrib,*entryprix;
FILE *f,*fich;
char k[30],a[30],d[30],h[30],i[30]; int e,f1,g;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30];


entryid2=lookup_widget(objet,"nnidentifiant");
strcpy(k,gtk_entry_get_text(GTK_ENTRY(entryid2)));

entrycin=lookup_widget(objet,"nncin");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrycin)));

entryreservation=lookup_widget(objet, "nncombobox");
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryreservation)));


entryjour=lookup_widget(objet,"nnjour");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));

entrymois=lookup_widget(objet,"nnmois");
f1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrymois));

entryannee=lookup_widget(objet,"nnannee");
g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));



entryrib=lookup_widget(objet,"nnrib");
strcpy(h,gtk_entry_get_text(GTK_ENTRY(entryrib)));


entryprix=lookup_widget(objet,"nnprix");
strcpy(i,gtk_entry_get_text(GTK_ENTRY(entryprix)));


f=fopen("/home/siwar/Projects/project16/src/file.txt","r");
fich=fopen("/home/siwar/Projects/project16/src/modif.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8)!=EOF)
{
if(strcmp(k,a1)==0)
{
fprintf(fich,"%s %d %d %d %s %s %s\n",a1,e,f1,g,d,h,i); 

}
else fprintf(fich,"%s %s %s %s %s %s %s %s\n",a1,a2,a3,a4,a5,a6,a7,a8);


}

fclose(f);
fclose(fich);
remove("/home/siwar/Projects/project16/src/file.txt");
rename("/home/siwar/Projects/project16/src/modif.txt","/home/siwar/Projects/project16/src/file.txt");
FILE* fichier = NULL;

fichier = fopen("/home/siwar/Projects/project16/src/modif.txt", "w");
if (fichier != NULL)
{
fputs("", fichier);
fclose(fichier);
}

}

