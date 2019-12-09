#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "offre.h"

void
on_buttonajouteroffre_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output1;
GtkWidget *entryid;
GtkWidget *entrytitre;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *an1;
GtkWidget *jour2;
GtkWidget *mois2;
GtkWidget *an2;
GtkWidget *entryhotel;
GtkWidget *categ;
GtkWidget *entrydetail;
GtkWidget *entryprix;


FILE *f;
char a[30],b[30],i[30],j[30],k[30],l[30]; int c,d,e,f1,g,h;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30],a11[30],a12[30];
entryid=lookup_widget(button,"entryid");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryid)));

entrytitre=lookup_widget(button,"entrytitre");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(entrytitre)));

jour1=lookup_widget(button,"jour1");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));

mois1=lookup_widget(button,"mois1");
d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));

an1=lookup_widget(button,"an1");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an1));



jour2=lookup_widget(button,"jour2");
f1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));

mois2=lookup_widget(button,"mois2");
g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));

an2=lookup_widget(button,"an2");
h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an2));

entryhotel=lookup_widget(button,"entryhotel");
strcpy(i,gtk_entry_get_text(GTK_ENTRY(entryhotel)));

categ=lookup_widget(button, "categ");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(categ)));

entrydetail=lookup_widget(button,"entrydetail");
strcpy(k,gtk_entry_get_text(GTK_ENTRY(entrydetail)));

entryprix=lookup_widget(button,"entryprix");
strcpy(l,gtk_entry_get_text(GTK_ENTRY(entryprix)));
int n=0;
output1=lookup_widget(button,"labelerroroffre");
f=fopen("offre.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);	
	

	if(n!=0) {gtk_label_set_text(GTK_LABEL(output1),"id existant");}
	else	
	{f=fopen("offre.txt","a+");
	if(f!=NULL)
	{
   		fprintf(f,"%s %s %d %d %d %d %d %d %s %s %s %s\n",a,b,c,d,e,f1,g,h,i,j,k,l); 
   

	}
	fclose(f);
	gtk_label_set_text(GTK_LABEL(output1),"ajout avec succes");}	


}


void
on_buttonafficheroffre_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *notebook;
GtkWidget *window1;
window1=lookup_widget(button,"window1");
notebook=lookup_widget(window1,"notebook1");
treeview1=lookup_widget(window1,"treeview1");
afficher1(treeview1);

}


void
on_buttonsupprimeroffre_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
char a[30];
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30],a11[30],a12[30];
GtkWidget *entrysupoffre;
GtkWidget *output2;
FILE *f;
output2=lookup_widget(button,"labelerroroffre2");

entrysupoffre=lookup_widget(button,"entrysupoffre");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrysupoffre)));

int n=0;

f=fopen("offre.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);
if(n!=0) {gtk_label_set_text(GTK_LABEL(output2),"suppression réussite");
sup_offre(a,f);}
else gtk_label_set_text(GTK_LABEL(output2),"Id offre inexistant");






}


void
on_buttonafficheroffre2_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{FILE *f;
GtkWidget *entryidoffre2,*labelerroroffre2;
GtkWidget *labelidoffre2,*labeltitreoffre,*jj1,*mm1,*aaaa1,*jj2,*mm2,*aaaa2,*labelhotel,*labelcateg,*labeldetail,*labelprix;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30],a11[30],a12[30];
char a[30];
int n=0;

entryidoffre2=lookup_widget(button,"entryidoffre2");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryidoffre2)));

