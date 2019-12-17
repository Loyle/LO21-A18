#include <stdio.h>
#include <stdlib.h>
#include "initialize_population.h"
#include "../people/value.h"
#include "../people/calculate_quality.h"
#include "../structures.h"


Population *initialize_population(int longIndiv, int popSize) {
    // On g�n�re le premier �l�ment
    Population *pop = malloc(sizeof(Population));
    pop->popSize = popSize;
    pop->first = malloc(sizeof(ElemPop));
    ElemPop *elem = pop->first;
    elem->people = initialize_people_rec(longIndiv);

    // On d�finit ses caract�ristiques
    elem->people->value = calculate_value(elem->people);
    elem->people->quality = calculate_quality(elem->people, elem->people->value);


    for(int i = 1; i < popSize; i++) {
        // On g�n�re le reste de la population jusqu'� la taille souhait�
        elem->next = malloc(sizeof(ElemPop));
        elem = elem->next;
        elem->people = initialize_people_rec(longIndiv);

        // On d�finit ses caract�ristiques
        elem->people->value = calculate_value(elem->people);
        elem->people->quality = calculate_quality(elem->people, elem->people->value);
    }

    return pop;
}
