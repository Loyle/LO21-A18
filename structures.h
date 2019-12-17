#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED


typedef unsigned char Bit;

typedef struct ElemIndiv ElemIndiv;
struct ElemIndiv
{
    ElemIndiv *next;
    Bit bit;
};

typedef struct Individu Individu;
struct Individu
{
    ElemIndiv *first;
    int longindiv;
    int value;
    float quality;
};

typedef struct ElemPop ElemPop;
struct ElemPop
{
    ElemPop *next;
    Individu *people;
};
typedef struct Population Population;
struct Population {
    ElemPop *first;
    int popSize;
};

#endif // STRUCTURE_H_INCLUDED
