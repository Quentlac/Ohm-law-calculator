#include <stdlib.h>
#include <gtk/gtk.h>
#include "main.h"

int main (int argc, char *argv[])
{
    Data data;
    gtk_init(&argc,&argv);


    data.fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(data.fenetre),"Calculateur loi ohm");
    gtk_window_set_default_size(GTK_WINDOW(data.fenetre),600,100);


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
    gtk_signal_connect(G_OBJECT(bouton),"clicked",G_CALLBACK(calcul),(gpointer) &data);

    //ajout d'une reponse(U)
    data.label_tensi = gtk_label_new("<big>Tension: 0 v</big>");
    gtk_label_set_use_markup(GTK_LABEL(data.label_tensi),TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),data.label_tensi,FALSE,FALSE,0);

    //ajout d'une reponse(I)
    data.label_intens = gtk_label_new("<big>Intensité: 0 A</big>");
    gtk_label_set_use_markup(GTK_LABEL(data.label_intens),TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),data.label_intens,FALSE,FALSE,0);

    //ajout d'une reponse(R)
    data.label_resist = gtk_label_new("<big>Résistance: 0 ohms</big>");
    gtk_label_set_use_markup(GTK_LABEL(data.label_resist),TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),data.label_resist,FALSE,FALSE,0);


    gtk_container_add(GTK_WINDOW(data.fenetre),GTK_BOX(vbox));
    gtk_widget_show_all(data.fenetre);
    gtk_signal_connect(G_OBJECT(data.fenetre),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main();


}

void calcul(GtkWidget * widget,Data* data){

    char* U_entry = gtk_entry_get_text(GTK_ENTRY(data->entre_tens));
    char* I_entry = gtk_entry_get_text(GTK_ENTRY(data->entre_intens));
    char* R_entry = gtk_entry_get_text(GTK_ENTRY(data->entre_resist));

    //test des entre:
    int valid = 0;
    if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_tens)) != 0){
        valid++;

    }
    if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_intens)) != 0){
        valid++;

    }
    if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_resist)) != 0){
        valid++;

    }
    if(valid < 2)error(data->fenetre,"Il manque des donnees!");
    else{
        if(valid > 2)error(data->fenetre,"Il y a des donnees en trop!");
        else{
            char affiche_U[100] = "<big>Tension: ";
            char affiche_I[100] = "<big>Intensite: ";
            char affiche_R[100] = "<big>Resistance: ";

            char charU[100];
            char charI[100];
            char charR[100];

            if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_tens)) == 0){
                double I = atoi(I_entry);
                double R = atoi(R_entry);
                double U = R*I;

                sprintf(charU,"%f",U);
                sprintf(charI,"%f",I);
                sprintf(charR,"%f",R);
            }
            if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_intens)) == 0){
                double R = atoi(R_entry);
                double U = atoi(U_entry);
                double I = U/R;

                sprintf(charU,"%f",U);
                sprintf(charI,"%f",I);
                sprintf(charR,"%f",R);
            }
            if(gtk_entry_get_text_length (GTK_ENTRY(data->entre_resist)) == 0){
                double I = atoi(I_entry);
                double U = atoi(U_entry);
                double R = U/I;


                sprintf(charU,"%f",U);
                sprintf(charI,"%f",I);
                sprintf(charR,"%f",R);
            }
            strcat(affiche_U,charU);
            strcat(affiche_U," V</big>");

            strcat(affiche_I,charI);
            strcat(affiche_I," A</big>");

            strcat(affiche_R,charR);
            strcat(affiche_R," ohms</big>");

            gtk_label_set_text(GTK_LABEL(data->label_tensi),affiche_U);
            gtk_label_set_use_markup(GTK_LABEL(data->label_tensi),TRUE);

            gtk_label_set_text(GTK_LABEL(data->label_intens),affiche_I);
            gtk_label_set_use_markup(GTK_LABEL(data->label_intens),TRUE);

            gtk_label_set_text(GTK_LABEL(data->label_resist),affiche_R);
            gtk_label_set_use_markup(GTK_LABEL(data->label_resist),TRUE);
        }
    }


}

void error(GtkWidget* fenetre,char* error){
    GtkWidget * dialog = NULL;
    dialog = gtk_message_dialog_new(GTK_WINDOW(fenetre),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,error);
    gtk_window_set_position(GTK_WINDOW(dialog),GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
