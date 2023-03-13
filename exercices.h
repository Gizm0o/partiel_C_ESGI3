#ifndef MON_FICHIER_H
#define MON_FICHIER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mypow(int nb, int n);

double Suite(double x, unsigned N);

void Exercice1();

typedef double ElementTableau;

typedef ElementTableau *Tableau;

void permuter(ElementTableau *a, ElementTableau *b);

void permuter_Tableau(Tableau tab, unsigned size);

Tableau creer_Tableau(unsigned size);

void liberer_Tableau(Tableau *tab);

void afficher(const Tableau tab, unsigned size);

void Exercice2();

int mainExercices();

#endif