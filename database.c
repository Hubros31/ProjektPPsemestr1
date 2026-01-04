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
    int rolabohatera;
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
                if(rolabohatera==0)
                {
                    printf("Wybrana rola: BOHATER\n");
                    dodaj->dane.rola=(Rola)rolabohatera;
                    while(getchar()!='\n');
                }
                if(rolabohatera==1)
                {
                    printf("Wybrana rola: ZLOCZYNCA\n");
                    dodaj->dane.rola=(Rola)rolabohatera;
                    while(getchar()!='\n');

                }
                if(rolabohatera==2)
                {
                    printf("Wybrana rola: ANTYBOHATER\n");
                    dodaj->dane.rola=(Rola)rolabohatera;
                    while(getchar()!='\n');
                }
                if(rolabohatera==3)
                {
                    printf("Wybrana rola: NEUTRALNY\n");
                    dodaj->dane.rola=(Rola)rolabohatera;
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
    printf("\nPoziom zagrozenia: (0-10)");
    int pozzag;
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
                dodaj->dane.poziom_zagrozenia=pozzag;
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
    int statuss;
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
                    dodaj->dane.status=(Status)statuss;
                    while(getchar()!='\n');
                }
                if(statuss==1)
                {
                    printf("Wybrany status: USPIONY\n");
                    dodaj->dane.status=(Status)statuss;
                    while(getchar()!='\n');

                }
                if(statuss==2)
                {
                    printf("Wybrany status: W MISJI\n");
                    dodaj->dane.status=(Status)statuss;
                    while(getchar()!='\n');
                }
                if(statuss==3)
                {
                    printf("Wybrany status: RANNY\n");
                    dodaj->dane.status=(Status)statuss;
                    while(getchar()!='\n');
                }
                if(statuss==4)
                {
                    printf("Wybrany status: UWIEZIONY\n");
                    dodaj->dane.status=(Status)statuss;
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
    dodaj->next=*headd;
    *headd=dodaj;
    printf("\nPostac dodana pomyslnie!\n");
    printf("--------------------------------\n\n");
}
void wyswietlanie_calosci(Lista *headd)
{
    if (headd==NULL)
    {
        printf("\nPusta baza danych!\n\n");
        return;
    }
    while(headd!=NULL)
    {
        wyswietl_jedna_postac(headd->dane);
        headd=headd->next;
    }
}

