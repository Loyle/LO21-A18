#include <stdlib.h>
#include <stdio.h>
#include "../people/calculate_quality.h"
#include "../structures.h"

Population *quicksort(Population *pop) {
    // Les conditions d'arrêts
    if(pop->popSize == 1 || pop == NULL || pop->first == NULL) {
        return pop;
    }

    // Dans un premier temps, faut diviser pop en deux, et mettre les plus grand dans l'une, les plus petit dans l'autre
    int popSize = pop->popSize;
    ElemPop *elem = pop->first;

    // On initialises les population: best => meilleurs qualités, worth => moins bonne qualités
    Population *best = malloc(sizeof(Population));
    Population *worth = malloc(sizeof(Population));

    // On définits leurs paramètres
    best->popSize = 0;
    best->first = NULL;
    worth->popSize = 0;
    worth->first = NULL;


    while(elem != NULL) {
        // Pour chaque element de la population, on compare avec tous les autres elements
        int supp = 0;
        ElemPop *compare = pop->first;
        while(compare != NULL) {
            float quality1 = elem->people->quality;
            float quality2 = compare->people->quality;

            if(quality1 >= quality2) {
                // On compare les qualités afin de compter combien d'individus a une qualité inférieure ou égale à l'individu traitée
                supp++;
            }
            compare = compare->next;
        }

        // En fonction de supp, on place l'individu soit dans les meilleurs, soit dans les moins bon
        // Si meilleur est déjà plein (ça taille fait la moitiée de la taille de la population initiale) on le place dans les moins bon
        if(supp >= popSize / 2 && best->popSize <= popSize / 2) {

            // Cette individu a une meilleur qualité que la motié des invididus
            best = insert_tail_pop(best,elem->people);
        }
        else {
            // Cette individu a une moins bonne qualité que la motié des invididus
            worth = insert_tail_pop(worth,elem->people);
        }

        elem = elem->next;
    }

    if(best->popSize == 0) {
        // Si on a la pop best qui est vide, alors on retourne que la population worth
        return worth;
    }
    else if(worth->popSize == 0) {
        // Sinon si on a la pop worth qui est vide, alors on retourne que la population best
        return best;
    }
    else {
        // Sinon on retourne la fusion des populations best et worth triées par récurrence
        return merge_pop(quicksort(best),quicksort(worth));
    }

}
