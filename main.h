#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
typedef struct{
    GtkWidget* fenetre;

    GtkWidget *entre_tens;
    GtkWidget *entre_intens;
    GtkWidget *entre_resist;

    GtkWidget *label_tensi;
    GtkWidget *label_intens;
    GtkWidget *label_resist;

}Data;

void calcul(GtkWidget * widget,Data* data);
void error(GtkWidget* fenetre,char* error);
#endif // MAIN_H_INCLUDED
