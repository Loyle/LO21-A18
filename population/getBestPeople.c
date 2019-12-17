#include <stdio.h>
#include <stdlib.h>
#include "getBestPeople.h"
#include "../structures.h"

Individu *getBestPeople(Population *pop) {
    ElemPop *best = malloc(sizeof(ElemPop));
    ElemPop *elem = malloc(sizeof(ElemPop));

    best = pop->first;
    elem = pop->first;

    // Tant que on a pas parcouru toute la population
    while(elem != NULL) {
        // Si on trouve un individu meilleur que celui d'avant (donc avec une qualité plus petite, on le stock dans Best
        if(elem->people->quality < best->people->quality) {
            best = elem;
        }

        elem = elem->next;
    }

    return best->people;
}
