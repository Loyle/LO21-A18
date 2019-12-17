#include <stdio.h>
#include <stdlib.h>
#include "getRandomPeople.h"
#include "../structures.h"

Individu *getRandomPeople(Population *pop) {

    ElemPop *elem = malloc(sizeof(ElemPop));
    elem = pop->first;

    // g�n�re un nombre al�atoire entre 0 et la taille de la population
    int random = rand()%pop->popSize;
    for(int i = 0; i < random; i++) {
        // r�cup�re l'individu correspondant � ce nombre al�atoire
        elem = elem->next;
    }

    return elem->people;
}
