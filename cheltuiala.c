#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cheltuiala.h"


Cheltuiala* creeazaCh(int zi, float suma, const char* tip) {

    Cheltuiala* chtl = malloc(sizeof(Cheltuiala));

    int nrT = (int)strlen(tip) + 1;

    chtl->tip = malloc(nrT * sizeof (char));

    strcpy(chtl->tip, tip);

    chtl->zi = zi;

    chtl->suma = suma;

    return chtl;

}

int validareCh(Cheltuiala cht) {

    if ( cht.zi <= 0 || cht.zi > 31  )

        return 0;

    if ( cht.suma <= 0 )

        return 0;

    if ( strcmp(cht.tip, "") == 0 )

        return 0;

    return 1;
}

void eliminaCh(Cheltuiala *cht) {

    cht -> zi = 0;

    cht -> suma = 0;

    free(cht->tip);

    cht -> tip = NULL;
}