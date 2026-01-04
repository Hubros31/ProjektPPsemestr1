#include <stdio.h>
#include <stdlib.h>

#include "database.h"


int menu()
{
    int wybor;
    while(1)
    {
        printf("--- Centralny System Ewidencji Metropolii Nova Solaris ---\n");
        printf("--- MENU ---\n");
        printf("1. Dodaj nowa postac\n");
        printf("2. Edytuj wybrana postac\n");
        printf("3. Usun wybrana postac\n");
        printf("4. Wyszukaj po nazwie bohatera\n");
        printf("5. Wyszukaj po poziomie zagrozenia\n");
        printf("6. Posortuj dane alfabetycznie wedlug nazwy postaci\n");
        printf("7. Posortuj dane rosnaco wedlug poziomu zagrozenia postaci (od najmniejszego poziomu do najwiekszego)\n");
        printf("8. Wczytaj z pliku\n");
        printf("9. Wczytaj do pliku\n");
        printf("10. Wyswietl cala baze\n");
        printf("0. Zakoncz dzialanie programu\n");
        printf("------------\n");
        printf("WYBIERZ OPCJE:");
        if(scanf("%d",&wybor)!=1)
        {
            printf("\nNie wybrano poprawnie opcji! Sprobuj ponownie!\n\n");
            while(getchar()!='\n');
            continue;
        }
        if(wybor>=0 && wybor<=10)
            break;
        printf("\nNie wybrano poprawnej opcji! Sprobuj ponownie!\n\n");
    }
    return wybor;
}
void dzialanie_na_menu(Lista **opcje)
{
    char nazwa[100];
    char plikk[100];
    int poz;


    while(1)
    {
        int opcja=menu();
        if(opcja==1)
        {
            while(getchar()!='\n');
            dodawanie_postaci(opcje);
        }
        if(opcja==2)
        {
            printf("Podaj pseudonim w ktorym edytowane beda dane: ");
            scanf(" %99[^\n]",nazwa);
            while(getchar()!='\n');
            edycja_postaci(*opcje,nazwa);
        }
        if(opcja==3)
        {
            printf("Podaj pseudonim do usuniecia: ");
            scanf(" %99[^\n]",nazwa);
            while(getchar()!='\n');
            usuniecie_postaci(opcje,nazwa);
        }
        if(opcja==4)
        {
            printf("Podaj szukany pseudonim: ");
            scanf(" %99[^\n]",nazwa);
            while(getchar()!='\n');
            wyszukiwanie_nazwa(*opcje,nazwa);
        }
        if(opcja==5)
        {
            printf("Podaj szukany poziom zagrozenia (0-10): ");
            int wynik2=scanf("%d",&poz);
            if(wynik2!=1)
            {
                while(getchar()!='\n');
                printf("Podaj liczbe z zakresu od 0 do 10!\n");
            }
            else
            {
                while(getchar()!='\n');
                wyszukiwanie_poziom_zagrozenia(*opcje,poz);
            }
        }
        if(opcja==6)
        {
            while(getchar()!='\n');
            sortowanie_alfabetycznie(opcje);
        }
        if(opcja==7)
        {
            while(getchar()!='\n');
            sortowanie_po_zagrozeniu(opcje);
        }
        if(opcja==8)
        {
            while(getchar()!='\n');
            printf("Podaj nazwe pliku: ");
            scanf("%99s", plikk);
            zapisz_do_pliku(*opcje,plikk);
        }
        if(opcja==9)
        {
            while(getchar()!='\n');
            printf("Podaj nazwe pliku: ");
            scanf("%99s", plikk);
            wczytaj_z_pliku(opcje,plikk);
        }
        if(opcja==10)
        {
            while(getchar()!='\n');
            wyswietlanie_calosci(*opcje);
        }
        if(opcja==0)
        {
            while(getchar()!='\n');
            printf("Do zobaczenia uzytkowniku!");
            break;
        }

    }
}