void edycja_postaci(Lista *headd, char *username)
{
    Lista *wyszukaj=headd;
    int flaga=0;

    while(wyszukaj!=NULL)
    {
        if (strcmp(wyszukaj->dane.pseudonim, username)==0)
        {
            flaga=1;
            break;
        }
        wyszukaj=wyszukaj->next;
    }

    if (flaga==0)
    {
        printf("\nNie znaleziono postaci o podanym pseudonimie!\n\n");
        return;
    }
    while(1)
    {
        printf("--- EDYCJA DANYCH: %s ---\n",wyszukaj->dane.pseudonim);
        printf("1. Zmien Role\n");
        printf("2. Zmien Moc\n");
        printf("3. Zmien Poziom Zagrozenia\n");
        printf("4. Zmien Dzielnice\n");
        printf("5. Zmien Status\n");
        printf("0. Anuluj edytowanie\n");
        printf("Wybierz opcje: ");

        int wybor;
        int wynikk=scanf("%d", &wybor);
        if(wynikk!=1)
        {
            printf("Podaj liczbe z zakresu od 0 do 5! Sprobuj ponownie!\n");
            while(getchar()!='\n');
            continue;
        }
        else
        {
            if(wybor==0)
            {
                printf("Edycje anulowano pomyslnie!.\n\n");
                break;
            }
            if(wybor==1)
            {
                printf("Nowa rola (0-Bohater 1-Zloczynca 2-Antybohater 3-Neutralny): ");
                int nowa_rola;
                if(scanf("%d",&nowa_rola)==1 && nowa_rola>=0 && nowa_rola<=3)
                {
                    wyszukaj->dane.rola=(Rola)nowa_rola;
                    printf("Edycje roli zakonczono pomyslnie!\n\n");
                }
                else
                {
                    printf("Podaj wartosc z zakresu od 0 do 3! Edycja niewprowadzona!.\n");
                }
                break;
            }
            if(wybor==2)
            {
                printf("Nowa moc: ");
                scanf(" %99[^\n]",wyszukaj->dane.moc);
                printf("Edycje mocy zakonczono pomyslnie!\n\n");
                break;
            }
            if(wybor==3)
            {
                printf("Nowy poziom zagrozenia (0-10): ");
                int nowy_poziom;
                scanf("%d",&nowy_poziom);
                if (nowy_poziom>=0 && nowy_poziom<=10)
                {
                    wyszukaj->dane.poziom_zagrozenia=nowy_poziom;
                    printf("Edycje poziomu zagrozenia zakonczono pomyslnie!\n\n");
                }
                else
                {
                    printf("Podaj wartosc z zakresu od 0 do 10! Edycja niewprowadzona!\n\n");
                }
                break;
            }
            if(wybor==4)
            {
                printf("Nowa dzielnica: ");
                scanf(" %149[^\n]",wyszukaj->dane.dzielnica_dzialania);
                printf("Edycje dzielnicy zakonczono pomyslnie!\n\n");
                break;
            }
            if(wybor==5)
            {
                printf("Nowy status (0-Aktywny 1-Uspiony 2-W misji 3-Ranny 4-Uwieziony): ");
                int nowy_status;
                scanf("%d",&nowy_status);
                if (nowy_status>=0 && nowy_status<=4)
                {
                    wyszukaj->dane.status=(Status)nowy_status;
                    printf("Edycje statusu zakonczono pomyslnie!\n\n");
                }
                else
                {
                    printf("Podaj wartosc z zakresu od 0 do 4! Edycja niewprowadzona!\n\n");
                }
                break;
            }
        }
    }
}
void usuniecie_postaci(Lista **headd, char *username)
{
    if (*headd==NULL)
    {
        printf("\nPusta baza danych!\n\n");
        return;
    }

    Lista *obecny=*headd;
    Lista *poprzedni=NULL;

    while(obecny!=NULL)
    {
        if (strcmp(obecny->dane.pseudonim, username) == 0)
        {
            if (obecny->dane.status==UWIEZIONY) //nasz warunek
            {
                printf("\nNie mozna usunac postaci, poniewaz postac %s jest uwieziona!\n\n",username);
                return;
            }
            if (poprzedni == NULL)
            {
                *headd=obecny->next; //pierwszy element listy
            }
            else
            {
                poprzedni->next=obecny->next; //w srodku lub na koncu
            }
            free(obecny);
            printf("\nPostac usunieta pomyslnie!\n\n");
            return;
        }
        poprzedni=obecny;
        obecny=obecny->next;
    }
    printf("\nNie znaleziono postaci o podanym pseudonimie!\n\n");
}

// FUNKCJE DO WYSZUKIWANIA

void wyszukiwanie_nazwa(Lista *headd,char *nick)
{
    if (headd==NULL)
    {
        printf("\nPusta baza danych!\n\n");
        return;
    }

    printf("\n--- WYNIKI WYSZUKIWANIA DLA: '%s' ---\n",nick);
    char *wszystkierole[]= {"Bohater","Zloczynca","Antybohater","Neutralny"};
    char *statusy[]= {"Aktywny","Uspiony","W misji","Ranny","Uwieziony"};

    int czyznaleziono=0;

    while(headd!=NULL)
    {
        if (strcmp(headd->dane.pseudonim,nick)==0)
        {
            int i=headd->dane.rola;
            int i2=headd->dane.status;

            printf("ZNALEZIONO!\n");
            printf("--------------------------------------------------\n");
            printf("Pseudonim: %s\n",headd->dane.pseudonim);
            printf("Rola:      %s\n",wszystkierole[i]);
            printf("Moc:       %s\n",headd->dane.moc);
            printf("Poziom:    %d\n",headd->dane.poziom_zagrozenia);
            printf("Dzielnica: %s\n",headd->dane.dzielnica_dzialania);
            printf("Status:    %s\n",statusy[i2]);
            printf("--------------------------------------------------\n");

            czyznaleziono=1;
        }
        headd=headd->next; //rozwazamy opcje gdy mamy wiecej osob o tym samym pseudonimie
    }

    if (czyznaleziono==0)
    {
        printf("Nie znaleziono postaci o takim pseudonimie!\n\n");
    }
}

