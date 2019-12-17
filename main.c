#include <stdio.h>
#include <stdlib.h>
#include "people/initialize_people.h"
#include "structures.h"
#include "people/calculate_quality.h"
#include "people/value.h"
#include "people/display_people.h"
#include "population/initialize_population.h"
#include "population/quicksort.h"
#include "population/tSelect.h"
#include "population/cross_population.h"
#include "population/getBestPeople.h"

int main()
{
    // On initialise 1 seul fois srand(time(NULL))
    srand(time(NULL));

    int restart;
    do
    {
        // On vide la console
        system("cls");

        int answer;
        do
        {
            printf("Bienvenu dans le generateur de population.\n- Tapez 1 pour le mode aleatoire\n- Tapez 2 pour le mode custom !\n");
            scanf("%i", &answer);
        }
        while(answer != 1 && answer != 2);


        int longindiv;
        float pCroise;
        int taillePop;
        int select;
        int nGen;

        do
        {
            printf("\nSaisir la longueur des individus : ");
            scanf("%i", &longindiv);
        }
        while(longindiv < 0 || longindiv > 100);

        do
        {
            printf("\nSaisir le taux de croisement : ");
            scanf("%f", &pCroise);
        }
        while(pCroise <= 0 || pCroise >= 1);

        if(answer == 1)
        {
            // Mode aléatoire
            taillePop = rand() %(200 - 20) + 20;
            select = ((rand()%(90 - 10) + 10) * taillePop) / 100;
            nGen = rand() %(200 - 20) + 20;
        }
        else
        {
            // Mode customisé


            do
            {
                printf("\nSaisir la taille de la population : ");
                scanf("%i", &taillePop);
            }
            while(taillePop < 20 || taillePop > 200);


            do
            {
                printf("\nSaisir taux de selection (en pourcentage) : ");
                scanf("%i", &select);
            }
            while(select < 10 || select > 90);
            select = (select * taillePop)/ 100;

            do
            {
                printf("\nSaisir le nombre de generation : ");
                scanf("%i", &nGen);
            }
            while(nGen < 20 || nGen > 200);
        }

        // On vide la console
        system("cls");

        // On affiche les informations
        printf("Taille individus : %i", longindiv);
        printf("\nTaille population : %i", taillePop);
        printf("\nProbabilite de croisement : %f", pCroise);
        printf("\nNombre de selection (en nombre): %i", select);
        printf("\nNombre de generation : %i", nGen);

        // On initialise la population
        Population *pop = initialize_population(longindiv,taillePop);

        // Nombre de génération
        for(int i = 0; i < nGen; i++)
        {
            pop = cross_population(pop,pCroise);
            pop = quicksort(pop);
            pop = tSelect(pop,select);
        }

        // On recherche et affiche le meilleur individu
        Individu *best = malloc(sizeof(Individu));
        best = getBestPeople(pop);
        printf("\n\nLe meilleur individu est : ");
        display_people(best);
        printf("\nDe valeur %i", best->value);
        printf("\nDe qualite %f\n", best->quality);

        do
        {
            printf("\n\nTapez 1 pour recommencer ou 0 pour arreter\n");
            scanf("%i", &restart);
        }
        while(restart != 0 && restart != 1);

    }
    while(restart == 1);
    return 0;
}
