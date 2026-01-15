#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "menu.h"

int main()
{
    Lista *baza_danych=NULL;
    dzialanie_na_menu(&baza_danych);
    wyczysc_pamiec(&baza_danych);

    return 0;
}

