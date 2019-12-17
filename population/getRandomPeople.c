#include <stdio.h>
#include <stdlib.h>
#include "getRandomPeople.h"
#include "../structures.h"

Individu *getRandomPeople(Population *pop) {

    ElemPop *elem = malloc(sizeof(ElemPop));
    elem = pop->first;

    // génère un nombre aléatoire entre 0 et la taille de la population
    int random = rand()%pop->popSize;
    for(int i = 0; i < random; i++) {
        // récupère l'individu correspondant à ce nombre aléatoire
        elem = elem->next;
    }

    return elem->people;
}