labelidoffre2=lookup_widget(button,"labelidoffre2");
labeltitreoffre=lookup_widget(button,"labeltitreoffre");
jj1=lookup_widget(button,"jj1");
mm1=lookup_widget(button,"mm1");
aaaa1=lookup_widget(button,"aaaa1");
jj2=lookup_widget(button,"jj2");
mm2=lookup_widget(button,"mm2");
aaaa2=lookup_widget(button,"aaaa2");
labelhotel=lookup_widget(button,"labelhotel");
labelcateg=lookup_widget(button,"labelcateg");
labeldetail=lookup_widget(button,"labeldetail");
labelprix=lookup_widget(button,"labelprix");
f=fopen("offre.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);
labelerroroffre2=lookup_widget(button,"labelerroroffre2"); 

if(n==0) {gtk_label_set_text(GTK_LABEL(labelerroroffre2),"cette offre n'existe pas");}
else{
f = fopen("offre.txt", "r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF)
{
if(strcmp(a,a1)==0)
{gtk_label_set_text(GTK_LABEL(labelidoffre2),a1);
gtk_label_set_text(GTK_LABEL(labeltitreoffre),a2);
gtk_label_set_text(GTK_LABEL(jj1),a3);
gtk_label_set_text(GTK_LABEL(mm1),a4);
gtk_label_set_text(GTK_LABEL(aaaa1),a5);
gtk_label_set_text(GTK_LABEL(jj2),a6);
gtk_label_set_text(GTK_LABEL(mm2),a7);
gtk_label_set_text(GTK_LABEL(aaaa2),a8);
gtk_label_set_text(GTK_LABEL(labelhotel),a9);
gtk_label_set_text(GTK_LABEL(labelcateg),a10);
gtk_label_set_text(GTK_LABEL(labeldetail),a11);
gtk_label_set_text(GTK_LABEL(labelprix),a12);

}


}
fclose(f);
gtk_label_set_text(GTK_LABEL(labelerroroffre2),"trouvé");}
}


void
on_buttonmodifoffre_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *entryidoffre2, *entryn_idoffre,*entryn_titreoffre,*n_jj1,*n_mm1,*n_aaaa1,*n_jj2,*n_mm2,*n_aaaa2,*entryn_hotel,*n_categ,*entryn_detail,*entryn_prix;
FILE *f,*fich;
GtkWidget *labelerroroffre3;
int n=0;
char a[30],b[30],i[30],j[30],k[30],l[30],a13[30]; int c,d,e,f1,g,h;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30],a11[30],a12[30];
entryidoffre2=lookup_widget(button,"entryidoffre2");
strcpy(a13,gtk_entry_get_text(GTK_ENTRY(entryidoffre2)));

entryn_idoffre=lookup_widget(button,"entryn_idoffre");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryn_idoffre)));

entryn_idoffre=lookup_widget(button,"entryn_titreoffre");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(entryn_idoffre)));

n_jj1=lookup_widget(button,"n_jj1");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_jj1));

n_mm1=lookup_widget(button,"n_mm1");
d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_mm1));

n_aaaa1=lookup_widget(button,"n_aaaa1");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_aaaa1));

n_jj2=lookup_widget(button,"n_jj2");
f1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_jj2));

n_mm2=lookup_widget(button,"n_mm2");
g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_mm2));

n_aaaa2=lookup_widget(button,"n_aaaa2");
h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(n_aaaa2));



entryn_hotel=lookup_widget(button,"entryn_hotel");
strcpy(i,gtk_entry_get_text(GTK_ENTRY(entryn_hotel)));

n_categ=lookup_widget(button, "n_categ");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(n_categ)));

entryn_detail=lookup_widget(button,"entryn_detail");
strcpy(k,gtk_entry_get_text(GTK_ENTRY(entryn_detail)));

entryn_prix=lookup_widget(button,"entryn_prix");
strcpy(l,gtk_entry_get_text(GTK_ENTRY(entryn_prix)));

f=fopen("offre.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);

f=fopen("offre.txt","r");
fich=fopen("tempoffre.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)!=EOF)
{
if(strcmp(a13,a1)==0)
{
fprintf(fich,"%s %s %d %d %d %d %d %d %s %s %s %s\n",a,b,c,d,e,f1,g,h,i,j,k,l); 

}
else fprintf(fich,"%s %s %s %s %s %s %s %s %s %s %s %s\n",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);


}

fclose(f);
fclose(fich);
remove("offre.txt");
rename("tempoffre.txt","offre.txt");
FILE* fichier = NULL;

fichier = fopen("tempoffre.txt", "w");
if (fichier != NULL)
{
fputs("", fichier);
fclose(fichier);


}




}
