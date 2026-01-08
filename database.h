#ifndef DATABASE_H
#define DATABASE_H

#include "report.h"

typedef struct Lista
{
    Postac dane;
    struct Lista *next;
} Lista;

//kolekcja obiektow
void dodawanie_postaci(Lista **headd); //dodawanie nowej postaci

void wyswietlanie_calosci(Lista *headd); //wyœwietlanie calej bazy

void edycja_postaci(Lista *headd,char *username); //edytowanie postaci

void usuniecie_postaci(Lista **headd,char *username); //usuniecie postaci (nie moze sie usunac gdy postac jest uwieziona!)

//wyszukiwanie i filtrowanie
void wyszukiwanie_nazwa(Lista *headd,char *nick); //wyszukiwanie po nazwie bohatera
void wyszukiwanie_poziom_zagrozenia(Lista *headd,int poziom); //wyszukiwanie po poziomie zagrozenia

//sortowanie
void sortowanie_alfabetycznie(Lista **headd); // wedlug nazwy bohtaera
void sortowanie_po_zagrozeniu(Lista **headd); // wedlug poziomu zagro¿enia

//czyszczenie
void wyczysc_pamiec(Lista **headd);
#endif
