#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"

void dodawanie_postaci(Lista **headd)
{
    struct Lista *dodaj=malloc(sizeof(struct Lista));
    if (dodaj==NULL)
    {
        printf("Blad pamieci!\n");
        return;
    }
    printf("--- DODAWANIE NOWEJ POSTACI ---\n");
    printf("Pseudonim:");
    scanf(" %99[^\n]",dodaj->dane.pseudonim);
    while(getchar()!='\n');
    printf("\nRola: (0-Bohater 1-Zloczynca 2-Antybohater 3-Neutralny)");
    int rolabohatera
    while(1)
    {
        int wynikrola=scanf("%d",&rolabohatera);
        if(wynikrola==0)
        {
            while(getchar()!='\n');
            printf("Podaj liczbe z zakresu od 0 do 3! Sprobuj ponownie.\n");
            continue;
        }
        else
        {
            if(rolabohatera>=0 && rolabohatera<=3)
            {
                if(rolaboatera==0)
                {
                    printf("Wybrana rola: BOHATER\n");
                    dodaj->dane.rola;
                    while(getchar()!='\n');
                }
                if(rolaboatera==1)
                {
                    printf("Wybrana rola: ZLOCZYNCA\n");
                    dodaj->dane.rola;
                    while(getchar()!='\n');

                }
                if(rolaboatera==2)
                {
                    printf("Wybrana rola: ANTYBOHATER\n");
                    dodaj->dane.rola;
                    while(getchar()!='\n');
                }
                if(rolaboatera==3)
                {
                    printf("Wybrana rola: NEUTRALNY\n");
                    dodaj->dane.rola;
                    while(getchar()!='\n');
                }
                break;
            }
            else
            {
                while(getchar()!='\n');
                printf("Podaj liczbe z zakresu od 0 do 3! Sprobuj ponownie.\n");
                continue;
            }
        }
    }
    printf("\nMoc:");
    scanf(" %99[^\n]",dodaj->dane.moc);
    while(getchar()!='\n');
    printf("\nPoziom zagrozenia: (0-10)")
    int pozzag
    while(1)
    {
        int wynikpoziom=scanf("%d",&pozzag);
        if(wynikpoziom==0)
        {
            while(getchar()!='\n');
            printf("Podaj liczbe z zakresu od 0 do 10! Sprobuj ponownie.\n");
            continue;
        }
        else
        {
            if(pozzag>=0 && pozzag<=10)
            {
                printf("Wprowadzony poziom zagrozenia %d\n",pozzag);
                dodaj->dane.poziom_zagrozenia;
                while(getchar()!='\n');
                break;
            }
            else
            {
                while(getchar()!='\n');
                printf("Podaj liczbe z zakresu od 0 do 10! Sprobuj ponownie.\n");
                continue;
            }
        }
    }
    printf("\nDzielnica:");
    scanf(" %149[^\n]",dodaj->dane.dzielnica_dzialania);
    while(getchar()!='\n');
    printf("\nStatus: (0-Aktywny 1-Uspiony 2-W misji 3-Ranny 4-Uwieziony)");
    int statuss
    while(1)
    {
        int wynikstatus=scanf("%d",&statuss);
        if(wynikstatus==0)
        {
            while(getchar()!='\n');
            printf("Podaj liczbe z zakresu od 0 do 4! Sprobuj ponownie.\n");
            continue;
        }
        else
        {
            if(statuss>=0 && statuss<=4)
            {
                if(statuss==0)
                {
                    printf("Wybrany status: AKTYWNY\n");
                    dodaj->dane.status;
                    while(getchar()!='\n');
                }
                if(statuss==1)
                {
                    printf("Wybrany status: USPIONY\n");
                    dodaj->dane.status;
                    while(getchar()!='\n');

                }
                if(statuss==2)
                {
                    printf("Wybrany status: W MISJI\n");
                    dodaj->dane.status;
                    while(getchar()!='\n');
                }
                if(statuss==3)
                {
                    printf("Wybrany status: RANNY\n");
                    dodaj->dane.status;
                    while(getchar()!='\n');
                }
                if(statuss==4)
                {
                    printf("Wybrany status: UWIEZIONY\n");
                    dodaj->dane.status;
                    while(getchar()!='\n');
                }
                break;
            }
            else
            {
                while(getchar()!='\n');
                printf("Podaj liczbe z zakresu od 0 do 4! Sprobuj ponownie.\n");
                continue;
            }
        }
    }
    dodaj->next *headd;
    *headd=dodaj;
    printf("\nPostac dodana pomyslnie!\n");
}
void wyswietlanie_calosci(Lista *headd)
{
    if (headd==NULL)
    {
        printf("\nPusta baza danych!\n");
        return;
    }
    char *wszystkierole[]={"Bohater","Zloczynca","Antybohater","Neutralny" };
    char *statusy[]={"Aktywny","Uspiony","W misji","Ranny","Uwieziony" };
    while(headd!=NULL)
    {
        int i=headd->dane.rola;
        int i2=headd->dane.status;
        printf("--------------------\n");
        printf("Pseudonim: %s\n",headd->dane.pseudonim);
        printf("Rola: %s\n",wszystkierole[i]);
        printf("Moc: %s\n",headd->dane.moc);
        printf("Poziom zagrozenia: %d\n",headd->dane.poziom_zagrozenia);
        printf("Dzielnica dzialania: %s\n",headd->dane.dzielnica_dzialania);
        printf("Status: %s\n",statusy[i2]);
        printf("--------------------\n");
        headd=headd->next;
    }
}
