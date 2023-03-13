#ifndef ARTICLE_H
#define ARTICLE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    DIVERS,
    VETEMENT,
    NOURRITURE,
    LIVRE
} Type;

typedef struct
{
    char a_nom[256];
    float a_prix;
    char a_description[1024];
    Type a_type;
} Article;

Article *creer_Article();
void afficher_Article(const Article *art);
void modifier_Article(Article *art);
void liberer_Article(Article **art);
void save_Article(const Article *art, FILE *fichier);
void load_Article(Article *art, FILE *fichier);

#endif // ARTICLE_H