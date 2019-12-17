#include <stdio.h>
#include <stdlib.h>
#include "../people/calculate_quality.h"
#include "../structures.h"

void display_population(Population *pop) {
    ElemPop *elem = malloc(sizeof(ElemPop));
    elem = pop->first;

    // Affiche rapidement une population
    while(elem != NULL) {
        printf("\n");
        display_people(elem->people);
        printf(" => Qualite : %f", elem->people->quality);
        elem = elem->next;
    }
}
