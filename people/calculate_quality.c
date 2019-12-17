#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "calculate_quality.h"
#include "../structures.h"

#define valueA -1
#define valueB 1

//#define valueA 0.1
//#define valueB 5

//#define valueA -3.14159265359
//#define valueB 3.14159265359

float calculate_quality(Individu *people, int value)
{
    // Pour éviter tout problème, on vérifie que people n'est pas NULL
    if(people != NULL)
    {
        // Calcul de la qualité en fonction de valueA et valueB
        double X = (value / pow(2,people->longindiv)) * (float)(valueB - valueA) + valueA;
        float quality = -1 * (X * X); //f1
        //float quality = -log(X); //f2
        //float quality = (float)-cos(X); //f3

        return quality;
    }
    else
    {
        return 0;
    }
}
