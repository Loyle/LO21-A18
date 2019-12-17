#include <stdio.h>
#include <stdlib.h>
#include "tSelect.h"
#include "../structures.h"
#include "../people/insert_tail.h"
Population *tSelect(Population *pop, int selection) {

    // On d�finie une population Selected qui correspond aux individus qui vont �tre s�lectionn�s
    // pour completer le reste de la population initiale
    Population *selected = malloc(sizeof(Population));
    selected->first = NULL;
    selected->popSize = 0;

    ElemPop *elem = malloc(sizeof(ElemPop));
    elem = pop->first;

    for(int i = 0; i < selection; i++) {
        // On r�cup�re les individus s�lectionn�s
        insert_tail_pop(selected,elem->people);

        elem = elem->next;
    }

    ElemPop *forReplace = malloc(sizeof(ElemPop));
    forReplace = selected->first;

    // elem correspond au premier element qui doit �tre remplac�, puis on continu tant qu'il est pas NULL
    while(elem != NULL) {
        if(forReplace == NULL) {
            // Si on arrive � la fin de la liste chain�e de la population s�lectionn�, on recommence au d�but
            forReplace = selected->first;
        }

        // On tronque au fur et � mesure
        elem->people = forReplace->people;

        elem = elem->next;
        forReplace = forReplace->next;
    }

    return pop;
}
