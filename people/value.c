#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int calculate_value(Individu *people)
{
    int value = 0;
    ElemIndiv *actuel = malloc(sizeof(ElemIndiv));
    actuel = people->first;
    for(int i = people->longindiv; i > 0 ; i--)
    {
        // On calcul la valeur
        value = (actuel->bit) * (int)pow(2,i-1) + value;
        actuel = actuel->next;
    }

    return value;
}
