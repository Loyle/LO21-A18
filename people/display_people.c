#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void display_people(Individu *individu)
{
    ElemIndiv *elem = malloc(sizeof(ElemIndiv));
    elem = individu->first;
    while(elem != NULL)
    {
        // On affiche chaque bits de l'individu
        printf("%u",elem->bit);
        elem = elem->next;
    }
}