void wyszukiwanie_poziom_zagrozenia(Lista *headd, int poziom)
{
    if (headd==NULL)
    {
        printf("\nPusta baza danych!\n\n");
        return;
    }

    printf("\n--- POSTACIE Z PODANYM POZIOMEM ZAGROZENIA: %d ---\n",poziom);

    char *wszystkierole[]= {"Bohater","Zloczynca","Antybohater","Neutralny"};
    char *statusy[]= {"Aktywny","Uspiony","W misji","Ranny","Uwieziony"};

    int czyznaleziono=0;

    while (headd!=NULL)
    {
        if (headd->dane.poziom_zagrozenia==poziom)
        {
            int i=headd->dane.rola;
            int i2=headd->dane.status;

            printf("ZNALEZIONO!\n");
            printf("--------------------------------------------------\n");
            printf("Pseudonim: %s\n",headd->dane.pseudonim);
            printf("Rola:      %s\n",wszystkierole[i]);
            printf("Moc:       %s\n",headd->dane.moc);
            printf("Poziom:    %d\n",headd->dane.poziom_zagrozenia);
            printf("Dzielnica: %s\n",headd->dane.dzielnica_dzialania);
            printf("Status:    %s\n",statusy[i2]);
            printf("--------------------------------------------------\n");

            czyznaleziono=1;
        }
        headd=headd->next;
    }

    if (czyznaleziono==0)
    {
        printf("Brak postaci o poziomie zagrozenia %d!\n\n", poziom);
    }
}

// FUNKCJE SORTOWANIA (sortowanie babelkowe)

void sortowanie_alfabetycznie(Lista **headd)
{
    if (*headd == NULL || (*headd)->next == NULL) //0 lub 1 element
    {
        printf("\nZa malo danych do sortowania.\n\n");
        return;
    }

    Lista *i;
    Lista *j;

    for (i=*headd;i!=NULL;i=i->next)
    {
        for (j=*headd;j->next!=NULL;j=j->next)
        {
            if (strcmp(j->dane.pseudonim,j->next->dane.pseudonim)>0)
            {
                Postac pom=j->dane;
                j->dane=j->next->dane;
                j->next->dane=pom;
            }
        }
    }
    printf("\nBaza posortowana alfabetycznie!\n\n");
}

void sortowanie_po_zagrozeniu(Lista **headd)
{
    if (*headd==NULL || (*headd)->next==NULL)
    {
        printf("\nZa malo danych do sortowania.\n\n");
        return;
    }

    Lista *i;
    Lista *j;

    for (i=*headd; i!=NULL; i=i->next)
    {
        for (j = *headd; j->next!=NULL; j=j->next)
        {
            if (j->dane.poziom_zagrozenia>j->next->dane.poziom_zagrozenia)
            {
                Postac pom=j->dane;
                j->dane=j->next->dane;
                j->next->dane=pom;
            }
        }
    }

    printf("\nBaza posortowana wedlug poziomu zagrozenia!\n\n");
}
void zapisz_do_pliku(Lista *headd,char *plikk)
{
    printf("\nW budowie.\n");
}

void wczytaj_z_pliku(Lista **headd,char *plikk)
{
    printf("\nw budowie.\n");
}

void wyczysc_pamiec(Lista **headd)
{
    printf("\nw budowie\n");
}
