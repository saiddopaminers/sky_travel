#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "greeting.h"
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *window4;
FILE*f;
void on_button1_clicked(GtkWidget *objet_graphique, gpointer user_data) 
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output1;
GtkWidget *erreur;
	
char login[20];
char password[20];
int k;
window1=lookup_widget(objet_graphique,"window1");
input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");

strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1))); 
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
erreur=lookup_widget(objet_graphique,"label4");
k=verifier(login,password);
if(k==1){
gtk_widget_destroy(window1);
window2 = create_window2 ();
gtk_widget_show(window2);}
if(k==2){
gtk_widget_destroy(window1);
window3 = create_window3 ();
gtk_widget_show(window3);}
if(k==3){
gtk_widget_destroy(window1);
window4 = create_window4 ();
gtk_widget_show(window4);}
else {
gtk_label_set_text(GTK_LABEL(erreur),"mot de passe ou login incorrect");}
}

