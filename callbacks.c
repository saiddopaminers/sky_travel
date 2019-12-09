#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fn.h"
#include <string.h>
GtkWidget *authentification;
GtkWidget *espace_admin;
GtkWidget *password;
GtkWidget *login;
GtkWidget *treeview1;
GtkWidget *notebook2;


void
on_connexion_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
struct user a;
int k;
authentification=lookup_widget(objet_graphique,"authentification");
//espaceclient=lookup_widget(objet_graphique,"espaceclient");
login=lookup_widget(objet_graphique,"login");
password=lookup_widget(objet_graphique,"password");
strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(password)));
k=verifier(a);
if(k==3)
{
espace_admin=create_espace_admin();
gtk_widget_destroy(authentification);
gtk_widget_show(espace_admin);
}

}


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;

GtkWidget *cinn,*nom, *prenom, *jour, *mois, *annee, *adresse, *sexeh, *sexef;
GtkWidget *espace_admin;

espace_admin=lookup_widget(objet,"espace_admin");

cinn=lookup_widget(objet, "cin");
nom=lookup_widget(objet, "nom");
prenom=lookup_widget(objet, "prenom");
jour=lookup_widget(objet, "spinbuttonjour");
mois=lookup_widget(objet, "comboboxmois");
annee=lookup_widget(objet, "spinbuttonannee");
adresse=lookup_widget(objet, "adresse");
sexeh=lookup_widget(objet, "radiobuttonh");
sexef=lookup_widget(objet, "radiobuttonf");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

p.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
strcpy (p.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));

p.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sexeh)))
	strcpy(p.sexe,"Homme");
  else 	strcpy(p.sexe,"Femme");

ajouter_personne(p);
}


void
on_label100_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
espace_admin=lookup_widget(objet,"espace_admin");
notebook2=lookup_widget(espace_admin,"notebook2");
treeview1=lookup_widget(espace_admin,"treeview1");
afficher_personne(treeview1);

}


void
on_recherche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *rechcin,*cinn,*nom,*prenom,*jour,*mois,*annee,*adresse,*sexe;
  personne p;
  char cin[20] ;
 

  
  rechcin=lookup_widget (objet,"rechcin");
  strcpy(cin,gtk_entry_get_text (GTK_ENTRY(rechcin)));
  
  p=rechercher(cin);

  FILE* f;
  f=fopen("client.txt","r");
 
  cinn=lookup_widget (objet,"cinm");
  nom=lookup_widget (objet,"nomm");
  prenom=lookup_widget (objet,"prenomm");
  jour=lookup_widget (objet,"spinbuttonjourm");
  //mois=lookup_widget (objet,"comboboxmoism");
  mois=lookup_widget (objet,"moism"); 
  annee=lookup_widget (objet,"spinbuttonanneem");
  adresse=lookup_widget (objet,"adressem");
  sexe=lookup_widget (objet,"sexem");
  gtk_entry_set_text (GTK_ENTRY(cinn),p.cin);
  gtk_entry_set_text (GTK_ENTRY(nom),p.nom);
  gtk_entry_set_text (GTK_ENTRY(prenom),p.prenom);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.d.jour);
  //gtk_combo_box_set_active(GTK_COMBO_BOX(mois),date_entier(p.d.mois));
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.d.annee);
  gtk_entry_set_text (GTK_ENTRY(mois),p.d.mois);
  gtk_entry_set_text (GTK_ENTRY(adresse),p.adresse);
  gtk_entry_set_text (GTK_ENTRY(sexe),p.sexe);
  
  
  

  
  fclose(f);
}



void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cinn,*nom,*prenom,*jour,*mois,*annee,*adresse,*sexe;
  
  personne p1;

  char cin[20];
  
  
  FILE* f;
  f=fopen("client.txt","r");

  cinn=lookup_widget (objet,"cinm");
  nom=lookup_widget (objet,"nomm");
  prenom=lookup_widget (objet,"prenomm");
  jour=lookup_widget (objet,"spinbuttonjourm");
  mois=lookup_widget (objet,"moism");
  annee=lookup_widget (objet,"spinbuttonanneem");
  adresse=lookup_widget (objet,"adressem");
  sexe=lookup_widget (objet,"sexem");
  
strcpy(p1.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));
strcpy(p1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));



p1.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
strcpy(p1.d.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
p1.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
//strcpy(moisch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));



strcpy(p1.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(p1.sexe,gtk_entry_get_text(GTK_ENTRY(sexe)));




  modifier_personne(p1);
  fclose(f);
}



void
on_supp_clicked                        (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *cinn,*nom,*prenom,*jour,*mois,*annee,*adresse,*sexe,*output;
  personne p;
char ch[100],ch1[100],cin[100];
int suppri;
  FILE* f;
  //f=fopen("residents.txt","r");
  //input8=lookup_widget (button,"Mentry25");
  //strcpy(CIN,gtk_entry_get_text (GTK_ENTRY(input8)));

  cinn=lookup_widget (objet,"cinm");
  nom=lookup_widget (objet,"nomm");
  prenom=lookup_widget (objet,"prenomm");
  jour=lookup_widget (objet,"spinbuttonjourm");
  //mois=lookup_widget (objet,"comboboxmoism");
  mois=lookup_widget (objet,"moism"); 
  annee=lookup_widget (objet,"spinbuttonanneem");
  adresse=lookup_widget (objet,"adressem");
  sexe=lookup_widget (objet,"sexem");
   output=lookup_widget (objet,"delelable");
   strcpy (cin,gtk_entry_get_text(GTK_ENTRY(cinn)));
   suppri=supprimer_personne(p,cin);
  if (suppri==1)
   {
  gtk_label_set_text (GTK_LABEL(output),"Profile-vous deleted");
   }

}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
espace_admin=lookup_widget(objet,"espace_admin");
gtk_widget_destroy(espace_admin);
espace_admin=create_espace_admin();
gtk_widget_show(espace_admin);

}

