#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

Individu *insert_head_people(Individu *people, Bit value)
{
    if(people == NULL)
    {
        // Cas où people n'est pas définie, on retourne un people vierge
        people = malloc(sizeof(Individu));
        people->first = NULL;
        people->longindiv = 0;
    }
    else if(people->first == NULL)
    {
        // Cas où le premier élement n'est pas définie, on le rajoute
        ElemIndiv *element = malloc(sizeof(ElemIndiv));
        element->bit = value;
        element->next = NULL;
        people->first = element;
        people->longindiv = 1;
    }
    else
    {
        // Tous les autres cas, on ajoute au début de la liste
        ElemIndiv *element = malloc(sizeof(ElemIndiv));
        element->bit = value;
        element->next = people->first;
        people->first = element;
        people->longindiv = people->longindiv + 1;
    }
    return people;
}

Population *insert_head_pop(Population *pop, Individu *people)
{
    if(pop == NULL)
    {
        // Cas où pop n'est pas définie, on retourne une population vierge
        pop = malloc(sizeof(Individu));
        pop->first = NULL;
        pop->popSize = 0;
    }
    else if(pop->first == NULL)
    {
        // Cas où le premier élement n'est pas définie, on le rajoute
        ElemPop *element = malloc(sizeof(ElemPop));
        element->people = people;
        element->next = NULL;
        pop->first = element;
        pop->popSize = 1;
    }
    else
    {
        // Tous les autres cas, on ajoute au début de la liste
        ElemPop *element = malloc(sizeof(ElemPop));
        element->people = people;
        element->next = pop->first;
        pop->first = element;
        pop->popSize = pop->popSize + 1;
    }
    return pop;
}
