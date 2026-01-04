#include <stdio.h>
#include "report.h"

void wyswietl_jedna_postac(Postac p)
{
    char *wszystkierole[]={"Bohater","Zloczynca","Antybohater","Neutralny" };
    char *statusy[]={"Aktywny","Uspiony","W misji","Ranny","Uwieziony" };

    printf("\n\n----------------------------------------\n");
    printf("Pseudonim:           %s\n", p.pseudonim);
    printf("Rola:                %s\n", wszystkierole[p.rola]);
    printf("Moc:                 %s\n", p.moc);
    printf("Poziom zagrozenia:   %d\n", p.poziom_zagrozenia);
    printf("Dzielnica dzialania: %s\n", p.dzielnica_dzialania);
    printf("Status:              %s\n", statusy[p.status]);
    printf("----------------------------------------\n\n\n");
}
