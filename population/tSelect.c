#include <stdio.h>
#include <stdlib.h>
#include "tSelect.h"
#include "../structures.h"
#include "../people/insert_tail.h"
Population *tSelect(Population *pop, int selection) {

    // On définie une population Selected qui correspond aux individus qui vont être sélectionnés
    // pour completer le reste de la population initiale
    Population *selected = malloc(sizeof(Population));
    selected->first = NULL;
    selected->popSize = 0;

    ElemPop *elem = malloc(sizeof(ElemPop));
    elem = pop->first;

    for(int i = 0; i < selection; i++) {
        // On récupère les individus sélectionnés
        insert_tail_pop(selected,elem->people);

        elem = elem->next;
    }

    ElemPop *forReplace = malloc(sizeof(ElemPop));
    forReplace = selected->first;

    // elem correspond au premier element qui doit être remplacé, puis on continu tant qu'il est pas NULL
    while(elem != NULL) {
        if(forReplace == NULL) {
            // Si on arrive à la fin de la liste chainée de la population sélectionné, on recommence au début
            forReplace = selected->first;
        }

        // On tronque au fur et à mesure
        elem->people = forReplace->people;

        elem = elem->next;
        forReplace = forReplace->next;
    }

    return pop;
}
