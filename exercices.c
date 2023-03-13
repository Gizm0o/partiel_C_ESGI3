#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mypow(int nb, int n)
{
    int i;
    int res = 1;
    for (i = 0; i < n; i++)
    {
        res = res * nb;
    }
    return res;
}

double Suite(double x, unsigned N)
{
    double res = x;
    int i;
    for (i = 1; i < N; i++)
    {
        res = res + mypow(-1, i) * mypow(x, 2 * i - 1) / mypow(i, 2 * i - 1);
    }
    return res;
}

void Exercice1()
{
    double x;
    unsigned N;
    printf("Entrez x: ");
    scanf("%lf", &x);
    printf("Entrez N: ");
    scanf("%u", &N);
    if (N > 50)
    {
        printf("Suite(%lf, %u) = %lf et atan(%lf) = %lf)", x, N, Suite(x, N), x, atan(x));
    }
    else
    {
        printf("N doit etre superieur a 50");
    }
}

typedef double ElementTableau;
typedef ElementTableau *Tableau;

void permuter(ElementTableau *a, ElementTableau *b)
{
    ElementTableau temp = *a;
    *a = *b;
    *b = temp;
}

void permuter_Tableau(Tableau tab, unsigned size)
{
    unsigned i;
    for (i = 0; i < size / 2; i++)
    {
        permuter(&tab[i], &tab[size - 1 - i]);
    }
}

Tableau creer_Tableau(unsigned size)
{
    Tableau tab = (Tableau)malloc(size * sizeof(ElementTableau));
    unsigned i;
    for (i = 0; i < size; i++)
    {
        tab[i] = rand() % 100;
    }
    return tab;
}

void liberer_Tableau(Tableau *tab)
{
    free(*tab);
    *tab = NULL;
}

void afficher(const Tableau tab, unsigned size)
{
    unsigned i;
    for (i = 0; i < size; i++)
    {
        printf("Tab[%u] = %lf", i, tab[i]);
    }
}

void Exercice2()
{
    unsigned size;
    printf("Entrez la taille du tableau: ");
    scanf("%u", &size);
    Tableau tab = creer_Tableau(size);
    afficher(tab, size);
    permuter_Tableau(tab, size);
    afficher(tab, size);
    liberer_Tableau(&tab);
}

int mainExercices()
{
    void Exercice1();
    void Exercice2();
    return 0;
}
