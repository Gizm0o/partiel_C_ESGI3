
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
    char *a_nom[256];
    float a_prix;
    char a_description[1024];
    Type a_type;
} Article;

Article *creer_Article()
{
    Article *art = (Article *)malloc(sizeof(Article));
    if (art == NULL)
    {
        printf("Erreur d'allocation de memoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez le nom de l'article: ");
    scanf("%255s", art->a_nom);
    printf("Entrez le prix de l'article: ");
    scanf("%f", &art->a_prix);
    printf("Entrez la description de l'article: ");
    scanf("%1023s", art->a_description);
    printf("Entrez le type de l'article: ");
    scanf("%d", &art->a_type);
    return art;
}

void afficher_Article(const Article *art)
{
    printf("Nom: %s, Prix: %f, Description: %s, Type: %d", art->a_nom, art->a_prix, art->a_description, art->a_type);
}

void modifier_Article(Article *art)
{
    printf("Entrez le nom de l'article: ");
    scanf("%255s", art->a_nom);
    printf("Entrez le prix de l'article: ");
    scanf("%f", &art->a_prix);
    printf("Entrez la description de l'article: ");
    scanf("%1023s", art->a_description);
    printf("Entrez le type de l'article: ");
    scanf("%d", &art->a_type);
}

void liberer_Article(Article **art)
{
    free(*art);
    *art = NULL;
}

void save_Article(const Article *art, FILE *fichier)
{
    fprintf(fichier, "%s %f %s %d", art->a_nom, art->a_prix, art->a_description, art->a_type);
}

void load_Article(Article *art, FILE *fichier)
{
    int type;
    fscanf(fichier, "%255s %f %1023s %d\n", art->a_nom, &art->a_prix, art->a_description, &type);
    art->a_type = (Type)type;
}

int main_Article()
{
    int nbArticleMax = 1;
    Article *tab_Article[nbArticleMax];

    for (int i = 0; i < nbArticleMax; i++)
    {
        tab_Article[i] = creer_Article();

        afficher_Article(tab_Article[i]);
        modifier_Article(tab_Article[i]);
        afficher_Article(tab_Article[i]);

        FILE *fichier = fopen("article.txt", "w");
        if (fichier == NULL)
        {
            printf("Erreur d'ouverture du fichier.\n");
            exit(EXIT_FAILURE);
        }

        save_Article(tab_Article[i], fichier);
        fclose(fichier);
    }

    for (int i = 0; i < nbArticleMax; ++i)
    {
        liberer_Article(&tab_Article[i]);
    }

    FILE *fichier = fopen("article.txt", "r");

    for (int i = 0; i < nbArticleMax; ++i)
    {
        tab_Article[i] = creer_Article();
        load_Article(tab_Article[i], fichier);
        afficher_Article(tab_Article[i]);
    }

    fclose(fichier);

    for (int i = 0; i < nbArticleMax; ++i)
    {
        liberer_Article(&tab_Article[i]);
    }

    return 0;
}
