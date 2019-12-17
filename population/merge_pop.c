#include <stdlib.h>
#include <stdio.h>
#include "../people/calculate_quality.h"
#include "../people/insert_tail.h"
#include "merge_pop.h"

Population *merge_pop(Population *big, Population *small) {
    ElemPop *smallElem = small->first;


    // big = meilleur qualit�, small = moins bonne qualit�
    if(big == NULL) {
        //Si big est NULL, on le cr�e
        big = malloc(sizeof(Population));
        big->first = NULL;
        big->popSize = 0;
    }

    while(smallElem != NULL) {
        // On parcour la population de moins bonne qualit�
        // On ajoute chaque individu dans l'ordre � la suite de la population big
        // On conserve ainsi l'ordre du plus grand au plus petit
        big = insert_tail_pop(big,smallElem->people);

        smallElem = smallElem->next;
    }


    return big;
}
