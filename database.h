#ifndef DATABASE_H
#define DATABASE_H

#include "report.h"

typedef struct Lista
{
    Postac dane;
    struct Lista *next;
} Lista;

void dodawanie_nowej_postaci(Lista **poczatek);
void wyswietl_liste(Lista *poczatek);

#endif
