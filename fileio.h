#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include "database.h"

// operacje na plikach
void zapisz_do_pliku(Lista *headd,char *plikk);
void wczytaj_z_pliku(Lista **headd,char *plikk);

#endif
