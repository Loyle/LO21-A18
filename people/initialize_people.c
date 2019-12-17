#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../structures.h"
#include "insert_head.h"
#include "insert_tail.h"

Individu *initialize_people_ite(int longindiv)
{
    Individu *l = malloc(sizeof(Individu));
    Individu *p = malloc(sizeof(Individu));
    l->first = NULL;
    p->first = NULL;
    while (longindiv>0)
    {
        l->first = malloc(sizeof(ElemIndiv));
        l->longindiv = longindiv;
        l->first->bit = rand()%2;
        l->first->next = p->first;
        p->first = l->first;
        longindiv--;

    }
    return p;
}

Individu *initialize_people_rec(int longindiv) {
    if(longindiv == 0) {
        // Condition d'arrêt, on return une population vierge
        return insert_head_people(NULL,rand() % 2);
    }
    // On ajoute à chaque fois en récurrence à la suite de la liste chainée population
    return insert_tail_people(initialize_people_rec(longindiv - 1),rand() % 2);
}
