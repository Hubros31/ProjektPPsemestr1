#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void zapisz_do_pliku(Lista *headd,char *plikk)
{
    FILE *fp=fopen(plikk, "w");
    if (fp==NULL)
    {
        printf("\nOtworzenie pliku %s nie powiodlo sie!\n",plikk);
        return;
    }
    Lista *obecny=headd;
    while(obecny!=NULL)
    {
        fprintf(fp,"%s\n",obecny->dane.pseudonim);
        fprintf(fp,"%d\n",obecny->dane.rola);
        fprintf(fp,"%s\n",obecny->dane.moc);
        fprintf(fp,"%d\n",obecny->dane.poziom_zagrozenia);
        fprintf(fp,"%s\n",obecny->dane.dzielnica_dzialania);
        fprintf(fp,"%d\n",obecny->dane.status);

        obecny=obecny->next;
    }

    fclose(fp);
    printf("\nZapis do pliku '%s' zakonczony pomyslnie!\n",plikk);
}

void wczytaj_z_pliku(Lista **headd,char *plikk)
{
    FILE *fp=fopen(plikk,"r");
    if (fp==NULL)
    {
        printf("\nPlik '%s' nie istnieje!\n",plikk);
        return;
    }
    if (*headd!=NULL)
    {
        wyczysc_pamiec(headd);
    }
    while(1)
    {
        Lista *nowy=(Lista*)malloc(sizeof(Lista));
        if(fscanf(fp," %[^\n]",nowy->dane.pseudonim)!=1)
        {
            free(nowy);
            break;
        }
        fscanf(fp,"%d",&nowy->dane.rola);
        fscanf(fp," %[^\n]",nowy->dane.moc);
        fscanf(fp,"%d", &nowy->dane.poziom_zagrozenia);
        fscanf(fp," %[^\n]",nowy->dane.dzielnica_dzialania);
        fscanf(fp,"%d",&nowy->dane.status);

        nowy->next=*headd;
        *headd=nowy;
    }
    fclose(fp);
    printf("\nWczytanie z pliku %s zakonczono pomyslnie!\n",plikk);
}
