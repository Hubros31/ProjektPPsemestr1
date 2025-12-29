#ifndef REPORT_H
#define REPORT_H

typedef enum
{
    BOHATER, ZLOCZYNCA, ANTYBOHATER, NEUTRALNY
} Rola;

typedef enum
{
    AKTYWNY, USPIONY, WMISJI, RANNY, UWIEZIONY
} Status;

typedef struct
{
    char pseudonim[100];
    Rola rola;
    char moc[100];
    int poziom_zagrozenia;
    char dzielnica_dzialania[150];
    Status status;
} Postac;

void wyswietl_jedna_postac(Postac p);

#endif
