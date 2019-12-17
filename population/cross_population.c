#include <stdio.h>
#include <stdlib.h>
#include "cross_population.h"
#include "getRandomPeople.h"
#include "../people/calculate_quality.h"
#include "../people/value.h"
#include "../structures.h"
#include "../people/display_people.h"

Population *cross_population(Population *pop, float pCroise)
{
    // On initialise les deux individus qui seront croisé
    Individu *P1 = malloc(sizeof(Individu));
    Individu *P2 = malloc(sizeof(Individu));

    // On crée la nouvelle population qui va être initialisé
    Population *newPop = malloc(sizeof(Population));
    newPop->popSize = 0;
    newPop->first = NULL;

    // Tant que la nouvelle population fait pas la taille de l'actuelle, on continu
    while(newPop->popSize < pop->popSize)
    {
        // On initialise l'individu qui sera le résultat du croisement de P1 et P2
        Individu *P3 = malloc(sizeof(Individu));
        P3->first = NULL;
        P3->longindiv = 0;

        // On sélectionne 2 individue aléatoirement
        P1 = getRandomPeople(pop);
        do
        {
            // On fait en sorte de pas selectionner deux fois le même individu
            P2 = getRandomPeople(pop);
        }
        while(P1 == P2);


        ElemIndiv *bitP1 = malloc(sizeof(ElemIndiv));
        ElemIndiv *bitP2 = malloc(sizeof(ElemIndiv));

        // On récupère le premier element de la liste chainée de P1 et P2
        bitP1 = P1->first;
        bitP2 = P2->first;


        // On croise les deux individue pour former un nouvel individu tant que on a pas parcouru tous les bits de l'individu
        while(bitP1 != NULL && bitP2 != NULL) {
            if(rand()%2 < pCroise) {
                // On prend bit de P1
                insert_tail_people(P3,bitP1->bit);
            }
            else {
                // On prend bit de P2
                insert_tail_people(P3,bitP2->bit);

            }

            // On passe aux bits suivants
            bitP1 = bitP1->next;
            bitP2 = bitP2->next;
        }



        // On complète les paramètres de P3
        P3->value = calculate_value(P3);
        P3->quality = calculate_quality(P3, P3->value);
        // On a crée le nouvel individu, on le rajoute à la nouvelle population
        insert_tail_pop(newPop,P3);

    }


    return newPop;
}
