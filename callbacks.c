#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "rec.h"
#include <string.h> 

GtkWidget *window1;
GtkWidget *treeview1;
GtkWidget *notebook1;

void
on_soumettre_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{  

rec recla;

GtkWidget *input1,*input2;
GtkWidget *combobox_sujet;
GtkWidget *window1;

window1=lookup_widget(objet,"window1");

input1=lookup_widget(objet, "id_client");
input2=lookup_widget(objet, "reclamation");
combobox_sujet=lookup_widget(objet, "combobox_sujet");


strcpy(recla.id_client,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(recla.reclamation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(recla.sujet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_sujet)));


ajouter_rec(recla);
}



void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *treeview1;

window1=lookup_widget(objet,"window1");

treeview1=lookup_widget(window1,"treeview1");
afficher_rec(treeview1);
}







void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *window1;
GtkWidget *window;

int a;
window1=lookup_widget(objet,"window1");
input=lookup_widget(objet,"spinbutton1");
a=gtk_spin_button_get_value(GTK_SPIN_BUTTON (input));
delete(a);
window=create_window2();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
}


void
on_validate_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
rec recla;

GtkWidget *input1,*input2;
GtkWidget *combobox_sujet;
GtkWidget *window1;

window1=lookup_widget(objet,"window2");

input1=lookup_widget(objet, "id_client");
input2=lookup_widget(objet, "reclamation");
combobox_sujet=lookup_widget(objet, "combobox_sujet");


strcpy(recla.id_client,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(recla.reclamation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(recla.sujet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_sujet)));


ajouter_rec(recla);
}

