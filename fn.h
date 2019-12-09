#ifndef AGENT_H
#define AGENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct user
{
char login[20];
char password[20];
int role;
};

int verifier(struct user a);

struct date_naissance
{
    int jour;
    char mois[100];
    int annee;
};
typedef struct date_naissance Date;
 struct personne
{

char cin[20];
char nom[20];
char prenom[20];
Date d;
char adresse[10];
char sexe[20];

}; typedef struct personne personne;

void ajouter_personne(personne p);
void afficher_personne(GtkWidget *liste);
personne rechercher (char cin[20]);
void modifier_personne(personne p1);
int date_entier(char ch[100]);
int supprimer_personne(personne p,char cin[100]);
#endif

