#include <stdlib.h>
#include <gtk/gtk.h>
#include "main.h"

int main (int argc, char *argv[])
{
    Data data;
    GtkWidget *fenetre = NULL;
    gtk_init(&argc,&argv);

    fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fenetre),"Calculateur loi ohm");
//ajout d'une boite vertical
GtkWidget * vbox = NULL;
vbox = gtk_vbox_new(TRUE,0);

    //ajout d'une boite horizontal
    GtkWidget * formu = NULL;
    formu = gtk_hbox_new(TRUE,0);

    //ajout d'une etiquette(tension)
    GtkWidget * label_tension = NULL;
    label_tension = gtk_label_new("Tension(v):");
    gtk_label_set_use_markup(GTK_LABEL(label_tension),TRUE);
    gtk_box_pack_start(GTK_BOX(formu),label_tension,FALSE,FALSE,0);

    //ajout d'une saisie de texte
    data.entre_tens = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(formu),data.entre_tens,FALSE,FALSE,0);

        //ajout d'une etiquette(resistance)
    GtkWidget * label_resistance = NULL;
    label_resistance = gtk_label_new("Resistance(ohm):");
    gtk_label_set_use_markup(GTK_LABEL(label_resistance),TRUE);
    gtk_box_pack_start(GTK_BOX(formu),label_resistance,FALSE,FALSE,0);

    //ajout d'une saisie de texte
    data.entre_resist = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(formu),data.entre_resist,FALSE,FALSE,0);

    //ajout d'une etiquette(intensite)
    GtkWidget * label_intensite = NULL;
    label_intensite = gtk_label_new("Intensité(A):");
    gtk_label_set_use_markup(GTK_LABEL(label_intensite),TRUE);
    gtk_box_pack_start(GTK_BOX(formu),label_intensite,FALSE,FALSE,0);

    //ajout d'une saisie de texte
    data.entre_intens = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(formu),data.entre_intens,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox),formu,FALSE,FALSE,0);

    //ajout d'un bouton
    GtkWidget * bouton = NULL;
    bouton = gtk_button_new_with_label("calculer");
    gtk_box_pack_start(GTK_BOX(vbox),bouton,FALSE,FALSE,0);


    //ajout d'une reponse
    data.label_tensi = gtk_label_new("");


    gtk_container_add(GTK_WINDOW(fenetre),GTK_BOX(vbox));
    gtk_widget_show_all(fenetre);
    gtk_signal_connect(G_OBJECT(fenetre),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main();


}
